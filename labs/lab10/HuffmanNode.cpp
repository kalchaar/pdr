// Keenan Alchaar | ka5nt | 04/27/2021 | HuffmanNode.cpp

#include "HuffmanNode.h"
#include <string>
using namespace std;

HuffmanNode::HuffmanNode() {
  chr = 0;  // char
  freq = 0; // int
  left = NULL;
  right = NULL;
}

HuffmanNode::HuffmanNode(char character, int frequency) {
  chr = character;
  freq = frequency;
  left = NULL;
  right = NULL;
}

HuffmanNode::~HuffmanNode() {
  delete left;
  delete right;
  left = NULL;
  right = NULL;
}
