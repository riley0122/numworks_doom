#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char *argv[]){
    if(argc < 3){
        std::cout << "usage: " << argv[0] << " [input file (.obj)] [output file (.h/.hpp)]\n";
        return -1;
    }

    std::fstream inFile(argv[1]);
    if(inFile.is_open()){
        std::cout << "Succesfully opened file " << argv[1] << "\n";

        std::string line;

        std::vector<std::string> pointStrings;
        std::vector<std::string> edgeStrings;

        while(std::getline(inFile, line)){
            if(line[0] == 'v' && line[1] == ' '){
                pointStrings.push_back(line);
                std::cout << "Found point\n";
            }
        }

        inFile.close();
    }else{
        std::cout << "Failed to open " << argv[1] << ". Are you sure it exists?\n";
    }

    return 0;
}