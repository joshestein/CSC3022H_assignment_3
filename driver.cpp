#include <fstream>
#include <iostream>
#include <memory>
#include <queue>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
#include "HuffmanNode.h"
#include "HuffmanTree.h"

void print_unordered_map(std::unordered_map<char, int> &key_value_pairs) {
    for( const auto& n : key_value_pairs ) {
        std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
    }
}

/*
void inorder(std::shared_ptr<HuffmanNode> root) {
    if (root->left == nullptr && root->right == nullptr) {
        std::cout << root->getLetter() << ": " << root->getFrequency() << "\n";
    } else {
        if (root->left != nullptr) {
            inorder(root->left);
        }
        if (root->right != nullptr) {
            inorder(root->right);
        }
    }
}
*/

// First construct a min-heap with frequency values. Then build the huffman tree.
HuffmanTree build_huffman_tree(std::unordered_map<char, int> &key_value_pairs){
    HuffmanTree tree;

    // push letter-frequencies onto Huffman tree (as leaves)
    for( const auto& n : key_value_pairs ) {
        HuffmanNode node(n.first, n.second);
        tree.push(node);
    }

    while (tree.size() != 1) {
        HuffmanNode small_1 = tree.top();
        tree.pop();
        HuffmanNode small_2 = tree.top();
        tree.pop();

        //std::cout << "small_1: " << small_1.getLetter() << " freq: "<<small_1.getFrequency() << "\n";
        
        // combine frequencies of two smallest nodes
        // put into new node
        int freq = small_1.getFrequency() + small_2.getFrequency();
        HuffmanNode node('\0', freq);;
        node.left = std::make_shared<HuffmanNode>(small_1);
        node.right = std::make_shared<HuffmanNode>(small_2);
        tree.push(node);
    }

    //inorder(root);
    std::cout << "HuffmanTree built\n";
    return tree;
}

// Checks if key is in unordered_map
bool check_key(char letter, std::unordered_map<char, int> &key_value_pairs) {
    if (key_value_pairs.find(letter) == key_value_pairs.end()) {
        return false;
    }
    return true;
}

// Read file into char array
std::string read_file_into_string(const std::string &file_name) {
    std::ifstream myfile (file_name);
    if (myfile.is_open()) {
        std::stringstream buffer;
        buffer << myfile.rdbuf();
        myfile.close();                    
        return buffer.str();
    }
    std::cout << "There was an error reading the file. Did you enter the file name correctly?\n";
    return "";
}

// Generate letter frequencies
void get_letter_frequencies(const std::string &input, std::unordered_map<char, int> &key_value_pairs) {
    for (int i = 0; i < input.size(); i++) {
        if (check_key(input[i], key_value_pairs)) {
            key_value_pairs[input[i]]++;
        } else {
            key_value_pairs[input[i]] = 1;
        }
    }
}

// Read file into key value pairs
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

int write_out(const std::string &output_name, const std::string &input, std::unordered_map<char, std::string> &huffman_encoding) {
    std::ofstream myfile;

    // write header
    myfile.open(output_name + ".hdr");
    myfile << "Letter, Code\n";
    for (auto pair:huffman_encoding) {
        myfile  << pair.first << ", " << pair.second << "\n";
    }
    myfile.close();
    
    myfile.open(output_name + ".txt");
    for (int i = 0; i < input.size(); i++) {
        myfile << huffman_encoding[input[i]];
    }
    myfile.close();
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "You entered incorrect arguments.\n";
        std::cout << "Please enter 'huffencode <inputFile> <outputFile>' where huffencode is the name of the application.\n";
        return 0;
    }

    // read file into string
    std::string input = read_file_into_string(argv[1]);
    std::unordered_map<char, int> key_value_pairs = {};

    // generate letter frequencies in string
    get_letter_frequencies(input, key_value_pairs);
    
    HuffmanTree tree = build_huffman_tree(key_value_pairs);
    std::unordered_map<char, std::string> huffman_encoding;

    HuffmanNode root = tree.top();
    tree.encode(root, "", huffman_encoding);

    write_out(argv[2], input, huffman_encoding);
    return 0;
}
