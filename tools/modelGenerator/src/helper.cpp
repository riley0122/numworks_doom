#include "helper.h"

#include <string>
#include <vector>
#include <cstdlib>

std::vector<std::string> split(std::string string, char splitter)
{
    std::vector<std::string> result;
    std::string subString = "";

    for (int i = 0; i < string.length(); i++)
    {
        if(string[i] == splitter)
        {
            result.push_back(subString);
            subString = "";
        } else
        {
            subString += string[i];
        }
    }

    result.push_back(subString);

    return result;
}

point generatePoint(std::string string){
    std::vector<std::string> values = split(string, ' ');

    float x = atof(values[1].c_str());
    float y = atof(values[2].c_str());
    float z = atof(values[3].c_str());

    return point{x, y, z};
}
