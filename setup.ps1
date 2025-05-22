$ErrorActionPreference = "Stop"
New-Item -ItemType Directory -Force -Path .\build
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_BUILD_TYPE=Debug -G Ninja -B build 