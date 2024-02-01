#include <iostream>
#include <fstream>

int main(int argc, char *argv[]){
    if(argc < 3){
        std::cout << "usage: " << argv[0] << " [input file (.obj)] [output file (.h/.hpp)]\n";
        return -1;
    }

    std::fstream inFile(argv[1]);
    if(inFile.is_open()){
        std::cout << "Succesfully opened file " << argv[1] << "\n";

        inFile.close();
    }else{
        std::cout << "Failed to open " << argv[1] << ". Are you sure it exists?\n";
    }

    return 0;
}