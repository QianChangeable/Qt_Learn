param(
    [switch]$Run,
    [switch]$Clean
)

$ErrorActionPreference = "Stop"

if (Test-Path (Join-Path $PSScriptRoot "CMakeLists.txt")) {
    $ProjectRoot = $PSScriptRoot
} elseif (Test-Path (Join-Path (Split-Path -Parent $PSScriptRoot) "CMakeLists.txt")) {
    $ProjectRoot = Split-Path -Parent $PSScriptRoot
} else {
    throw "CMakeLists.txt not found. Put this script in project root or scripts/."
}

$BuildDir = Join-Path $ProjectRoot "build"
$QtRoot   = "E:\Qt\5.15.2\mingw81_64"
$MingwBin = "E:\Qt\Tools\mingw810_64\bin"
$NinjaDir = "E:\Qt\Tools\Ninja"
$CMake    = "D:\CMake\bin\cmake.exe"

foreach ($p in @($QtRoot, $MingwBin, $NinjaDir, $CMake)) {
    if (-not (Test-Path $p)) {
        throw "Missing path: $p"
    }
}

$env:PATH = "$MingwBin;$(Join-Path $QtRoot 'bin');$NinjaDir;$env:PATH"

if ($Clean -and (Test-Path $BuildDir)) {
    Write-Host "==> Cleaning build..." -ForegroundColor Yellow
    Remove-Item -Recurse -Force $BuildDir
}

New-Item -ItemType Directory -Force -Path $BuildDir | Out-Null

Write-Host "==> Configuring Qt 5.15.2 MinGW..." -ForegroundColor Cyan
& $CMake -S $ProjectRoot -B $BuildDir `
    -G Ninja `
    -DCMAKE_BUILD_TYPE=Debug `
    -DCMAKE_PREFIX_PATH=$QtRoot `
    -DCMAKE_CXX_COMPILER="$(Join-Path $MingwBin 'g++.exe')" `
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

if ($LASTEXITCODE -ne 0) {
    throw "CMake configure failed"
}

Write-Host "==> Building..." -ForegroundColor Cyan
& $CMake --build $BuildDir
if ($LASTEXITCODE -ne 0) {
    throw "Build failed"
}

$exe = Join-Path $BuildDir "HelloQt.exe"
if (-not (Test-Path $exe)) {
    throw "Executable not found: $exe"
}

Write-Host "==> OK: $exe" -ForegroundColor Green

if ($Run) {
    Write-Host "==> Launching..." -ForegroundColor Cyan
    Start-Process $exe
}