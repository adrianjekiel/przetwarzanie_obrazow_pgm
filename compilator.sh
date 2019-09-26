#!/bin/bash

PROJECT_DIR="$(pwd)"

echo "start"

cd $PROJECT_DIR

case $1 in
        "configure") mkdir -p build && cd "build" && cmake ..;;
        "clean") cd "build" && make clean;;
        "rebuild") cd "build" && make all;;
        "ut") cd "build" && make install && make test;;
        "remove") rm -rf "build";;
esac

echo "end"
