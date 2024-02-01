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

point generatePoint(std::string string);
