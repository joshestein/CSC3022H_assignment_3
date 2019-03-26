#include "catch.hpp"
#include "HuffmanNode.h"
#include <iostream>

TEST_CASE("HuffmanNode tests", "[HuffmanNode]") {
    std::cout << "Default constructor tests\n";
    HuffmanNode node;
    REQUIRE(node.getFrequency() == 0);
    REQUIRE(node.getLetter() == '\0');
    REQUIRE(node.left == nullptr);
    REQUIRE(node.right == nullptr);
}


