#!/bin/bash
# Скрипт для первоначальной настройки сервера myServer
# Запустите этот скрипт на сервере: bash setup-server.sh

set -e

echo "=== Начинаю настройку сервера для деплоя ==="

# Проверка root прав
if [ "$EUID" -ne 0 ]; then
    echo "Пожалуйста, запустите скрипт с sudo"
    exit 1
fi

# Обновление системы
echo "1. Обновление системы..."
apt update && apt upgrade -y

# Установка Docker
echo "2. Установка Docker..."
if ! command -v docker &> /dev/null; then
    curl -fsSL https://get.docker.com -o get-docker.sh
    sh get-docker.sh
    rm get-docker.sh
    usermod -aG docker artem
    echo "Docker установлен"
else
    echo "Docker уже установлен"
fi

# Установка Docker Compose
echo "3. Установка Docker Compose..."
apt install docker-compose-plugin -y

# Создание директории для приложения
echo "4. Создание директории приложения..."
mkdir -p /opt/iec61850-server
chown artem:artem /opt/iec61850-server

# Настройка firewall (опционально)
echo "5. Настройка firewall..."
if command -v ufw &> /dev/null; then
    ufw allow 22/tcp    # SSH
    ufw allow 8080/tcp  # Web API
    ufw allow 8102/tcp  # IEC-61850 TCP
    ufw allow 8102/udp  # IEC-61850 UDP
    echo "Firewall настроен"
else
    echo "UFW не установлен, пропускаем настройку firewall"
fi

# Проверка установки
echo "=== Проверка установки ==="
echo "Docker version:"
docker --version
echo "Docker Compose version:"
docker compose version

echo ""
echo "=== Настройка завершена! ==="
echo "Теперь:"
echo "1. Выйдите из системы: exit"
echo "2. Войдите снова: ssh artem@myServer"
echo "3. Перейдите в директорию: cd /opt/iec61850-server"
echo "4. Настройте SSH ключи для GitHub Actions (см. SETUP_DEPLOY.md)"
