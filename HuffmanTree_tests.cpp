#include "catch.hpp"
#include "HuffmanTree.h"
#include "HuffmanNode.h"
#include <iostream>


TEST_CASE("HuffmanTree tests", "[HuffmanTree]") {
    std::cout << "HUFFMAN_TREE TESTS\n";
    std::cout << "---------------------\n";
    std::cout << "Default constructor tests\n";

    HuffmanTree tree;
    REQUIRE(tree.size() == 0);

    std::cout << "Push tests\n";
    HuffmanNode node('a', 100);
    HuffmanNode node2('b', 200);
    tree.push(node);
    REQUIRE(tree.size() == 1);
    tree.push(node2);
    REQUIRE(tree.size() == 2);

    std::cout << "Top tests\n";
    HuffmanNode top = tree.top();
    REQUIRE(top.getLetter() == 'a');
    REQUIRE(top.getFrequency() == 100);

    std::cout << "Pop tests\n";
    tree.pop();
    REQUIRE(tree.size() == 1);
    tree.pop();
    REQUIRE(tree.size() == 0);
}
