#include <iostream>

int main(int argc, char *argv[]){
    if(argc < 3){
        std::cout << "usage: " << argv[0] << " [input file (.obj)] [output file (.h/.hpp)]\n";
        return -1;
    }

    return 0;
}