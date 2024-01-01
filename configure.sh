#!/bin/bash
chmod +x build.sh install.sh run.sh
cmake -S . -B BuildDirLinux -G"Ninja" -DCMAKE_BUILD_TYPE=Debug
