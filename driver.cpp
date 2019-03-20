#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

int read_file(std::string file_name) {
    std::string line;
    std::ifstream myfile (file_name);
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            std::cout << line << "\n";
        }
        myfile.close();
        return 0;
    }
    return -1;
    
}
int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "You entered incorrect arguments.\n";
        std::cout << "Please enter 'huffencode <inputFile> <outputFile>' where huffencode is the name of the application\n";
        return 0;
    }
    read_file(argv[1]);

    
    return 0;
}
