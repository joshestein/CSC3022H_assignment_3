Welcome to the readme.

### Instructions

1. Run ```make``` to build the executable. 
2. Run ./\<executable> \<inputFile.txt> \<outputName> to build the Huffman
   encoding. Please provide a simple output name - the program will build a
   corresponding output.txt and output.hdr

### Tests

Run ```make tests``` to run all unit tests.

### Files

The HuffmanNode class is responsible for representing nodes within the tree.
Each node has a letter, a frequency and two smart pointers assosciated with it. 

The HuffmanTree class is responsible for representing a tree structure. It
makes use of priority queue. The tree can be encoded, decoded or simply printed
(an inorder print). A variety of wrappers for the priority queue have been
implemented to allow for pushing, popping, etc.

The driver.cpp file is responsible for reading the input file, generating the
HuffmanTree, generating the corresponding encoding and outputting the output
files. 
