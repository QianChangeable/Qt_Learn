param(
    [switch]$NoRun,
    [switch]$Clean
)

& "$PSScriptRoot\scripts\build.ps1" -NoRun:$NoRun -Clean:$Clean