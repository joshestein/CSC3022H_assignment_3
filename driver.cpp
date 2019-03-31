#include <bitset>
#include <fstream>
#include <iostream>
#include <math.h>
#include <memory>
#include <queue>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
#include "HuffmanNode.h"
#include "HuffmanTree.h"
#include "utilities.h"

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

// Write encoding pairs to .hdr file and actual encoding to .txt
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

    unsigned char bit_buffer;
    int bit_count = 0;

    myfile.open(output_name + "_bitstream.txt", std::ofstream::binary);
    // build a bit_buffer with every 8 bites
    // write that buffer to a file, then start again
    for (int i = 0; i < encoded_string.size(); i++) {
        int bit = encoded_string[i] - '0';
        bit_buffer = bit_buffer << 1|bit;
        bit_count++;
        if (bit_count == 8) {
            myfile << bit_buffer;
            bit_buffer = 0;
            bit_count  = 0;
        }
    }
    // leftover bits
    //bit_buffer = bit_buffer & 0xFF;
    myfile << bit_buffer;
    myfile.close();

    myfile.open(output_name + "_bitstream.hdr");
    myfile << encoded_string.size();
    myfile.close();

    // strtol can also be used, but will be limited for very large encodings

    return 1;
}

std::string read_bytes(const std::string &file_name) {
    int bits;

    std::ifstream myfile (file_name+"_bitstream.hdr");
    myfile >> bits;
    myfile.close();

    int bytes = ceil(bits/8.0);

    myfile.open(file_name+"_bitstream.txt", std::ifstream::binary);
    if (myfile.is_open()) {
        unsigned char buffer[bytes];
        myfile >> buffer;
        myfile.close();

        std::string output;
        for (int i = 0; i < bytes; i ++) { 
            // if there is a leftover number of bits
            // For example, if there are 6 or 14 bits
            // We want to process the first few bytes
            // Then process the remainder
            if (i == bytes-1 && bits%8 != 0){
                std::bitset<8>b(buffer[i]);
                std::string b_string = b.to_string();
                output += b_string.substr(8-bits%8, 8);
                return output;
            }
            output += std::bitset<8>(buffer[i]).to_string();
        }
        return output;
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

    // generate letter frequencies in given string
    utilities::get_letter_frequencies(input, key_value_pairs);
    
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
