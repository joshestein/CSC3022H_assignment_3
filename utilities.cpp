#include "utilities.h"
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
