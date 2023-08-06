@echo off

set BUILD_DIR=build

echo === Generating CMake build files ===
if not exist %BUILD_DIR% mkdir %BUILD_DIR%
cmake -S . -B %BUILD_DIR%

echo === Building the project ===
cmake --build %BUILD_DIR% --config Release

echo === Build process completed ===
