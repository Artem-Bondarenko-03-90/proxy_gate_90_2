# Рабочая конфигурация IEC-61850 Server с Docker и HTTP API

**Дата:** 2025-04-21
**Статус:** ✅ Полностью работает

## Обзор

Решение предоставляет IEC-61850 сервер с FileService для трёх Logical Devices, управляемый через HTTP API. Весь стек работает в Docker контейнере.

## Компоненты

### 1. IEC-61850 Server
- **Библиотека:** libiec61850 (скомпилирована из исходников в Linux)
- **Конфигурация:** Статическая модель из `MultiLD.cid`
- **Порт:** 8102
- **Logical Devices:**
  - `Measurements` (LD1) - измерительные данные
  - `Protection` (LD2) - события защиты
  - `Control` (LD3) - статус управления

### 2. HTTP API (FullApi)
- **Фреймворк:** .NET 8.0 Minimal API с Swagger
- **Порт:** 8080
- **Файл:** `FullApi/Program.cs`

### 3. Docker контейнер
- **Имя:** iec61850-server
- **Dockerfile:** `Dockerfile.final` (многоступенчатая сборка)
- **Проброс портов:** 8080:80 (API), 8102:8102 (IEC-61850)

## Важные пути в контейнере

```
/app/
├── libiec61850_full/
│   ├── build/
│   │   └── examples/
│   │       └── server_example_files/
│   │           ├── server_example_files       # IEC-61850 сервер (Linux binary)
│   │           └── vmd-filestore/             # Хранилище файлов
│   │               ├── Measurements/
│   │               ├── Protection/
│   │               └── Control/
│   ├── examples/
│   │   └── server_example_files/
│   │       ├── static_model.c                  # Сгенерированная модель
│   │       └── static_model.h
│   └── tools/
│       └── model_generator/
│           └── genmodel.jar                    # Генератор модели
└── publish/
    └── FullApi.dll                             # HTTP API
```

## HTTP API Endpoints

### Base URL: `http://localhost:8080`

### Health & Status
- `GET /health` - Проверка здоровья API
- `GET /api/server/status` - Статус IEC-61850 сервера
- `GET /api/devices` - Список Logical Devices

### File Management
- `GET /api/files/{deviceName}` - Список файлов в устройстве
- `POST /api/files/{deviceName}` - Загрузка файла
- `GET /api/files/{deviceName}/{fileName}` - Скачивание файла
- `DELETE /api/files/{deviceName}/{fileName}` - Удаление файла

### Server Control
- `POST /api/server/start?port=8102` - Запуск сервера
- `POST /api/server/stop` - Остановка сервера
- `POST /api/server/rebuild` - Пересборка сервера из CID файла

### Swagger UI
- `http://localhost:8080/swagger` - Интерактивная документация API

## Примеры использования HTTP API

### Загрузка файла
```bash
curl -X POST -F "file=@sensor.json" \
  http://localhost:8080/api/files/Measurements
```

### Получение списка файлов
```bash
curl http://localhost:8080/api/files/Measurements
```

### Скачивание файла
```bash
curl -O http://localhost:8080/api/files/Measurements/sensor.json
```

### Удаление файла
```bash
curl -X DELETE http://localhost:8080/api/files/Measurements/sensor.json
```

## IEC-61850 Подключение

### Параметры подключения
- **Хост:** `192.168.1.122` (из локальной сети) или `localhost` (локально)
- **Порт:** `8102`
- **TLS:** Отключён

### Logical Devices и имена файлов
Имена файлов в FileService включают префикс устройства:
- `Measurements/temperature.json`
- `Protection/events.log`
- `Control/status.txt`

### Пример клиента
```csharp
// См. TestFileServiceApp/Program.cs
IedConnection connection = IedConnection.Create();
connection.Connect("localhost", 8102);

// Чтение директории
var fileNames = FileService.GetFileDirectory(connection, "Measurements");

// Получение файла
var fileData = FileService.GetFile(connection, "Measurements/sensor.json");

// Отправка файла
FileService.SetFile(connection, "Measurements/new.json", fileData);
```

## Динамическая перекомпиляция

### Через HTTP API
```bash
curl -X POST \
  -F "cidFile=@MultiLD.cid" \
  -F "iedName=MultiLD" \
  -F "accessPoint=accessPoint1" \
  -F "port=8102" \
  http://localhost:8080/api/server/rebuild
```

### Через shell скрипт
```bash
./upload-cid.sh MultiLD.cid MultiLD accessPoint1
```

Процесс:
1. Загрузка CID файла
2. Генерация статической модели (genmodel.jar)
3. Компиляция сервера (cmake + make)
4. Перезапуск сервера

## Docker команды

### Сборка контейнера
```bash
docker build -f Dockerfile.final -t iec61850-server .
```

### Запуск контейнера
```bash
docker run -d --name iec61850-server \
  -p 8080:80 \
  -p 8102:8102 \
  iec61850-server
```

### Проверка логов
```bash
docker logs iec61850-server
docker logs -f iec61850-server  # follow
```

### Остановка и удаление
```bash
docker stop iec61850-server
docker rm iec61850-server
```

### Вход в контейнер
```bash
docker exec -it iec61850-server bash
```

## Конфигурация MultiLD.cid

Файл `MultiLD.cid` описывает три Logical Device с FileService:

```xml
<IED name="MultiLD">
  <AccessPoint name="accessPoint1">
    <Server>
      <Authentication none="true"/>
      <FileHandling/>
    </Server>
    <LDevice inst="LD1" lnType="LLN0"> <!-- Measurements -->
      <LN0 lnClass="LLN0" inst="" lnType="LLN0"/>
      <LogicalNode name="Measurements"/>
    </LDevice>
    <LDevice inst="LD2" lnType="LLN0"> <!-- Protection -->
      <LN0 lnClass="LLN0" inst="" lnType="LLN0"/>
      <LogicalNode name="Protection"/>
    </LDevice>
    <LDevice inst="LD3" lnType="LLN0"> <!-- Control -->
      <LN0 lnClass="LLN0" inst="" lnType="LLN0"/>
      <LogicalNode name="Control"/>
    </LDevice>
  </AccessPoint>
</IED>
```

## Known Issues & Решения

### 1. Anti-forgery middleware для IFormFile
**Проблема:** IFormFile требует anti-forgery middleware
**Решение:** `.DisableAntiforgery()` для file upload endpoints

### 2. Пути к файлам Windows vs Linux
**Проблема:** FullApi использовал `/Debug/vmd-filestore`, а Linux сервер - `/vmd-filestore`
**Решение:** Изменить `FileStoreDir` в Program.cs:
```csharp
const string FileStoreDir = ServerDir + "/vmd-filestore"; // Без /Debug
```

### 3. Dockerignore исключал необходимые файлы
**Проблема:** `**/*.cmake` и `**/build/` были исключены
**Решение:** Убрать эти исключения из .dockerignore для Dockerfile.final

### 4. Трекинг процесса сервера API
**Проблема:** API показывает статус "stopped", хотя сервер работает
**Причина:** Сервер запускается через Docker entrypoint, а не через API
**Варианты решения:**
- Оставить как есть (сервер работает, статус не критичен)
- Или запустить сервер через API POST /api/server/start

## Текущее состояние файлов

### Известные файлы в системе

**Measurements (LD1):**
- `sensor.json` (38 bytes) - тестовые данные датчика

**Protection (LD2):**
- `events.log` (16 bytes) - лог событий

**Control (LD3):**
- `status.txt` (21 bytes) - статус устройства

## Проверка работоспособности

### 1. Проверить API
```bash
curl http://localhost:8080/health
# Ожидаемый ответ: {"status":"healthy",...}
```

### 2. Проверить IEC-61850 сервер
```bash
cd TestFileServiceApp
dotnet run -- localhost 8102
# Ожидаемый вывод: список файлов во всех трёх устройствах
```

### 3. Проверить файлы через API
```bash
curl http://localhost:8080/api/files/Measurements
# Ожидаемый ответ: JSON с массивом файлов
```

### 4. Проверить файлы напрямую в контейнере
```bash
docker exec iec61850-server ls -la \
  /app/libiec61850_full/build/examples/server_example_files/vmd-filestore/
```

## Дальнейшее развитие

### Возможные улучшения

1. **Интеграция треда процесса сервера**
   - Использовать `Process.Start()` из API вместо entrypoint скрипта
   - Корректный статус в `/api/server/status`
   - Возможность остановки через API

2. **Поддержка конфигурации через CFG**
   - Исследовать возможность FileService с ConfigFileParser
   - Динамическое изменение модели без перекомпиляции

3. **Добавление TLS**
   - Настройка HTTPS для API
   - Поддержка secure IEC-61850 соединений

4. **Мониторинг и логирование**
   - Структурированные логи
   - Метрики производительности
   - Health checks для IEC-61850 сервера

5. **Тесты**
   - Unit тесты для API
   - Интеграционные тесты с IEC-61850 клиентом
   - Тесты на корректность файлов

## Ключевые файлы проекта

```
proxy_gate_90_2/
├── FullApi/Program.cs           # HTTP API endpoints
├── Dockerfile.final              # Docker контейнер (рабочий)
├── MultiLD.cid                   # Конфигурация IED с 3 LD
├── .dockerignore                 # Настроен для Dockerfile.final
├── upload-cid.sh                 # Скрипт динамической перекомпиляции
├── TestFileServiceApp/           # IEC-61850 клиент для тестов
├── publish-full/                 # Опубликованное API
└── libiec61850_full/             # Исходники библиотеки
```

## Резюме

Система полностью работоспособна:
- ✅ IEC-61850 сервер с FileService для 3 Logical Devices
- ✅ HTTP API для управления файлами
- ✅ Docker контейнер с автоматическим запуском
- ✅ Динамическая перекомпиляция из CID файлов
- ✅ Swagger документация
- ✅ Тестовый клиент для проверки

**Важно:** При изменении CID файла не забывайте пересобирать модель и перезапускать сервер через `/api/server/rebuild`.
