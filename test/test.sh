#!/usr/bin/env bash

rm -rf dist

echo "Building..."
echo ====================
echo

mkdir -p dist
g++ -DDESTKTOP_BUILD -DTEST -std=c++11 -Wall -o dist/DOOM $(find ../src -name '*.cpp')

echo
echo ====================
echo "Finished building"

echo
echo
echo "Testing..."
echo ====================
echo

TEST_RESULTS=$(./dist/DOOM)
echo "$TEST_RESULTS"

echo
echo ====================
echo "Finished testing"

if [[ $TEST_RESULTS =~ "FAILED" ]]; then
    echo "Some test failed!"
    exit 1
fi
