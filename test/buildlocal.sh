#!/usr/bin/env bash

mkdir -p dist
g++ -DDESTKTOP_BUILD -std=c++11 -Wall -o dist/DOOM $(find ../src -name '*.cpp')