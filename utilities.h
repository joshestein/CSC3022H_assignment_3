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
}

#endif
