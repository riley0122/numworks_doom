#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "helper.h"

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        std::cout << "usage: " << argv[0] << " [input file (.obj)] [output file (.h/.hpp)]\n";
        return -1;
    }

    std::vector<point> points;
    std::vector<vertex> edges;

    std::string name = "defualtName";

    std::fstream inFile(argv[1]);
    if(inFile.is_open())
    {
        std::cout << "Succesfully opened file " << argv[1] << "\n";

        std::string line;

        while(std::getline(inFile, line))
        {
            if(line[0] == 'v' && line[1] == ' ')
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
    if(outFile.is_open())
    {
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