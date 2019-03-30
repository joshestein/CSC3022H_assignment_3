#include "catch.hpp"
#include "HuffmanTree.h"
#include "HuffmanNode.h"
#include <iostream>
#include <unordered_map>

bool check_key(char letter, std::unordered_map<char, int> &key_value_pairs) {
     if (key_value_pairs.find(letter) == key_value_pairs.end()) {
         return false;
     }
     return true;
}

TEST_CASE("HuffmanTree tests", "[HuffmanTree]") {
    std::cout << "HUFFMAN_TREE TESTS\n";
    std::cout << "---------------------\n";
    std::cout << "Default constructor tests\n";

    HuffmanTree tree;
    REQUIRE(tree.size() == 0);

    std::cout << "Push and size() tests\n";
    HuffmanNode node('a', 1);
    HuffmanNode node2('b', 2);
    tree.push(node);
    REQUIRE(tree.size() == 1);
    tree.push(node2);
    REQUIRE(tree.size() == 2);

    std::cout << "Top tests\n";
    HuffmanNode top = tree.top();
    REQUIRE(top.getLetter() == 'a');
    REQUIRE(top.getFrequency() == 1);

    std::cout << "Pop tests\n";
    tree.pop();
    REQUIRE(tree.size() == 1);
    tree.pop();
    REQUIRE(tree.size() == 0);

    std::cout << "Tree build tests\n";
    std::string input = "abb";
    //      (3)
    //     /   \
    //   (a-1) (b-2)

    std::unordered_map<char, std::string> encoding;
    std::unordered_map<std::string, char> reverse_encoding;
    std::unordered_map<char, int> key_value_pairs = {};

    REQUIRE(check_key('a', key_value_pairs) == false);

    for (int i = 0; i < input.size(); i++) {
        if (check_key(input[i], key_value_pairs)) {
            key_value_pairs[input[i]]++;
        } else {
            key_value_pairs[input[i]] = 1;
        }
    }
    tree.build_tree(key_value_pairs);
    REQUIRE(tree.size() == 1);

    HuffmanNode combo = tree.top();
    REQUIRE(combo.getFrequency() == 3);
    REQUIRE(combo.getLetter() == '\0');
    REQUIRE((combo.left)->getLetter() == 'a');
    REQUIRE((combo.left)->getFrequency() == 1);
    REQUIRE((combo.right)->getLetter() == 'b');
    REQUIRE((combo.right)->getFrequency() == 2);

    std::cout << "Encoding tests\n";
    tree.encode(combo, "", encoding, reverse_encoding);

    REQUIRE(encoding['a'] == "0");
    REQUIRE(encoding['b'] == "1");
    REQUIRE(reverse_encoding["0"] == 'a');
    REQUIRE(reverse_encoding["1"] == 'b');

    std::cout << "Decoding tests\n";
    std::string binary = "011";  
    std::string decoded = tree.decode(binary, reverse_encoding);
    REQUIRE(decoded == "abb");

    std::cout << "Copy constructor tests\n";
    HuffmanTree copied_tree = tree;
    REQUIRE(copied_tree.size() == 1);
    HuffmanNode copy_combo = tree.top();
    REQUIRE(copy_combo.getFrequency() == 3);
    REQUIRE(copy_combo.getLetter() == '\0');
    REQUIRE((copy_combo.left)->getLetter() == 'a');
    REQUIRE((copy_combo.left)->getFrequency() == 1);
    REQUIRE((copy_combo.right)->getLetter() == 'b');
    REQUIRE((copy_combo.right)->getFrequency() == 2);

    combo = tree.top();
    REQUIRE(combo.getFrequency() == 3);
    REQUIRE(combo.getLetter() == '\0');
    REQUIRE((combo.left)->getLetter() == 'a');
    REQUIRE((combo.left)->getFrequency() == 1);
    REQUIRE((combo.right)->getLetter() == 'b');
    REQUIRE((combo.right)->getFrequency() == 2);

    std::cout << "Copy assignment tests\n";
    HuffmanTree new_tree;
    // is this correct?
    new_tree = tree;
    REQUIRE(new_tree.size() == 1);

    copy_combo = new_tree.top();
    REQUIRE(copy_combo.getFrequency() == 3);
    REQUIRE(copy_combo.getLetter() == '\0');
    REQUIRE((copy_combo.left)->getLetter() == 'a');
    REQUIRE((copy_combo.left)->getFrequency() == 1);
    REQUIRE((copy_combo.right)->getLetter() == 'b');
    REQUIRE((copy_combo.right)->getFrequency() == 2);

    combo = tree.top();
    REQUIRE(combo.getFrequency() == 3);
    REQUIRE(combo.getLetter() == '\0');
    REQUIRE((combo.left)->getLetter() == 'a');
    REQUIRE((combo.left)->getFrequency() == 1);
    REQUIRE((combo.right)->getLetter() == 'b');
    REQUIRE((combo.right)->getFrequency() == 2);

    std::cout << "Move constructor tests\n";
    //TODO
    
    std::cout << "Move assignment tests\n";
    //TODO
}
