#!/usr/bin/env bash
# This Source Code Formis subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at https://mozilla.org/MPL/2.0/.

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
