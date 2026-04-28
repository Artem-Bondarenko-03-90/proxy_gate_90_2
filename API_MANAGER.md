# IEC 61850 LD Manager API

REST API для динамического управления логическими устройствами IEC 61850 сервера.

## Архитектура

```
┌─────────────────┐     ┌──────────────────┐
│  api-manager    │────▶│  Docker Daemon   │
│  (FastAPI)      │     │                  │
└─────────────────┘     └──────────────────┘
         │                         │
         │ mounts                 │ manages
         ▼                         ▼
┌─────────────────┐     ┌──────────────────┐
│  Project files  │     │ iec61850-server  │
│  - CID file     │────▶│  (IEC 61850)     │
│  - Model files  │     │                  │
│  - Dockerfile   │     └──────────────────┘
└─────────────────┘
```

## Запуск

```bash
# Запустить оба контейнера
docker-compose up -d

# Проверить статус
docker-compose ps

# Логи API менеджера
docker logs -f iec61850-api-manager

# Логи сервера
docker logs -f iec61850-fileserver
```

## API Эндпоинты

### GET / - Корень
Информация о сервисе

**Response:**
```json
{
  "service": "IEC 61850 LD Manager API",
  "version": "1.0.0",
  "status": "running"
}
```

### GET /api/status - Статус сервера
Получить статус IEC 61850 сервера и список логических устройств

**Response:**
```json
{
  "container_running": true,
  "logical_devices": ["GenericIO", "GenericIO2"],
  "port": 102
}
```

### GET /api/ld - Список LD
Получить список всех логических устройств

**Response:**
```json
{
  "logical_devices": ["GenericIO", "GenericIO2"],
  "count": 2
}
```

### POST /api/ld - Добавить LD
Добавить новое логическое устройство

**Request:**
```json
{
  "name": "GenericIO3",
  "template": "GenericIO"
}
```

**Response:**
```json
{
  "name": "GenericIO3",
  "status": "pending",
  "message": "Adding logical device 'GenericIO3' in background"
}
```

**Процесс:**
1. Модификация `multi-ld-model.cid` (добавление нового LD)
2. Перегенерация `static_model.c/h` через `genmodel.jar`
3. Создание файловой директории `vmd-filestore/GenericIO3/`
4. Пересборка Docker образа
5. Перезапуск контейнера `iec61850-fileserver`

**Время выполнения:** ~3-5 минут (зависит от системы)

### GET /api/ld/{ld_name} - Информация о LD
Получить информацию о конкретном логическом устройстве

**Response:**
```json
{
  "name": "GenericIO",
  "exists": true,
  "filestore_exists": true
}
```

### DELETE /api/ld/{ld_name} - Удалить LD
Удалить логическое устройство (пока не реализовано)

## Примеры использования

### cURL

```bash
# Проверить статус
curl http://localhost:8000/api/status

# Список всех LD
curl http://localhost:8000/api/ld

# Добавить новое LD
curl -X POST http://localhost:8000/api/ld \
  -H "Content-Type: application/json" \
  -d '{"name": "GenericIO3", "template": "GenericIO"}'

# Информация о LD
curl http://localhost:8000/api/ld/GenericIO3
```

### Python

```python
import requests

# Базовый URL
BASE_URL = "http://localhost:8000"

# Добавить новое LD
response = requests.post(
    f"{BASE_URL}/api/ld",
    json={
        "name": "GenericIO3",
        "template": "GenericIO"
    }
)
print(response.json())

# Проверить статус
response = requests.get(f"{BASE_URL}/api/status")
print(response.json())
```

### PowerShell

```powershell
# Добавить новое LD
$body = @{
    name = "GenericIO3"
    template = "GenericIO"
} | ConvertTo-Json

Invoke-RestMethod -Uri "http://localhost:8000/api/ld" `
    -Method POST `
    -ContentType "application/json" `
    -Body $body

# Проверить статус
Invoke-RestMethod -Uri "http://localhost:8000/api/status"
```

## Мониторинг прогресса

Операция добавления LD выполняется в фоновом режиме. Для отслеживания:

```bash
# Логи API менеджера
docker logs -f iec61850-api-manager

# Смотреть логи в реальном времени
docker-compose logs -f api-manager
```

## Ограничения

- **Защищенные LD:** `GenericIO` и `GenericIO2` нельзя удалить
- **Длина имени:** 1-64 символа
- **Время выполнения:** 3-5 минут на добавление LD
- **Совместимость:** Нельзя удалять LD (пока не реализовано)

## Архитектурные решения

### Почему отдельный контейнер?

1. **Изоляция:** API менеджер изолирован от сервера
2. **Доступ к Docker:** Имеет доступ к Docker Daemon
3. **Отказоустойчивость:** Сервер можно перезапускать независимо от API
4. **Безопасность:** API можно остановить без остановки сервера

### Монтирование Docker socket

```yaml
volumes:
  - /var/run/docker.sock:/var/run/docker.sock
```

Позволяет API менеджеру:
- Управлять контейнерами (стоп/старт/рестарт)
- Пересобирать образы
- Мониторить статус контейнеров

### Монтирование проекта

```yaml
volumes:
  - .:/work
```

Позволяет API менеджеру:
- Модифицировать CID файлы
- Генерировать модели
- Обновлять Dockerfile
- Создавать файловые структуры

## Troubleshooting

### Контейнер api-manager не запускается

```bash
# Проверить логи
docker logs iec61850-api-manager

# Проверить Docker socket
docker exec iec61850-api-manager ls -la /var/run/docker.sock
```

### Ошибка при добавлении LD

```bash
# Проверить права доступа к файлам
ls -la multi-ld-model.cid
ls -la genmodel.jar

# Проверить логи
docker logs iec61850-api-manager --tail 50
```

### Контейнер сервера не перезапускается

```bash
# Проверить статус
docker ps -a | grep iec61850

# Перезапустить вручную
docker restart iec61850-fileserver
```

## Следующие улучшения

1. **WebSocket** для real-time обновлений статуса
2. **Удаление LD** с полной очисткой
3. **Валидация CID** перед сборкой
4. **Rollback** при ошибках
5. **Аутентификация** для API
6. **Логирование операций** в базу данных
7. **UI** для удобного управления
