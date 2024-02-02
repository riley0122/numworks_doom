#pragma once

#include <string>
#include <vector>
#include <cstdlib>

std::vector<std::string> split(std::string string, char splitter);

struct point
{
    float x;
    float y;
    float z;
};

struct vertex
{
    int from;
    int to;
};

point generatePoint(std::string string);
std::vector<vertex> generateEdgesFromFace(std::string faceString);
