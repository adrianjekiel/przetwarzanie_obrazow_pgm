#!/bin/bash

PROJECT_DIR="$(pwd)"

echo "start"

cd $PROJECT_DIR

case $1 in
        "configure") mkdir build && cd "build" && cmake ..;;
        "clean") cd "build" && make clean;;
        "rebuild") cd "build" && make install;;
        "ut") cd "build" && make install && make test;;
        "remove") rm -rf "build";;
esac

echo "end"
