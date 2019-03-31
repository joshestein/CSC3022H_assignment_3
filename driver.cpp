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
int write_pairs(const std::string &output_name, std::unordered_map<char, std::string> &huffman_encoding) {
    std::ofstream myfile;

    // write header
    myfile.open(output_name + ".hdr");
    if (myfile.is_open()) {
        myfile << "Letter, Code\n";
        for (auto pair:huffman_encoding) {
            myfile  << pair.first << ", " << pair.second << "\n";
        }
        myfile.close();
    }
    std::cout << "Failed to write Huffman pairs to header\n";
    return 0;
}

int write_encoding(const std::string &output_name, const std::string &encoded_string, std::unordered_map<char, std::string> &huffman_encoding) {
    std::ofstream myfile;
    myfile.open(output_name + ".txt");
    if (myfile.is_open()) {
        myfile << encoded_string;
        myfile.close();
        return 1;
    }
    std::cout << "Failed to write encoding\n";
    return 0;
}

int write_bytes(const unsigned char *bytes, const std::string &output_name) {
    std::ofstream myfile;

    myfile.open(output_name + "_bitstream.txt", std::ofstream::binary);
    if (myfile.is_open()) {
        myfile << bytes;
        myfile.close();
        return 1;
    }
    std::cout << "Failed to write bitstream\n";
    return 0;
}

std::string read_bytes_into_binary_string(const std::string &file_name) {
    int bits, bytes;

    std::ifstream myfile (file_name+"_bitstream.hdr");
    myfile >> bits;
    myfile.close();

    bytes = ceil(bits/8.0);

    myfile.open(file_name+"_bitstream.txt", std::ifstream::binary);
    if (myfile.is_open()) {
        unsigned char buffer[bytes];
        myfile >> buffer;
        myfile.close();

        std::string output = utilities::generate_string_from_bytes(bits, bytes, buffer);
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
    
    // build huffman tree and encodings
    HuffmanTree tree; 
    tree.build_tree(key_value_pairs);
    std::unordered_map<char, std::string> huffman_encoding;
    std::unordered_map<std::string, char> reverse_encoding;

    HuffmanNode root = tree.top();
    tree.encode(root, "", huffman_encoding, reverse_encoding);

    // write huffman encoding pairs
    if (write_pairs(argv[2], huffman_encoding)) {
        std::cout << "Succesfully wrote Huffman pairs to output header.\n";
    }

    std::string encoded_string = utilities::generate_huffman_encoding(input, huffman_encoding);

    if (write_encoding(argv[2], encoded_string, huffman_encoding)) {
        std::cout << "Wrote encoded string to output file. \n";
    }

    //std::string encoded_string_2 = read_file_into_string(std::string(argv[2]) + ".txt");
    //std::string decoded = tree.decode(encoded_string, reverse_encoding);

    int bytes = ceil(encoded_string.size()/8.0);
    unsigned char out_buffer[bytes];
    // generate output bit buffer
    utilities::generate_bit_buffer(encoded_string, out_buffer);

    if (write_bytes(out_buffer, argv[2])) {
        std::cout << "Succesfully wrote bit-stream.\n";
    }

    // read bit buffer and decode
    std::string new_encoded_string = read_bytes_into_binary_string(std::string(argv[2]));
    std::string new_decoded = tree.decode(new_encoded_string, reverse_encoding);
    std::cout << new_decoded << "\n";
            
    return 0;
}
