#!/bin/bash

cmake -S . -B build-debug -DCMAKE_BUILD_TYPE=debug
cmake --build build-debug
