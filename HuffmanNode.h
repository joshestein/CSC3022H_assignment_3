#ifndef HuffmanNode_H
#define HuffmanNode_H

class HuffmanNode {
    private:
        char letter;
        int frequency;
        HuffmanNode *left, *right;
    public:
        HuffmanNode(char letter, int frequency);
        ~HuffmanNode();
        int getFrequency();
};

#endif
