#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"

mkdir -p build
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_BUILD_TYPE=Debug -G Ninja -B build 