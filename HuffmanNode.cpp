#include "HuffmanNode.h"
#include <iostream>

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

HuffmanNode::~HuffmanNode() {
    //std::cout << "Node being destroyed\n";
}

int HuffmanNode::getFrequency() const{
    return frequency;
}

char HuffmanNode::getLetter() const{
    return letter;
}
