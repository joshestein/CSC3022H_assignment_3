#include "utilities.h"
#include <bitset>
#include <iostream>

void utilities::print_unordered_map(std::unordered_map<char, int> &key_value_pairs) {
    for( const auto& n : key_value_pairs ) {
        std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
    }
}

// Checks if letter is in letter frequencies map
bool utilities::check_key(char letter, std::unordered_map<char, int> &key_value_pairs) {
    if (key_value_pairs.find(letter) == key_value_pairs.end()) {
        return false;
    }
    return true;
}

// Generates letter frequencies map
void utilities::get_letter_frequencies(const std::string &input, std::unordered_map<char, int> &key_value_pairs) {
    for (int i = 0; i < input.size(); i++) {
        if (check_key(input[i], key_value_pairs)) {
            key_value_pairs[input[i]]++;
        } else {
            key_value_pairs[input[i]] = 1;
        }
    }
}

std::string utilities::generate_huffman_encoding(const std::string &input, std::unordered_map<char, std::string> &huffman_encoding) {
    std::string output;
    for (int i = 0; i < input.size(); i++) {
         output += huffman_encoding[input[i]];
    }
    return output;
}

void utilities::generate_bit_buffer(const std::string &encoded_string, unsigned char* out_buffer) {
    unsigned char bit_buffer;
    int bit_count = 0;

    // build a bit_buffer with every 8 bites
    // write that buffer to a file, then start again
    int index = 0;
    for (int i = 0; i < encoded_string.size(); i++) {
        int bit = encoded_string[i] - '0';
        bit_buffer = bit_buffer << 1|bit;
        bit_count++;
        if (bit_count == 8) {
            out_buffer[index] = bit_buffer;
            index++;
            bit_buffer = 0;
            bit_count  = 0;
        }
    }
    // leftover bits
    //overall_bit_buffer << bit_buffer;
    if (index != encoded_string.size()) {
        out_buffer[index] = bit_buffer;
    }
}

std::string utilities::generate_string_from_bytes(const int &bits, const int &bytes, unsigned char *bit_buffer) {
    std::string output;
    for (int i = 0; i < bytes; i ++) { 
        // if there is a leftover number of bits
        // For example, if there are 6 or 14 bits
        // We want to process the first few bytes
        // Then process the remainder
        if (i == bytes-1 && bits%8 != 0){
            std::bitset<8>b(bit_buffer[i]);
            std::string b_string = b.to_string();
            output += b_string.substr(8-bits%8, 8);
            return output;
        }
        output += std::bitset<8>(bit_buffer[i]).to_string();
    }
    return output;
}
