# Быстрый старт - IEC-61850 Server

## Запуск контейнера

```bash
# Сборка (если ещё не собран)
docker build -f Dockerfile.final -t iec61850-server .

# Запуск
docker run -d --name iec61850-server -p 8080:80 -p 8102:8102 iec61850-server

# Проверка
curl http://localhost:8080/health
```

## Подключение IEC-61850 клиента

**Параметры:**
- Хост: `192.168.1.122` или `localhost`
- Порт: `8102`

**Тестовый клиент:**
```bash
cd TestFileServiceApp
dotnet run -- localhost 8102
```

## Загрузка файлов через API

```bash
# Measurements
echo '{"temp": 25.5}' | curl -X POST -F "file=@-;" http://localhost:8080/api/files/Measurements

# Protection
echo 'Event log' | curl -X POST -F "file=@-;" http://localhost:8080/api/files/Protection

# Control
echo 'Status: OK' | curl -X POST -F "file=@-;" http://localhost:8080/api/files/Control
```

## Полезные команды

```bash
# Статус сервера
curl http://localhost:8080/api/server/status

# Список файлов в устройстве
curl http://localhost:8080/api/files/Measurements

# Логи контейнера
docker logs iec61850-server

# Остановка
docker stop iec61850-server

# Перезапуск
docker restart iec61850-server
```

## Swagger UI

Откройте в браузере: http://localhost:8080/swagger

## Доступные Logical Devices

1. **Measurements** (LD1) - измерения
2. **Protection** (LD2) - защита
3. **Control** (LD3) - управление
