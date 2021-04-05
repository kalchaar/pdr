// Keenan Alchaar | ka5nt | 04/02/2021 | hashTable.cpp

#include "hashTable.h"
#include <string>
#include <list>
#include <vector>
#include <iostream>
using namespace std;

hashTable::hashTable(unsigned int tableSizeA) {
  table.resize(tableSizeA);
  tableSize = tableSizeA;
}

void hashTable::insert(string s) {
  unsigned int hashVal = hashStr(s, tableSize);
  while(table.at(hashVal) != "") {
    hashVal++;
    hashVal = hashVal % tableSize;
  }
  table.at(hashVal) = s;
}

bool hashTable::find(string s) {
  unsigned int hashVal = hashStr(s, tableSize);
  if (table.at(hashVal) == s) {
    return true;
  }
  while (table.at(hashVal) != s && table.at(hashVal) != "") {
    hashVal++;
    hashVal = hashVal % tableSize;
    if (table.at(hashVal) == s) {
      return true;
    }
  }
  return false;
}

void hashTable::printTable() {
  for (vector<string>::iterator it = table.begin(); it != table.end(); it++) {
    cout << *it << endl;
  }
  cout << table.size() << endl;
}

unsigned int hashStr(string s, unsigned int mod) {
  unsigned int hash = 0;
  for (int i = 0; i < s.length(); i++) {
    hash += s[i]*power(23,i);
  }
  return hash % mod;
}

unsigned int power(int n, int power) { 
  if (power == 0) {
    return 1;
  }
  int temp = n;
  for (int i = 0; i < power - 1; i++) {
    temp = temp*n;
  }
  return temp;
}
