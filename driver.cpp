#include <fstream>
#include <iostream>
#include <memory>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
#include "HuffmanNode.h"

// This class is needed to compare two HuffmanNodes
class Compare {
    public:
        int operator() (const HuffmanNode &a, const HuffmanNode &b){
            return a.getFrequency() > b.getFrequency();
        }
};

void print_unordered_map(std::unordered_map<char, int> &key_value_pairs) {
    for( const auto& n : key_value_pairs ) {
        std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
    }
}

void print_tree(std::priority_queue<HuffmanNode, std::vector<HuffmanNode>, Compare> tree) {

}

// First construct a min-heap with frequency values. Then build the huffman tree.
void build_huffman_tree(std::unordered_map<char, int> &key_value_pairs){
    std::priority_queue<HuffmanNode, std::vector<HuffmanNode>, Compare> huffman_tree;
    for( const auto& n : key_value_pairs ) {
        std::shared_ptr<HuffmanNode> node(new HuffmanNode(n.first, n.second));
        huffman_tree.push(*node);
    }

    while (huffman_tree.size() != 1) {
        HuffmanNode small_1 = huffman_tree.top();
        huffman_tree.pop();
        HuffmanNode small_2 = huffman_tree.top();
        huffman_tree.pop();
        int freq = small_1.getFrequency() + small_2.getFrequency();
        std::shared_ptr<HuffmanNode> node(new HuffmanNode('\0', freq, small_1, small_2));
        huffman_tree.push(*node);
    }
    HuffmanNode root = huffman_tree.top();
    std::cout << "Root: " << root.getFrequency() << " letter: " << root.getLetter() << "\n";
    std::cout << "HuffmanTree built\n";
}

// Checks if key is in unordered_map
bool check_key(char letter, std::unordered_map<char, int> &key_value_pairs) {
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
