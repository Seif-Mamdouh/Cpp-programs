#include <iostream>
#include <fstream>
#include <vector>

int main() {

    std::string filename;
    std::cin>> filename;

    std::ofstream file ( filename.c_str(), std::ios::app);

    if(file.is_open()){
        std::cout << "Success Bitch!\n";
    }

    std::vector<std::string> names; 
    names.push_back("Fasial");
    names.push_back("Seif");
    names.push_back("Areej");
    names.push_back("FUCK");

    for(std::string name : names) {
        file << name << std::endl;
    }

    file.close();

    return 0;
}