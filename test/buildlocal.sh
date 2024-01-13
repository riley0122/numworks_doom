#!/usr/bin/env bash

mkdir -p dist
g++ -std=c++11 -Wall -o dist/DOOM $(find ../src -name '*.cpp')