#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

void print_unordered_map(std::unordered_map<char, int> &key_value_pairs) {
    for( const auto& n : key_value_pairs ) {
        std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
    }
}

bool check_key(char letter, std::unordered_map<char, int> &key_value_pairs) {
    // Checks if key is in unordered_map
    if (key_value_pairs.find(letter) == key_value_pairs.end()) {
        return false;
    } else {
        return true;
    }
}

int read_file(std::string file_name, std::unordered_map<char, int> &key_value_pairs) {
    std::string line;
    std::ifstream myfile (file_name);
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            char letter;
            for (int i = 0; i < line.length(); i++){
                letter = line[i];
                // Increment frequency count (if in map)
                // Otherwise set frequency to 1 (if not in map)
                if (check_key(letter, key_value_pairs)) {
                    key_value_pairs[letter]++;
                } else {
                    key_value_pairs[letter] = 1;
                }
            }
        }
        myfile.close();
        return 0;
    }
    return -1;
    
}
int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "You entered incorrect arguments.\n";
        std::cout << "Please enter 'huffencode <inputFile> <outputFile>' where huffencode is the name of the application.\n";
        return 0;
    }

    std::unordered_map<char, int> key_value_pairs = {};
    read_file(argv[1], key_value_pairs);
    print_unordered_map(key_value_pairs);
    
    return 0;
}
