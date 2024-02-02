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

template <typename T>
void appendVectorToVector(std::vector<T> *first, std::vector<T> second){
    for (int i = 0; i < second.size(); i++)
    {
        *first->push_back(second[i]);
    }
}

point generatePoint(std::string string){
    std::vector<std::string> values = split(string, ' ');

    float x = atof(values[1].c_str());
    float y = atof(values[2].c_str());
    float z = atof(values[3].c_str());

    return point{x, y, z};
}

std::vector<vertex> generateEdgesFromFace(std::string faceString){
    std::vector<std::string> splitted = split(faceString, ' ');
    splitted.erase(splitted.begin());

    std::vector<int> vertexes;

    for (int i = 0; i < splitted.size(); i++)
    {
        vertexes.push_back(splitted[i][0] - '0');
    }

    std::vector<vertex> results;

    for (int i = 0; i < vertexes.size() - 1; i++)
    {
        results.push_back(vertex{i, i + 1});
    }

    return results;
}
