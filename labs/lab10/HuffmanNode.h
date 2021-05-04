// Keenan Alchaar | ka5nt | 04/27/2021 | HuffmanNode.h

#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H
#include <string>
using namespace std;

class HuffmanNode {
 public:
  HuffmanNode();
  HuffmanNode(char character, int frequency);
  ~HuffmanNode();

  unsigned char chr;
  unsigned int freq;
  HuffmanNode* left;
  HuffmanNode* right;

  friend class heap;
};

#endif
