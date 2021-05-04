// Keenan Alchaar | ka5nt | 04/27/2021 | heap.h
// Modified from code provided by Aaron Bloomfield

#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <vector>
#include <string>
#include "HuffmanNode.h"
using namespace std;

class binary_heap {
public:
    binary_heap();
    binary_heap(vector<HuffmanNode*> vec);
    ~binary_heap();

    void insert(HuffmanNode* n);
    HuffmanNode* findMin();
    HuffmanNode* deleteMin();
    unsigned int size();
    void makeEmpty();
    bool isEmpty();
    void print();

private:
    vector<HuffmanNode*> heap;
    unsigned int heap_size;

    void percolateUp(int hole);
    void percolateDown(int hole);
};

#endif
