#ifndef HuffmanNode_H
#define HuffmanNode_H

#include <memory>

class HuffmanNode {
    private:
        char letter;
        int frequency;

    public:
        std::shared_ptr<HuffmanNode> left;
        std::shared_ptr<HuffmanNode> right;
        HuffmanNode(char letter, int frequency);
        ~HuffmanNode();
        int getFrequency() const;
        char getLetter() const;
};

#endif
