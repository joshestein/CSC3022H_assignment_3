#include "catch.hpp"
#include "HuffmanNode.h"
#include "HuffmanTree.h"
#include "utilities.h"

#include <iostream>
#include <math.h>
#include <string>
#include <unordered_map>


TEST_CASE("Utility tests", "[Utilities]") {
    std::cout << "-----------------------------\n";
    std::cout << "Utility  tests\n";
    std::cout << "-----------------------------\n";
    std::cout << "Frequency count tests\n";

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


    std::cout << "Huffman pairs tests --> tested more in HuffmanTree_tests.cpp\n";
    HuffmanTree tree;
    tree.build_tree(key_value_pairs);
    //      (3)
    //    /    \
    //  (b-1)  (a-2)
    std::unordered_map<char, std::string> huffman_encoding;
    std::unordered_map<std::string, char> reverse_encoding;

    HuffmanNode root = tree.top();
    tree.encode(root, "", huffman_encoding, reverse_encoding);

    REQUIRE(huffman_encoding['b'] == "0");
    REQUIRE(huffman_encoding['a'] == "1");
    REQUIRE(reverse_encoding["0"] == 'b');
    REQUIRE(reverse_encoding["1"] == 'a');

    std::cout << "Huffman encoding tests\n";
    std::string encoded_string = utilities::generate_huffman_encoding(aab, huffman_encoding);
    REQUIRE(encoded_string == "110");

    // ENCODED_STRING = 110
    // Bits = 3
    // One byte = 0000 0110
    // Integer value = 6

    std::cout << "Output buffer generation tests\n";
    int bytes = ceil(encoded_string.size()/8.0);
    REQUIRE(bytes == 1);

    unsigned char out_buffer[bytes];
    utilities::generate_bit_buffer(encoded_string, out_buffer);

    REQUIRE(out_buffer[0] == 6);

    std::cout << "Binary string from bytes tests\n";
    // assume the same buffer will be read in as that which is written out
    std::string binary_string = utilities::generate_string_from_bytes(3, 1, out_buffer);
    REQUIRE(binary_string == "110");
}
