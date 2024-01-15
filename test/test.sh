#!/usr/bin/env bash

echo "Building..."
echo ====================
echo

mkdir -p dist
g++ -DDESTKTOP_BUILD -DTEST -std=c++11 -Wall -o dist/DOOM $(find ../src -name '*.cpp')

echo
echo ====================
echo "Finished building"