# IEC-61850 Server with HTTP API

IEC-61850 сервер с FileService для трёх Logical Devices, управляемый через HTTP API. Работает в Docker контейнере с автодеплоем.

## Особенности

- ✅ IEC-61850 сервер с FileService для 3 Logical Devices
- ✅ HTTP API для управления файлами (.NET 8.0)
- ✅ Docker контейнер с автоматическим запуском
- ✅ Swagger документация API
- ✅ Автодеплой на сервер при пуше в master

## Быстрый старт

```bash
# Сборка
docker build -f Dockerfile.final -t iec61850-server .

# Запуск
docker run -d --name iec61850-server -p 8080:80 -p 8102:8102 iec61850-server

# Проверка
curl http://localhost:8080/health
```

## API Endpoints

- **Base URL:** `http://localhost:8080`
- **Swagger UI:** `http://localhost:8080/swagger`

### Основные endpoints:
- `GET /health` - Проверка здоровья API
- `GET /api/server/status` - Статус IEC-61850 сервера
- `GET /api/devices` - Список Logical Devices
- `POST /api/files/{deviceName}` - Загрузка файла
- `GET /api/files/{deviceName}` - Список файлов в устройстве
- `GET /api/files/{deviceName}/{fileName}` - Скачать файл
- `DELETE /api/files/{deviceName}/{fileName}` - Удалить файл
- `POST /api/server/rebuild` - Пересборка сервера из CID

## Logical Devices

1. **Measurements** (LD1) - измерительные данные
2. **Protection** (LD2) - события защиты
3. **Control** (LD3) - статус управления

## IEC-61850 Подключение

- **Хост:** `localhost` или IP сервера
- **Порт:** `8102`

## Примеры использования

### Загрузка файла:
```bash
echo '{"temp": 25.5}' | curl -X POST -F "file=@-;" http://localhost:8080/api/files/Measurements
```

### Получение списка файлов:
```bash
curl http://localhost:8080/api/files/Measurements
```

### Скачивание файла:
```bash
curl -O http://localhost:8080/api/files/Measurements/sensor.json
```

## Автодеплой

При пуше в ветку `master` автоматически разворачивается на сервере myServer.

Подробнее: [DEPLOYMENT.md](DEPLOYMENT.md)

## Документация

- [Полная документация](WORKING_SETUP.md) - рабочая конфигурация
- [Быстрый старт](QUICK_START.md) - команды для быстрого старта
- [Настройка деплоя](DEPLOYMENT.md) - инструкции по автодеплою

## Структура проекта

```
proxy_gate_90_2/
├── FullApi/              # HTTP API (.NET 8.0)
├── Dockerfile.final      # Docker контейнер
├── MultiLD.cid           # Конфигурация IED с 3 LD
├── libiec61850_full/     # Исходники библиотеки
├── .github/workflows/    # GitHub Actions для деплоя
└── scripts/              # Скрипты настройки
```

## Лицензия

MIT
# Test deployment
