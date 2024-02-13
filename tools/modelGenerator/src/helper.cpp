/*
  This Source Code Form is "Incompatible With Secondary Licenses," as
  defined by the Mozilla Public License, v. 2.0.

  This specific component is licensed under the GNU General Public License
  (GPL). Please refer to the 'LICENSE' file in this directory for the
  applicable terms of the GPL.

  Note: The 'LICENSE' file in the root directory of the project covers
  the rest of the project, and this notice applies specifically to this
  component within the "tools" directory.

    modelGenerator: generates header files out of 3D models.
    Copyright (C) 2024 contributers

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#include "helper.h"

#include <string>
#include <vector>
#include <cstdlib>

#define SCALE 15

std::vector<std::string> split(std::string string, char splitter) {
    std::vector<std::string> result;
    std::string subString = "";

    for (int i = 0; i < string.length(); i++)
    {
        if (string[i] == splitter)
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

point generatePoint(std::string string) {
    std::vector<std::string> values = split(string, ' ');

    float x = atof(values[1].c_str()) * SCALE;
    float y = atof(values[2].c_str()) * SCALE;
    float z = atof(values[3].c_str()) * SCALE;

    return point{x, y, z};
}

std::vector<vertex> generateEdgesFromFace(std::string faceString) {
    std::vector<std::string> splitted = split(faceString, ' ');
    splitted.erase(splitted.begin());

    std::vector<int> vertexes;

    for (int i = 0; i < splitted.size(); i++)
    {
        vertexes.push_back(atoi(split(splitted[i], '/')[0].c_str()));
    }

    std::vector<vertex> results;

    for (int i = 0; i < vertexes.size() - 1; i++)
    {
        results.push_back(vertex{vertexes[i] - 1, vertexes[i + 1] - 1});
    }

    results.push_back(vertex{vertexes[vertexes.size() - 1] - 1, vertexes[0] - 1});

    return results;
}
