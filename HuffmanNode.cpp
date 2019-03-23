#include "HuffmanNode.h"
#include <iostream>

HuffmanNode::HuffmanNode(char letter, int frequency): letter(letter), frequency(frequency) {
    //std::cout << "Node being created\n";
}

HuffmanNode::HuffmanNode(char letter, int frequency, HuffmanNode &left, HuffmanNode &right): letter(letter), frequency(frequency), left(&left), right(&right) {
    //std::cout << "Node being created\n";
}

HuffmanNode::~HuffmanNode() {
    //std::cout << "Node being destroyed\n";
}

int HuffmanNode::getFrequency() const{
    return frequency;
}

char HuffmanNode::getLetter() const{
    return letter;
}
