param(
    [switch]$Run,
    [switch]$Clean
)

& "$PSScriptRoot\scripts\build.ps1" -Run:$Run -Clean:$Clean