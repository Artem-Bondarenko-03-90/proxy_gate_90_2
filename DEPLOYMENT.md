# Деплой на сервер

## ⚠️ Важно: Локальный vs Публичный сервер

**GitHub Actions НЕ работает с локальными IP адресами** (например, `192.168.1.x`).

Если ваш сервер имеет локальный IP - используйте **локальный скрипт деплоя**.
Если у вас публичный IP или домен - можете использовать GitHub Actions.

---

## Локальный деплой (для локальных IP)

### Автоматический деплой с локальной машины

#### Вариант 1: PowerShell (Windows)

```powershell
# Настройте переменные (опционально)
$env:SERVER_HOST="192.168.1.10"
$env:SERVER_USER="root"
$env:SERVER_PORT="22"

# Запустите деплой
.\deploy-to-server.ps1
```

#### Вариант 2: Bash (Linux/Mac/WSL)

```bash
# Сделайте скрипт исполняемым
chmod +x deploy-to-server.sh

# Настройте переменные (опционально)
export SERVER_HOST=192.168.1.10
export SERVER_USER=root
export SERVER_PORT=22

# Запустите деплой
./deploy-to-server.sh
```

### Конфигурация локального деплоя

| Переменная | По умолчанию | Описание |
|------------|--------------|----------|
| `SERVER_HOST` | `192.168.1.10` | IP адрес сервера |
| `SERVER_USER` | `root` | Пользователь на сервере |
| `SERVER_PORT` | `22` | SSH порт |

### Что делает локальный скрипт:

1. ✅ Компилирует приложение (.NET)
2. ✅ Собирает Docker образ
3. ✅ Копирует образ на сервер через SCP
4. ✅ Останавливает старый контейнер
5. ✅ Запускает новый контейнер
6. ✅ Проверяет здоровье сервиса

### Ручной деплой (если автоматический не работает)

#### На локальной машине:

```bash
# 1. Соберите приложение
dotnet publish FullApi/FullApi.csproj -c Release -o publish-full

# 2. Соберите Docker образ
docker build --no-cache -f Dockerfile.final -t iec61850-server:latest .

# 3. Сохраните образ
docker save iec61850-server:latest | gzip > iec61850-server.tar.gz

# 4. Скопируйте на сервер
scp -P 22 iec61850-server.tar.gz root@192.168.1.10:/tmp/
```

#### На сервере:

```bash
# 5. Загрузите образ
docker load < /tmp/iec61850-server.tar.gz

# 6. Остановите старый контейнер
docker stop iec61850-server 2>/dev/null || true
docker rm iec61850-server 2>/dev/null || true

# 7. Запустите новый контейнер
docker run -d \
  --name iec61850-server \
  --restart unless-stopped \
  -p 8080:80 \
  -p 8102:8102 \
  -v iec61850-filestore:/app/libiec61850_full/build/examples/server_example_files/vmd-filestore \
  iec61850-server:latest

# 8. Очистите временный файл
rm /tmp/iec61850-server.tar.gz

# 9. Проверьте статус
docker ps | grep iec61850-server
```

---

## Деплой через GitHub Actions (для публичных IP)

> **Используйте этот метод только если у сервера публичный IP адрес!**

### Шаг 1: Подготовка сервера

```bash
# Установите Docker
curl -fsSL https://get.docker.com -o get-docker.sh
sudo sh get-docker.sh

# Добавьте пользователя в группу docker
sudo usermod -aG docker $USER

# Создайте директорию для приложения
sudo mkdir -p /opt/iec61850-server
```

### Шаг 2: Настройка GitHub Secrets

Откройте: **Settings → Secrets and variables → Actions → New repository secret**

Добавьте секреты:

| Имя | Значение | Описание |
|-----|----------|----------|
| `SERVER_HOST` | `ваш_домен.com` или `1.2.3.4` | Публичный IP или домен сервера |
| `SERVER_USER` | `root` или `ubuntu` | Пользователь на сервере |
| `SERVER_PASSWORD` | `ваш_пароль` | Пароль пользователя (или SSH ключ) |
| `SSH_PORT` | `22` | Порт SSH |

### Шаг 3: Деплой

```bash
git add .
git commit -m "Deploy"
git push origin master
```

Следите за выполнением во вкладке **Actions** на GitHub.

---

## Подготовка сервера (любой метод)

На сервере выполните:

```bash
# Обновите систему
sudo apt update && sudo apt upgrade -y

# Установите Docker
curl -fsSL https://get.docker.com -o get-docker.sh
sudo sh get-docker.sh

# Добавьте пользователя в группу docker
sudo usermod -aG docker $USER

# Примените изменения группы (выйдите и войдите снова)
newgrp docker

# Создайте директорию для приложения
sudo mkdir -p /opt/iec61850-server

# Откройте порты в firewall (если нужен)
sudo ufw allow 22/tcp    # SSH
sudo ufw allow 8080/tcp  # Web API
sudo ufw allow 8102/tcp  # IEC-61850 TCP
sudo ufw allow 8102/udp  # IEC-61850 UDP
sudo ufw enable
```

---

## Проверка деплоя

### Проверьте работу контейнера:

```bash
# На сервере
docker ps                    # Проверьте что контейнер запущен
docker logs iec61850-server  # Посмотрите логи
```

### Проверьте API:

```bash
# Health check
curl http://192.168.1.10:8080/health

# Статус сервера
curl http://192.168.1.10:8080/api/server/status

# Swagger UI
# Откройте в браузере: http://192.168.1.10:8080/swagger
```

---

## Решение проблем

### Permission denied (publickey)

**Решение 1:** Используйте пароль вместо SSH ключа

Создайте файл `~/.ssh/config`:
```
Host 192.168.1.10
    User root
    PreferredAuthentications password
```

**Решение 2:** Добавьте SSH ключ на сервер

```bash
# На локальной машине
cat ~/.ssh/id_rsa.pub | ssh root@192.168.1.10 "cat >> ~/.ssh/authorized_keys"
```

### Connection refused

**Решение:** Проверьте, что SSH сервер работает:
```bash
# На сервере
sudo systemctl status ssh
sudo systemctl start ssh
```

### Docker command not found

**Решение:** Установите Docker:
```bash
curl -fsSL https://get.docker.com -o get-docker.sh
sudo sh get-docker.sh
```

### Port 8080/8102 already in use

```bash
# Найдите процесс
sudo lsof -i :8080

# Или остановите конфликтующий контейнер
docker stop <container_name>
```

### Container not starting

```bash
docker logs iec61850-server  # Посмотрите логи
docker ps -a                 # Проверьте статус
```

---

## Управление сервисом

### Просмотр логов:
```bash
ssh root@192.168.1.10 "docker logs -f iec61850-server"
```

### Перезапуск:
```bash
ssh root@192.168.1.10 "docker restart iec61850-server"
```

### Остановка:
```bash
ssh root@192.168.1.10 "docker stop iec61850-server"
```

### Удаление:
```bash
ssh root@192.168.1.10 "docker rm -f iec61850-server"
```

---

## Доступ к сервису

После успешного деплоя:

- **Web API:** http://192.168.1.10:8080
- **Swagger UI:** http://192.168.1.10:8080/swagger
- **IEC-61850:** 192.168.1.10:8102

---

## Структура на сервере

```
server:/opt/iec61850-server/
└── (Docker контейнер с volume для filestore)
```

Docker volume `iec61850-filestore` хранит загруженные файлы.

---

## Дополнительная информация

Полная документация проекта в [WORKING_SETUP.md](WORKING_SETUP.md)
