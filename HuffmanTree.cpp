#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include "HuffmanTree.h"

// default constructor
HuffmanTree::HuffmanTree(void) {
    std::cout << "Tree being created\n";
}

// copy constructor
HuffmanTree::HuffmanTree(const HuffmanTree& tree): huffman_tree(tree.huffman_tree) {
}

// copy assignment
HuffmanTree& HuffmanTree::operator= (const HuffmanTree& tree) {
    huffman_tree = tree.huffman_tree;
}

// move constructor
HuffmanTree::HuffmanTree(HuffmanTree&& tree): huffman_tree(tree.huffman_tree) {
    // reset tree 
    tree.huffman_tree = std::priority_queue<HuffmanNode, std::vector<HuffmanNode>, Compare> ();
}

// move assignment
HuffmanTree& HuffmanTree::operator=(HuffmanTree&& tree) {
    huffman_tree = tree.huffman_tree;
    tree.huffman_tree = std::priority_queue<HuffmanNode, std::vector<HuffmanNode>, Compare> ();
}

// destructor
HuffmanTree::~HuffmanTree() {
}

void HuffmanTree::push(HuffmanNode &node){
    huffman_tree.push(node);
}

HuffmanNode HuffmanTree::top(){
    if (!huffman_tree.empty()) {
        return huffman_tree.top();
    }
}

void HuffmanTree::pop(){
    huffman_tree.pop();
}

int HuffmanTree::size() {
    return huffman_tree.size();
}

void HuffmanTree::print_inorder(HuffmanNode &root) {
    if (root.left == nullptr && root.right == nullptr) {
        std::cout << root.getLetter() << ": " << root.getFrequency() << "\n";
    } else {
        if (root.left != nullptr) {
            print_inorder(*(root.left));
        }
        if (root.right != nullptr) {
            print_inorder(*(root.right));
        }
    }
}

void HuffmanTree::encode(HuffmanNode &root, std::string str, std::unordered_map<char, std::string> &encoding, std::unordered_map<std::string, char> &reverse_encoding) {
    if (root.left == nullptr && root.right == nullptr) {
        encoding[root.getLetter()] = str;
        reverse_encoding[str] = root.getLetter();
        return;
    } else {
        if (root.left != nullptr) {
            encode(*(root.left), str+"0", encoding, reverse_encoding);
        }
        if (root.right != nullptr) {
            encode(*(root.right), str+"1", encoding, reverse_encoding);
        }
    }
}

std::string HuffmanTree::decode(std::string &binary, std::unordered_map<std::string, char> &reverse_encoding){
    std::string digit_sequence;
    std::string output;
    for (int i = 0; i < binary.size(); i++) {
        digit_sequence += binary[i];
        if (reverse_encoding[digit_sequence]) {
            output += reverse_encoding[digit_sequence];
            digit_sequence = "";
        }
    }
    return output;
}
