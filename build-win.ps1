param(
    [switch]$NoRun,
    [switch]$Clean
)

& "$PSScriptRoot\scripts\build-win.ps1" -NoRun:$NoRun -Clean:$Clean