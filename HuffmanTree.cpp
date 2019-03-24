#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include "HuffmanTree.h"

HuffmanTree::HuffmanTree(void) {
    std::cout << "Tree being created\n";
}

HuffmanTree::~HuffmanTree() {
}

void HuffmanTree::push(HuffmanNode &node){
    huffman_tree.push(node);
}

HuffmanNode HuffmanTree::top(){
    return huffman_tree.top();
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

void HuffmanTree::encode(HuffmanNode &root, std::string str, std::unordered_map<char, std::string> &encoding) {
    if (root.left == nullptr && root.right == nullptr) {
        encoding[root.getLetter()] = str;
        return;
    } else {
        if (root.left != nullptr) {
            encode(*(root.left), str+"0", encoding);
        }
        if (root.right != nullptr) {
            encode(*(root.right), str+"1", encoding);
        }
    }
}

void HuffmanTree::decode() {
}
