#!/usr/bin/env bash

BUILD_DIR=build

echo "=== Generating CMake build files ==="
mkdir -p $BUILD_DIR
cmake -S . -B $BUILD_DIR

echo "=== Building the project ==="
cmake --build $BUILD_DIR --config Release

echo "=== Build process completed ==="
