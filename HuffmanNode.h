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

// This class is needed to compare two HuffmanNodes
class Compare {
    public:
        int operator() (const HuffmanNode &a, const HuffmanNode &b){
            return a.getFrequency() > b.getFrequency();
        }
};

#endif
