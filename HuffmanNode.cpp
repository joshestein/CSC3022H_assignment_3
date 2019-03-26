#include "HuffmanNode.h"
#include <iostream>

// default constructor
HuffmanNode::HuffmanNode(): letter('\0'), frequency(0) {};

// parameterized constructor
HuffmanNode::HuffmanNode(char letter, int frequency): letter(letter), frequency(frequency), left(nullptr), right(nullptr) {
    //std::cout << "Node being created\n";
}

/*
HuffmanNode::HuffmanNode(char letter, int frequency, HuffmanNode &pLeft, HuffmanNode &pRight): letter(letter), frequency(frequency) {
    //std::cout << "Node being created\n";
    left(new HuffmanNode(pLeft));
    right(new HuffmanNode(pRight));
}
*/

// copy constructor
HuffmanNode::HuffmanNode(const HuffmanNode& node): letter(node.letter), frequency(node.frequency), left(node.left), right(node.right) {
}

// copy assignment
HuffmanNode& HuffmanNode::operator= (const HuffmanNode& node){
    letter = node.letter;
    frequency = node.frequency;
    left = node.left;
    right = node.right;
}

// move constructor
HuffmanNode::HuffmanNode(HuffmanNode&& node): letter(node.letter), frequency(node.frequency), left(std::move(node.left)), right(std::move(node.right)){
    node.letter = '\0';
    node.frequency = -1;
}

// move assignment
HuffmanNode& HuffmanNode::operator= (HuffmanNode&& node) {
    if (this != & node) {
        letter = node.letter;
        frequency = node.frequency;
        left = std::move(node.left);
        right = std::move(node.right);
        node.letter = '\0';
        node.frequency = -1;
    }
    return *this;
}
 
// destructor
HuffmanNode::~HuffmanNode() {
    //std::cout << "Node being destroyed\n";
}

int HuffmanNode::getFrequency() const{
    return frequency;
}

char HuffmanNode::getLetter() const{
    return letter;
}
