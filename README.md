Welcome to the readme.

### Instructions

1. Run ```make``` to build the executable. 
2. Run ./\<executable> \<inputFile.txt> \<outputName> to build the Huffman
   encoding. Please provide a simple output name - the program will build a
   corresponding output.txt and output.hdr
3. Please make sure your \<inputFile.txt> ends with a newline

### Tests

Run ```make tests``` to run all unit tests.

Individual tests can be found in all files with the suffix '_tests.cpp'

### Files

The HuffmanNode class is responsible for representing nodes within the tree.
Each node has a letter, a frequency and two smart pointers assosciated with it
(pointing to the left and right links respectively).

The HuffmanTree class is responsible for representing a tree structure. It
makes use of priority queue. The tree can be encoded, decoded or simply printed
(an inorder print). A variety of wrappers for the priority queue have been
implemented to allow for pushing, popping, etc. The tree class also includes
methods to build, the tree, encode the tree and decode some binary string.

The driver.cpp file is responsible for reading the input file, generating the
HuffmanTree, generating the corresponding huffman pairs, encoding the input,
outputting the output files (writing out the corresponding headers and binary
files).

The driver class outputs 4 files:

1. \<output>.hdr
2. \<output>.txt
3. \<output>_bitstream.hdr
4. \<output>_bitstream.txt 

The first two files are the Huffman encoding pairs and the Huffamn encoding as a binary
string.
The second two files represent the true compression - the header file
represents the number of bits, and the .txt file contains the actual bitstream
encoded as a series of bytes.
