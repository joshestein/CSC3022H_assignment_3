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
        HuffmanNode();                                       // Default constructor
        HuffmanNode(char letter, int frequency);             // Parameterized constructor
        HuffmanNode(const HuffmanNode& node);                // Copy constructor
        HuffmanNode& operator= (const HuffmanNode& node);    // Copy assignment
        HuffmanNode(HuffmanNode&& node);                     // Move constructor
        HuffmanNode& operator= (HuffmanNode&& node);         // Move assignment
        ~HuffmanNode();                                      // Destructor
        int getFrequency() const;
        char getLetter() const;
};

#endif
