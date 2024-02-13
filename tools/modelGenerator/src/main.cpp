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
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "helper.h"

int main(int argc, char *argv[]) {
    std::cout << "numworks_doom/tools/modelGenerator Copyright (C) 2024 contributors\nThis program comes with ABSOLUTELY NO WARRANTY; This program is licensed under the GPL license";
    if (argc < 3)
    {
        std::cout << "usage: " << argv[0] << " [input file (.obj)] [output file (.h/.hpp)]\n";
        return -1;
    }

    std::vector<point> points;
    std::vector<vertex> edges;

    std::string name = "defualtName";

    std::fstream inFile(argv[1]);
    if (inFile.is_open())
    {
        std::cout << "Succesfully opened file " << argv[1] << "\n";

        std::string line;

        while (std::getline(inFile, line))
        {
            if (line[0] == 'v' && line[1] == ' ')
            {
                points.push_back(generatePoint(line));
                std::cout << "Found point\n";
            } else if (line[0] == 'f' && line[1] == ' ')
            {
                std::vector<vertex> found = generateEdgesFromFace(line);
                edges.insert(edges.end(), found.begin(), found.end());
                std::cout << "Found face with " << found.size() << " edges\n";
            } else if (line[0] == 'o' && line[1] == ' ' && name == "defualtName")
            {
                name = split(line, ' ')[1];
            }
        }

        inFile.close();
    } else
    {
        std::cout << "Failed to open " << argv[1] << ". Are you sure it exists?\n";
        return 1;
    }

    std::cout << "Finished parsing " << argv[1] << " with " << points.size() << " points and " << edges.size() << " edges.\n";

    std::ofstream outFile(argv[2]);
    if (outFile.is_open())
    {
        outFile << "/*\n" << "\tAUTOGENERATED FILE\n" << "\n" << "\tThis file was automatically generated by the model generator tool.\n" << "\t(https://github.com/riley0122/numworks_doom/tree/main/tools/modelGenerator)\n" <<  "*/\n";
        outFile << "#pragma once\n" << "#include \"pos.h\"\n\n" << "namespace " << name << "\n{\n";

        outFile << "\t" << "position points[" << points.size() << "] = {\n";

        for (int i = 0; i < points.size(); i++) 
	{
            // 3 values each with max 3 decimals one decimal point 3 characters as base and a negative sign so max 8 per number
            // 10 for position and brackets
            // 9 for newlines tabs and commas
            int lineAlloc = (8 * 3 + 10 + 9);
            char *string = (char *) malloc(lineAlloc * sizeof(char));
            snprintf(string, lineAlloc, "\t\tposition{%.3f,%.3f,%.3f},\n", points[i].x, points[i].y, points[i].z);
            outFile << string;
        }

        outFile << "\t" << "};\n";

        outFile << "\n";

        outFile << "\t" << "vertex edges[" << edges.size() << "] = {\n";

        for (int i = 0; i < edges.size(); i++)
        {
            // 3 characters reserved for each number, dont expect more than 999 edges
            // 8 for vertex and brackets
            // 9 for newlines tabs and commas
            int lineAlloc = (2 * 3 + 8 + 9);
            char *string = (char *) malloc(lineAlloc * sizeof(char));
            snprintf(string, lineAlloc, "\t\tvertex{%d,%d},\n", edges[i].from, edges[i].to);
            outFile << string;
        }

        outFile << "\t" << "};\n";

        outFile << "}\n";

        outFile.close();

        std::cout << "Wrote " << argv[2] << " succesfully!\n";
    } else
    {
        std::cout << "Failed to create or open " << argv[2] << "!\n";
        return 2;
    }

    return 0;
}
