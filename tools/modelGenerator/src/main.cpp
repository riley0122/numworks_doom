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
        outFile.close();
    } else
    {
        std::cout << "Failed to create or open " << argv[2] << "!\n";
        return 2;
    }

    return 0;
}