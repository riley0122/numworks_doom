#pragma once

#include <string>
#include <vector>
#include <cstdlib>

std::vector<std::string> split(std::string string, char splitter);
// Append second vector to first vector
template <typename T>
void appendVectorToVector(std::vector<T> *first, std::vector<T> second);

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
