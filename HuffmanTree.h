#ifndef HuffmanTree_H
#define HuffmanTree_H

#include <memory>
#include <queue>
#include <string>
#include <unordered_map>
#include "HuffmanNode.h"

class HuffmanTree {
    std::priority_queue<HuffmanNode, std::vector<HuffmanNode>, Compare> huffman_tree;
    public:
        HuffmanTree();                                      // default constructor
        HuffmanTree(const HuffmanTree& tree);               // copy constructor
        HuffmanTree& operator= (const HuffmanTree& tree);   // copy assignment
        HuffmanTree(HuffmanTree&& tree);                    // move constructor
        HuffmanTree& operator=(HuffmanTree&& tree);         // move assignment
        ~HuffmanTree();                                     // destructor

        void push(HuffmanNode &node);
        HuffmanNode top();
        void pop();
        int size();

        void build_tree(std::unordered_map<char, int> &key_value_pairs);
        void print_inorder(HuffmanNode &root);

        void encode(HuffmanNode &root, std::string str, std::unordered_map<char, std::string> &encoding, std::unordered_map<std::string, char> &reverse_encoding);
        std::string decode(std::string &binary, std::unordered_map<std::string, char>  &reverse_encoding);
};

#endif
