#ifndef Utilities_H
#define Utilities_H

#include <string>
#include <unordered_map>

namespace utilities {

    // Prints letter frequencies
    void print_unordered_map(std::unordered_map<char, int> &key_value_pairs);

    // Checks if letter is in letter frequencies map
    bool check_key(char letter, std::unordered_map<char, int> &key_value_pairs);

    // Generates letter frequencies map
    void get_letter_frequencies(const std::string &input, std::unordered_map<char, int> &key_value_pairs);

    // Get Huffman encoding
    std::string generate_huffman_encoding(const std::string &input, std::unordered_map<char, std::string> &huffman_encoding);

    // Generates output bit stream from encoding
    void generate_bit_buffer(const std::string &encoded_string, unsigned char* out_buffer);

    // Generates binary string from bytes
    std::string generate_string_from_bytes(const int &bits, const int &bytes, unsigned char *bit_buffer);
}

#endif
