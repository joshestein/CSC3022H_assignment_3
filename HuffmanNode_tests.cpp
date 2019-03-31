#include "catch.hpp"
#include "HuffmanNode.h"
#include <iostream>
#include <memory>

TEST_CASE("HuffmanNode tests", "[HuffmanNode]") {
    std::cout << "HUFFMAN_NODE TESTS\n";
    std::cout << "---------------------\n";
    std::cout << "Default constructor tests\n";
    HuffmanNode node;
    REQUIRE(node.getFrequency() == 0);
    REQUIRE(node.getLetter() == '\0');
    REQUIRE(node.left == nullptr);
    REQUIRE(node.right == nullptr);

    REQUIRE_FALSE(node.getFrequency() != 0);
    REQUIRE_FALSE(node.getLetter() != '\0');
    REQUIRE_FALSE(node.left != nullptr);
    REQUIRE_FALSE(node.right != nullptr);

    std::cout << "Paramterized constructor tests\n";
    //------------------------------------------------------//
    //------------------Paramterized constructor------------//
    HuffmanNode param_node('a', 25);
    //------------------------------------------------------//

    REQUIRE(param_node.getFrequency() == 25);
    REQUIRE(param_node.getLetter() == 'a');
    REQUIRE(param_node.left == nullptr);
    REQUIRE(param_node.right == nullptr);

    REQUIRE_FALSE(param_node.getFrequency() != 25);
    REQUIRE_FALSE(param_node.getLetter() != 'a');
    REQUIRE_FALSE(param_node.left != nullptr);
    REQUIRE_FALSE(param_node.right != nullptr);
    
    //------------------------------------------------------//
    //------------------Copy constructor--------------------//
    //------------------------------------------------------//
    std::cout << "Copy constructor tests\n";
    HuffmanNode copied_node = param_node;

    REQUIRE(param_node.getFrequency() == 25);
    REQUIRE(param_node.getLetter() == 'a');
    REQUIRE(param_node.left == nullptr);
    REQUIRE(param_node.right == nullptr);

    REQUIRE(copied_node.getFrequency() == 25);
    REQUIRE(copied_node.getLetter() == 'a');
    REQUIRE(copied_node.left == nullptr);
    REQUIRE(copied_node.right == nullptr);

    //------------------------------------------------------//
    //------------------Copy assignmnet---------------------//
    //------------------------------------------------------//
    std::cout << "Copy assignment tests\n";
    node = param_node;

    REQUIRE(param_node.getFrequency() == 25);
    REQUIRE(param_node.getLetter() == 'a');
    REQUIRE(param_node.left == nullptr);
    REQUIRE(param_node.right == nullptr);

    REQUIRE(node.getFrequency() == 25);
    REQUIRE(node.getLetter() == 'a');
    REQUIRE(node.left == nullptr);
    REQUIRE(node.right == nullptr);

    //------------------------------------------------------//
    //------------------Move constructor--------------------//
    //------------------------------------------------------//
    std::cout << "Move constructor tests\n";

    HuffmanNode move_node(std::move(param_node));
    REQUIRE(move_node.getFrequency() == 25);
    REQUIRE(move_node.getLetter() == 'a');
    REQUIRE(move_node.left == nullptr);
    REQUIRE(move_node.right == nullptr);

    REQUIRE(param_node.getFrequency() == -1);
    REQUIRE(param_node.getLetter() == '\0');
    REQUIRE(param_node.left == nullptr);
    REQUIRE(param_node.right == nullptr);

    //------------------------------------------------------//
    //------------------Move assignment---------------------//
    //------------------------------------------------------//
    std::cout << "Move assignment tests\n";
    HuffmanNode move_assign_node;
    move_assign_node = std::move(move_node);
    
    REQUIRE(move_assign_node.getFrequency() == 25);
    REQUIRE(move_assign_node.getLetter() == 'a');
    REQUIRE(move_assign_node.left == nullptr);
    REQUIRE(move_assign_node.right == nullptr);

    REQUIRE(move_node.getFrequency() == -1);
    REQUIRE(move_node.getLetter() == '\0');
    REQUIRE(move_node.left == nullptr);
    REQUIRE(move_node.right == nullptr);
    
    //------------------------------------------------------//
    //------------------Pointer tests-----------------------//
    //------------------------------------------------------//
    std::cout << "Pointer tests\n";

    std::shared_ptr<HuffmanNode> null_ptrNode;
    REQUIRE(null_ptrNode == nullptr);

    std::shared_ptr<HuffmanNode> ptrNode(std::make_shared<HuffmanNode>());
    REQUIRE_FALSE(ptrNode == nullptr);
    REQUIRE(ptrNode->getFrequency() == 0);
    REQUIRE(ptrNode->getLetter() == '\0');
    REQUIRE(ptrNode->left == nullptr);
    REQUIRE(ptrNode->right == nullptr);
    
    std::shared_ptr<HuffmanNode> ptrNode2(std::make_shared<HuffmanNode>('a', 100));
    REQUIRE_FALSE(ptrNode2 == nullptr);
    REQUIRE(ptrNode2->getFrequency() == 100);
    REQUIRE(ptrNode2->getLetter() == 'a');
    REQUIRE(ptrNode->left == nullptr);
    REQUIRE(ptrNode->right == nullptr);

    ptrNode->left = ptrNode2;
    REQUIRE_FALSE(ptrNode->left == nullptr);
    REQUIRE(ptrNode->right == nullptr);
    REQUIRE((ptrNode->left)->getFrequency() == 100);
    REQUIRE((ptrNode->left)->getLetter() == 'a');

    std::shared_ptr<HuffmanNode> ptrNode3(std::make_shared<HuffmanNode>('b', 25));
    ptrNode->right = ptrNode3;
    REQUIRE_FALSE(ptrNode->left == nullptr);
    REQUIRE_FALSE(ptrNode->right == nullptr);
    REQUIRE((ptrNode->right)->getFrequency() == 25);
    REQUIRE((ptrNode->right)->getLetter() == 'b');
    std::cout << "---------------------\n";

    //------------------------------------------------------//
    //------------------Node comparison---------------------//
    //------------------------------------------------------//
    HuffmanNode small('s', 1);
    HuffmanNode big('b', 100);
    //REQUIRE(big > small);
}


