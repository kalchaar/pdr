// Keenan Alchaar | ka5nt | 04/27/2021 | huffmanenc.cpp
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unordered_map>
#include "HuffmanNode.h"
#include "heap.h"
using namespace std;

void findEncoding(HuffmanNode* node, string path);
int* countFreq(int freq[], string filename);
string encodeText(string filename);
int lenExcludeSpace(string s);
unordered_map<char, string> encodingMap;

int main(int argc, char** argv) {
  int freq[256];
  
  for (int i = 0; i < 256; i++) {
    freq[i] = 0;
  }
  
  int* freqOut = countFreq(freq, argv[1]);
  binary_heap huffmanHeap;
  
  for (int i = 0; i < 256; i++) {
    if (freqOut[i] == 0) {
      continue;
    } else {
      HuffmanNode* n = new HuffmanNode((char) i, freq[i]);
      huffmanHeap.insert(n);
    }
  }
  
  while (huffmanHeap.size() != 1) {
    HuffmanNode* n1 = huffmanHeap.deleteMin();
    HuffmanNode* n2 = huffmanHeap.deleteMin();
    HuffmanNode* np = new HuffmanNode();
    np->left = n1;
    np->right = n2;
    np->freq = n1->freq + n2->freq;
    huffmanHeap.insert(np);
  }

  int totalSymbols = huffmanHeap.findMin()->freq;
  findEncoding(huffmanHeap.findMin(), "");
  string encodedText = encodeText(argv[1]);
  int distinctSymbols = encodingMap.size();
  int originalBits = 8*totalSymbols;
  int compressedBits = lenExcludeSpace(encodedText);
  double compressionRatio = (double) originalBits/ (double) compressedBits;
  double huffmanCost = (double) compressedBits/ (double) totalSymbols;
  cout << "----------------------------------------" << endl;
  cout << encodedText << endl;
  cout << "----------------------------------------" << endl;
  cout << "There are a total of " << totalSymbols << " symbols that are encoded." << endl;
  cout << "There are " << distinctSymbols << " distinct symbols used." << endl;
  cout << "There were " << originalBits << " bits in the original file." << endl;
  cout << "There were " << compressedBits << " bits in the compressed file." << endl;
  cout << "This gives a compression ratio of " << compressionRatio << "." << endl;
  cout << "The cost of the Huffman tree is " << huffmanCost << " bits per character." << endl;
  huffmanHeap.makeEmpty();
  return 0;
}

void findEncoding(HuffmanNode* node, string path) {
  if (node->left == NULL && node->right == NULL) {
    if (node->chr == 32) {
      cout << "space " << path << endl;
      encodingMap[node->chr] = path;
    } else {
      cout << node->chr << " " << path << endl;
      encodingMap[node->chr] = path;
    }
  } else {
    findEncoding(node->right, path + "1");
    findEncoding(node->left, path + "0");
  }
}

int* countFreq(int* freq, string filename) {
  ifstream file(filename);
  if(!file.is_open()) {
    cout << "Unable to open" << endl;
    exit(2);
  }
  char c;
  while(file.get(c)) {
    if ( (c < 32) || (c > 126) ) {
      continue;
    } else {
      freq[c]++;
    }
  }
  file.close();
  return freq;
}

string encodeText(string filename) {
  ifstream file(filename);
  if(!file.is_open()) {
    cout << "Unable to open" << endl;
    exit(2);
  }
  string s = "";
  char c;
  while(file.get(c)) {
    if ( (c < 32) || (c > 126) ) {
      continue;
    } else {
      s = s + encodingMap[c] + " ";
    }
  }
  return s;
}

int lenExcludeSpace(string s) {
  int ret = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 32) {
      continue;
    } else {
      ret++;
    }
  }
  return ret;
}
