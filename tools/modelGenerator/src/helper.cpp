#include "helper.h"

#include <string>
#include <vector>

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

    return result;
}