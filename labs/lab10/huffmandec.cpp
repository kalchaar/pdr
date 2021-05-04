// Keenan Alchaar | ka5nt | 04/30/2021 | huffmandec.cpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <map>
#include "HuffmanNode.h"
using namespace std;

map<string, char> prefixCodes;
void buildTree(HuffmanNode* root, string path);
string decodeBits(HuffmanNode* root, string encodedBits);
string decoded = "";

int main (int argc, char** argv) {
  if (argc != 2) {
    cout << "Must supply the input file name as the only parameter" << endl;
    exit(1);
  }

  ifstream file(argv[1], ifstream::binary);
  HuffmanNode* root = new HuffmanNode();

  if (!file.is_open()) {
    cout << "Unable to open file" << endl;
  }

  while (true) {
    string character;
    string prefix;
    file >> character;

    if (character[0] == '-' && character.length() > 1) {
      break;
    }

    if (character == "space") {
      character = " ";
    }

    file >> prefix;

    prefixCodes[prefix] = character[0];
    
  }

  buildTree(root, "");
  stringstream sstm;

  while (true) {
    string bits;
    
    file >> bits;

    if (bits[0] == '-') {
      break;
    }

    sstm << bits;
  }
  string allbits = sstm.str();
  
  cout << decodeBits(root, allbits) << endl;
  return 0;
}

void buildTree(HuffmanNode* root, string path) {
  if (prefixCodes.find(path) != prefixCodes.end()) {
    root->chr = prefixCodes[path];
  } else {
    HuffmanNode* left = new HuffmanNode();
    HuffmanNode* right = new HuffmanNode();;
    root->left = left;
    root->right = right;
    buildTree(left, path + "0");
    buildTree(right, path + "1");
  }
}

string decodeBits(HuffmanNode* root, string encodedBits) {
  string decodedBits = "";
  HuffmanNode* current = root;
  for (int i = 0; i < encodedBits.size(); i++) {
    if (encodedBits[i] == '0') {
      current = current->left;
    } else {
      current = current->right;
    }

    if (current->left == NULL && current->right == NULL) {
      decodedBits.push_back(current->chr);
      current = root;
    }
  }
  return decodedBits;
}
