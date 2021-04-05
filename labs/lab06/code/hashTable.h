#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <list>
#include <vector>
using namespace std;

class hashTable {
 public:
  hashTable(unsigned int tableSizeA);
  void insert(string s);
  bool find(string s);
  unsigned int power(int n, int power);
  void printTable();
 private:
  vector<string> table;
  unsigned int tableSize;
};

unsigned int hashStr(string s, unsigned int mod);
unsigned int power(int n, int power);

#endif
