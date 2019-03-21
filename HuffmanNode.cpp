#include "HuffmanNode.h"
#include <iostream>

HuffmanNode::HuffmanNode(char letter, int frequency): letter(letter), frequency(frequency) {
    std::cout << "Node being created\n";
};

HuffmanNode::~HuffmanNode() {
    std::cout << "Node being destroyed\n";
}

int HuffmanNode::getFrequency() {
    return frequency;
}
