#include "catch.hpp"
#include "HuffmanTree.h"
#include <iostream>


TEST_CASE("HuffmanTree tests", "[HuffmanTree]") {
    std::cout << "HUFFMAN_TREE TESTS\n";
    std::cout << "---------------------\n";
    std::cout << "Default constructor tests\n";

    HuffmanTree tree;
    REQUIRE(tree.size() == 0);
}
