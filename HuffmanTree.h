#ifndef HuffmanTree_H
#define HuffmanTree_H

#include <memory>
#include <string>
#include <unordered_map>
#include "HuffmanNode.h"

// This class is needed to compare two HuffmanNodes
class Compare {
    public:
        int operator() (const HuffmanNode &a, const HuffmanNode &b){
            return a.getFrequency() > b.getFrequency();
        }
};

class HuffmanTree {
    std::priority_queue<HuffmanNode, std::vector<HuffmanNode>, Compare> huffman_tree;
    public:
        HuffmanTree();
        ~HuffmanTree();

        void push(HuffmanNode &node);
        HuffmanNode top();
        void pop();
        int size();

        void print_inorder(HuffmanNode &root);

        void encode(HuffmanNode &root, std::string str, std::unordered_map<char, std::string> &encoding, std::unordered_map<std::string, char> &reverse_encoding);
        std::string decode(std::string &binary, std::unordered_map<std::string, char>  &reverse_encoding);
};

#endif
