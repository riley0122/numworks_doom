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

    std::fstream inFile(argv[1]);
    if(inFile.is_open())
    {
        std::cout << "Succesfully opened file " << argv[1] << "\n";

        std::string line;

        std::vector<point> points;
        std::vector<vertex> edges;

        while(std::getline(inFile, line))
        {
            if(line[0] == 'v' && line[1] == ' ')
            {
                points.push_back(generatePoint(line));
                std::cout << "Found point\n";
            } else if (line[0] == 'f' && line[1] == ' ')
            {
                // TODO: unwrap vector and append to edges
                std::cout << "Found face\n";
            }
        }

        inFile.close();
    } else
    {
        std::cout << "Failed to open " << argv[1] << ". Are you sure it exists?\n";
    }

    return 0;
}