// Keenan Alchaar | ka5nt | 03/16/2021 | prelab4.cpp

#include <iostream>
using namespace std;

void sizeOfTest() {
  cout << "Size of int: " << sizeof(int) << endl;
  cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
  cout << "Size of float: " << sizeof(float) << endl;
  cout << "Size of double: " << sizeof(double) << endl;
  cout << "Size of char: " << sizeof(char) << endl;
  cout << "Size of bool: " << sizeof(bool) << endl;
  cout << "Size of int*: " << sizeof(int*) << endl;
  cout << "Size of char*: " << sizeof(char*) << endl;
  cout << "Size of double*: " << sizeof(double*) << endl;
}

void overflow() {
  unsigned int i = 4294967295;
  cout << i << " + 1 = " << i+1 << endl;
}

void outputBinary(unsigned int i) {
  unsigned int q = i;
  unsigned int r;
  
  unsigned int binaryRep[31];
  for (int k = 0; k < 31; k++) {
    binaryRep[k] = 0;
  }
  
  int count = 31;
  while (q != 0) {
    r = q % 2;
    q = q / 2;
    if (r == 0) {
      binaryRep[count] = 0;
    } else {
      binaryRep[count] = 1;
    }
    count--;
  }
  
  for (int k = 0; k < 8; k++) {
    cout << binaryRep[4*k] << binaryRep[4*k+1] << binaryRep[4*k+2] <<  binaryRep[4*k+3] << " ";
  }
  cout << endl;
}

int main() {
  unsigned int x;
  cin >> x;
  sizeOfTest();
  overflow();
  outputBinary(x);
  return 0;
}
