#ifndef HuffmanNode_H
#define HuffmanNode_H

class HuffmanNode {
    private:
        char letter;
        int frequency;

    public:
        HuffmanNode *left, *right;
        HuffmanNode(char letter, int frequency);
        HuffmanNode(char letter, int frequency, HuffmanNode &left, HuffmanNode &right);
        ~HuffmanNode();
        int getFrequency() const;
        char getLetter() const;
};

#endif
