#include <fstream>
#include <iostream>
#include <memory>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
#include "HuffmanNode.h"

class Compare {
    public:
        bool operator() (HuffmanNode &a, HuffmanNode &b){
            if (a.getFrequency() < b.getFrequency()) {
                return true;
            }
            return false;
        }
};
void print_unordered_map(std::unordered_map<char, int> &key_value_pairs) {
    for( const auto& n : key_value_pairs ) {
        std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
    }
}

void build_huffman_tree(std::unordered_map<char, int> &key_value_pairs){
    std::priority_queue<HuffmanNode, std::vector<HuffmanNode>, Compare> min_huffman_heap;
    for( const auto& n : key_value_pairs ) {
        std::shared_ptr<HuffmanNode> node(new HuffmanNode(n.first, n.second));
        min_huffman_heap.push(*node);
    }
    std::cout << min_huffman_heap.size() << "\n";
}


bool check_key(char letter, std::unordered_map<char, int> &key_value_pairs) {
    // Checks if key is in unordered_map
    if (key_value_pairs.find(letter) == key_value_pairs.end()) {
        return false;
    }
    return true;
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
        return 1;
    } 
    std::cout << "There was an error reading the file. Did you enter the file name correctly?\n";
    return 0;
    
}
int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "You entered incorrect arguments.\n";
        std::cout << "Please enter 'huffencode <inputFile> <outputFile>' where huffencode is the name of the application.\n";
        return 0;
    }

    std::unordered_map<char, int> key_value_pairs = {};
    if (read_file(argv[1], key_value_pairs)) {
        print_unordered_map(key_value_pairs);
    }
    build_huffman_tree(key_value_pairs);
    return 0;
}
