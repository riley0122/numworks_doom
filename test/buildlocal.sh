#!/usr/bin/env bash

response="n"

if [ "$1" == "-y" ] || [ "$1" == "--yes" ]; then
    response="y"
elif [ "$1" == "-n" ] || [ "$1" == "--no" ]; then
    response="n"
else
    echo -n "Do you want to enable graphics mode? (y/n): "
    read -r response

    while [[ ! "$response" =~ ^[YyNn]$ ]]; do
        echo "Please enter 'y' or 'n'."
        echo -n "Do you want to enable graphics mode? (y/n): "
        read -r response
    done
fi

mkdir -p dist

if [ "$response" == "y" ] || [ "$response" == "Y" ]; then
    echo "Building WITH graphics"
    g++ -DDESTKTOP_BUILD -DGRAPHICS_ENABLED -std=c++11 -Wall -o dist/DOOM $(find ../src -name '*.cpp') -lSDL2
else
    echo "Building WITHOUT graphics"
    g++ -DDESTKTOP_BUILD -std=c++11 -Wall -o dist/DOOM $(find ../src -name '*.cpp')
fi
