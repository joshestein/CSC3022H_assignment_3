#include <bitset>
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

// Checks if key is in unordered_map
bool check_key(char letter, std::unordered_map<char, int> &key_value_pairs) {
    if (key_value_pairs.find(letter) == key_value_pairs.end()) {
        return false;
    }
    return true;
}

// Read file into string
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

int write_bytes(const std::string &output_name, const std::string &encoded_string) {
    std::ofstream myfile;

    /*
    myfile.open(output_name + "_bitstream.txt");
    std::cout << encoded_string << "\n";
    for (int i = 0; i < encoded_string.size(); i++) {
        int bit = encoded_string[i] - '0';
        //std::cout << bit; 
        bit_buffer = bit_buffer << 1|bit;
        //std::cout << (int)bit_buffer << "\n";
        //std::cout << bit_buffer << "\n";
        bit_count++;
        overall_bit_count++;
        if (bit_count == 8) {
            myfile << &bit_buffer;
            std::cout << "Bit buffer: " << &bit_buffer << "\n";
            //std::cout << "Bit buffer: " << (int)bit_buffer << "\n";
            bit_buffer = 0;
            bit_count  = 0;
        }
    }
    std::cout << "Bit buffer: " << (int)bit_buffer << "\n";
    myfile << &bit_buffer;
    myfile.close();

    myfile.open(output_name + "_bitstream.hdr");
    myfile << overall_bit_count++;
    myfile.close();

    */


    char *end;
    long value = std::strtol(encoded_string.c_str(), &end, 2);
    unsigned char c = value;

    myfile.open(output_name+"_bytes.txt", std::ofstream::binary);
    myfile.write(encoded_string.c_str(), encoded_string.size());
    myfile.close();

    myfile.open(output_name+"_bytes.hdr");
    myfile << encoded_string.size();
    myfile.close();
    /*
    std::cout <<  c_2 << "\n";
    std::cout << (int)c_2 << "\n";
    unsigned char c = value & 0xFF;
    std::cout << "Strtol char" << c << "\n";
    */

    return 1;
}

std::string read_bytes(const std::string &file_name) {
    int size;

    std::ifstream myfile (file_name+"_bytes.hdr");
    myfile >> size;
    myfile.close();

    myfile.open(file_name+"_bytes.txt", std::ifstream::binary);
    if (myfile.is_open()) {
        std::string buffer;
        buffer.resize(size);
        myfile.read(&buffer[0], buffer.size());
        myfile.close();
        return buffer;
    }
    std::cout << "There was an error reading the file. Did you enter the file name correctly?\n";
    return "";
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
    
    HuffmanTree tree; 
    tree.build_tree(key_value_pairs);
    std::unordered_map<char, std::string> huffman_encoding;
    std::unordered_map<std::string, char> reverse_encoding;

    HuffmanNode root = tree.top();
    tree.encode(root, "", huffman_encoding, reverse_encoding);

    write_out(argv[2], input, huffman_encoding);
    
    std::string encoded_string = read_file_into_string(std::string(argv[2]) + ".txt");
    std::string decoded = tree.decode(encoded_string, reverse_encoding);

    if (write_bytes(argv[2], encoded_string)) {
        std::cout << "Succesfully wrote bit-stream\n";
    }

    std::string new_encoded_string = read_bytes(std::string(argv[2]));
    std::string new_decoded = tree.decode(new_encoded_string, reverse_encoding);
    std::cout << new_decoded << "\n";
            
    return 0;
}
