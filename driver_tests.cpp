#include "catch.hpp"
#include "HuffmanNode.h"
#include "HuffmanTree.h"
#include "utilities.h"

#include <iostream>
#include <string>
#include <unordered_map>


TEST_CASE("Frequency counting tests", "[Frequency]") {
    std::cout << "-----------------------------\n";
    std::cout << "Frequency counting tests\n";
    std::cout << "-----------------------------\n";

    std::unordered_map<char, int> key_value_pairs;
    std::string a = "a";
    utilities::get_letter_frequencies(a, key_value_pairs);

    REQUIRE(key_value_pairs['a'] == 1);
    REQUIRE(key_value_pairs['b'] == 0);

    key_value_pairs.clear();
    std::string ab = "ab";
    utilities::get_letter_frequencies(ab, key_value_pairs);

    REQUIRE(key_value_pairs['a'] == 1);
    REQUIRE(key_value_pairs['b'] == 1);

    key_value_pairs.clear();
    std::string aab = "aab";
    utilities::get_letter_frequencies(aab, key_value_pairs);

    REQUIRE(key_value_pairs['a'] == 2);
    REQUIRE(key_value_pairs['b'] == 1);
}
