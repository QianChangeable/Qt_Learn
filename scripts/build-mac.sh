#!/usr/bin/env bash
set -euo pipefail

NoRun=0
Clean=0

for arg in "$@"; do
  case "$arg" in
    --no-run|-NoRun) NoRun=1 ;;
    --clean|-Clean) Clean=1 ;;
    -h|--help)
      echo "Usage: $0 [--clean] [--no-run]"
      exit 0
      ;;
    *)
      echo "Unknown option: $arg" >&2
      exit 1
      ;;
  esac
done

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

if [[ -f "$SCRIPT_DIR/CMakeLists.txt" ]]; then
  ProjectRoot="$SCRIPT_DIR"
elif [[ -f "$(dirname "$SCRIPT_DIR")/CMakeLists.txt" ]]; then
  ProjectRoot="$(dirname "$SCRIPT_DIR")"
else
  echo "CMakeLists.txt not found. Put this script in project root or scripts/." >&2
  exit 1
fi

BuildDir="$ProjectRoot/build"

# Homebrew Qt 5 on Apple Silicon; override with CMAKE_PREFIX_PATH if needed.
QtRoot="${CMAKE_PREFIX_PATH:-/opt/homebrew/opt/qt@5}"

if [[ ! -d "$QtRoot" ]]; then
  echo "Missing Qt prefix: $QtRoot" >&2
  echo "Install with: brew install qt@5" >&2
  echo "Or set CMAKE_PREFIX_PATH to your Qt 5 prefix." >&2
  exit 1
fi

if ! command -v cmake >/dev/null 2>&1; then
  echo "cmake not found. Install with: brew install cmake" >&2
  exit 1
fi

Generator=()
if command -v ninja >/dev/null 2>&1; then
  Generator=(-G Ninja)
else
  Generator=(-G "Unix Makefiles")
  echo "==> ninja not found, using Unix Makefiles"
fi

if [[ "$Clean" -eq 1 && -d "$BuildDir" ]]; then
  echo "==> Cleaning build..."
  rm -rf "$BuildDir"
fi

mkdir -p "$BuildDir"

echo "==> Configuring Qt 5 (macOS)..."
cmake -S "$ProjectRoot" -B "$BuildDir" \
  "${Generator[@]}" \
  -DCMAKE_BUILD_TYPE=Debug \
  -DCMAKE_PREFIX_PATH="$QtRoot" \
  -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

echo "==> Building..."
cmake --build "$BuildDir"

exe="$BuildDir/HelloQt"
if [[ ! -x "$exe" ]]; then
  echo "Executable not found: $exe" >&2
  exit 1
fi

echo "==> OK: $exe"

if [[ "$NoRun" -eq 0 ]]; then
  echo "==> Launching..."
  "$exe"
fi
