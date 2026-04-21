# Скрипт для генерации SSH ключей на Windows
# Запустите в PowerShell: .\scripts\setup-ssh.ps1

$ErrorActionPreference = "Stop"

Write-Host "=== Генерация SSH ключей для GitHub Actions ===" -ForegroundColor Green

# Создание директории .ssh если не существует
$sshDir = "$env:USERPROFILE\.ssh"
if (-not (Test-Path $sshDir)) {
    New-Item -ItemType Directory -Path $sshDir -Force
    Write-Host "Создана директория: $sshDir" -ForegroundColor Yellow
}

# Генерация ключа
$keyPath = "$sshDir\github_deploy_key"
if (Test-Path $keyPath) {
    $overwrite = Read-Host "Ключ $keyPath уже существует. Перезаписать? (y/n)"
    if ($overwrite -ne "y") {
        Write-Host "Генерация отменена" -ForegroundColor Red
        exit 0
    }
}

Write-Host "Генерация SSH ключа..." -ForegroundColor Yellow
ssh-keygen -t ed25519 -C "github-deploy-$(Get-Date -Format 'yyyyMMdd')" -f $keyPath -N ""

# Установка прав
icacls $keyPath /inheritance:r
icacls $keyPath /grant:r "$($env:USERNAME):F"

Write-Host "Ключ создан успешно!" -ForegroundColor Green

# Отображение публичного ключа
Write-Host "`n=== Публичный ключ (скопируйте его на сервер) ===" -ForegroundColor Cyan
Get-Content "$keyPath.pub"

Write-Host "`n=== Приватный ключ (добавьте в GitHub Secrets) ===" -ForegroundColor Cyan
Write-Host "1. Откройте файл: $keyPath" -ForegroundColor Yellow
Write-Host "2. Скопируйте ВСЁ содержимое в GitHub Secret: SSH_PRIVATE_KEY" -ForegroundColor Yellow

# Команда для копирования ключа на сервер
$serverHost = Read-Host "`nВведите hostname или IP сервера (по умолчанию: myServer)"
if ([string]::IsNullOrWhiteSpace($serverHost)) {
    $serverHost = "myServer"
}

Write-Host "`nКоманда для копирования ключа на сервер:" -ForegroundColor Cyan
Write-Host "type `$env:USERPROFILE\.ssh\github_deploy_key.pub | ssh artem@$serverHost `"cat >> ~/.ssh/authorized_keys`"" -ForegroundColor Yellow

# Тест подключения
Write-Host "`nТестирование подключения..." -ForegroundColor Yellow
$test = ssh -i $keyPath -o StrictHostKeyChecking=no -o ConnectTimeout=5 "artem@$serverHost" "docker --version" 2>&1

if ($LASTEXITCODE -eq 0) {
    Write-Host "SSH подключение успешно!" -ForegroundColor Green
    Write-Host $test
} else {
    Write-Host "SSH подключение не удалось. Убедитесь что:" -ForegroundColor Red
    Write-Host "1. Публичный ключ добавлен в ~/.ssh/authorized_keys на сервере" -ForegroundColor Red
    Write-Host "2. Docker установлен на сервере" -ForegroundColor Red
    Write-Host "3. Пользователь artem существует на сервере" -ForegroundColor Red
}

Write-Host "`n=== Следующие шаги ===" -ForegroundColor Cyan
Write-Host "1. Добавьте приватный ключ в GitHub Secrets как SSH_PRIVATE_KEY" -ForegroundColor White
Write-Host "2. Добавьте в GitHub Secrets:" -ForegroundColor White
Write-Host "   - SSH_PORT: 22" -ForegroundColor White
Write-Host "   - SERVER_HOST: $serverHost" -ForegroundColor White
Write-Host "   - SERVER_USER: artem" -ForegroundColor White
Write-Host "3. Запушьте код в GitHub для первого деплоя" -ForegroundColor White
