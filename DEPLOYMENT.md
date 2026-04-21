# Настройка автодеплоя на Ubuntu сервер

Автоматический деплой на сервер **myServer** при пуше в ветку `master`.

## Архитектура

- **CI/CD:** GitHub Actions
- **Dockerfile:** Dockerfile.final (компилирует libiec61850 в контейнере)
- **API:** FullApi (.NET 8.0)
- **Порты:** 8080 (Web API), 8102 (IEC-61850)

## Шаг 1: Подготовка сервера myServer

Подключитесь к серверу и выполните:

```bash
# Обновите систему
sudo apt update && sudo apt upgrade -y

# Установите Docker
curl -fsSL https://get.docker.com -o get-docker.sh
sudo sh get-docker.sh

# Добавьте пользователя в группу docker
sudo usermod -aG docker artem

# Установите Docker Compose
sudo apt install docker-compose-plugin -y

# Примените изменения группы (выйдите и войдите снова)
newgrp docker

# Создайте директорию для приложения
sudo mkdir -p /opt/iec61850-server
sudo chown artem:artem /opt/iec61850-server
```

## Шаг 2: Настройка SSH ключей

### На Windows (вашей локальной машине):

```powershell
# В PowerShell
ssh-keygen -t ed25519 -C "github-deploy" -f ~/.ssh/github_deploy_key
```

### Скопируйте публичный ключ на сервер:

```powershell
type $env:USERPROFILE\.ssh\github_deploy_key.pub | ssh artem@myServer "cat >> ~/.ssh/authorized_keys"
```

### Проверьте подключение:

```powershell
ssh -i ~/.ssh/github_deploy_key artem@myServer "docker --version"
```

## Шаг 3: Настройка GitHub Secrets

Откройте ваш репозиторий на GitHub: **Settings → Secrets and variables → Actions → New repository secret**

Добавьте секреты:

| Имя | Значение | Описание |
|-----|----------|----------|
| `SSH_PRIVATE_KEY` | (приватный ключ) | Содержимое файла `github_deploy_key` (БЕЗ .pub) |
| `SSH_PORT` | `22` | Порт SSH (или ваш кастомный) |
| `SERVER_HOST` | `myServer` | IP или hostname сервера |
| `SERVER_USER` | `artem` | Имя пользователя на сервере |

### Как добавить SSH_PRIVATE_KEY:

1. Откройте файл `C:\Users\<ваш_пользователь>\.ssh\github_deploy_key` (без .pub!)
2. Скопируйте **ВСЁ** содержимое включая строки `-----BEGIN` и `-----END`
3. Вставьте в поле значения секрета в GitHub

## Шаг 4: Деплой

### Запушьте код в GitHub:

```bash
git add .
git commit -m "Setup auto-deployment"
git push origin master
```

### Следите за выполнением:

1. Откройте репозиторий на GitHub
2. Перейдите во вкладку **Actions**
3. Выберите последний workflow "Deploy to Ubuntu Server"
4. Следите за логами выполнения

## Проверка деплоя

### На сервере:

```bash
ssh artem@myServer
docker ps                    # Проверьте что контейнер запущен
docker logs iec61850-server  # Посмотрите логи
```

### Проверьте API:

```bash
# Health check
curl http://myServer:8080/health

# Список устройств
curl http://myServer:8080/api/devices

# Swagger UI
# Откройте в браузере: http://myServer:8080/swagger
```

## Решение проблем

### Permission denied (publickey)
- Убедитесь, что публичный ключ добавлен в `~/.ssh/authorized_keys` на сервере
- Проверьте права: `chmod 600 ~/.ssh/github_deploy_key`

### Port 8080/8102 already in use
```bash
sudo lsof -i :8080  # Найдите процесс
# Или измените порты в .github/workflows/deploy.yml
```

### Container not starting
```bash
docker logs iec61850-server  # Посмотрите логи
docker ps -a                 # Проверьте статус
```

### Docker command not found
```bash
# Убедитесь что пользователь в группе docker
groups artem
# Перезайдите в систему после добавления в группу
```

## Управление

### Просмотр логов:
```bash
ssh artem@myServer "docker logs -f iec61850-server"
```

### Перезапуск:
```bash
ssh artem@myServer "docker restart iec61850-server"
```

### Остановка:
```bash
ssh artem@myServer "docker stop iec61850-server"
```

### Обновление вручную:
```bash
ssh artem@myServer
cd /opt/iec61850-server
# Github Actions автоматически задеплоит новую версию при следующем пуше
```

## Firewall (если нужен)

```bash
sudo ufw allow 22/tcp    # SSH
sudo ufw allow 8080/tcp  # Web API
sudo ufw allow 8102/tcp  # IEC-61850 TCP
sudo ufw allow 8102/udp  # IEC-61850 UDP
sudo ufw enable
```

## Структура на сервере

```
myServer:/opt/iec61850-server/
└── (Docker контейнер с volume для filestore)
```

Docker volume `iec61850-filestore` хранит загруженные файлы.

## Дополнительная информация

Полная документация проекта в [WORKING_SETUP.md](WORKING_SETUP.md)
