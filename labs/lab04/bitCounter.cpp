// Keenan Alchaar | ka5nt | 03/19/2021 | bitCounter.cpp
#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
using namespace std;

string convertToBase10(string number, int startBase);

int bitCounter(int n) {
  if (n == 0) { // base case
    return 0;
  }
  if (n % 2 == 0) {
    return bitCounter(n / 2);
  } else {
    return 1 + bitCounter(n / 2);
  }
}

string baseConverter(string number, int startBase, int endBase) {
  string base10 = convertToBase10(number, startBase);
  int int2Char = 55;
  int q = stoi(base10);
  int r;
  string strNum = "";
  while (q != 0) {
    r = q % endBase;
    q = q / endBase;
    if (r >= 10) {
      r += int2Char; // if the remainder is to be represented as a letter convert it first
      strNum = (char)r + strNum; // letter case
    } else {
      strNum = to_string(r) + strNum; // number case
    }
  }
  return strNum;
}

string convertToBase10(string number, int startBase) {
  int numArray[number.length()];
  int charLetter2Int = 55;
  int charNumber2Int = 48;
  int convertedBase10 = 0;
  for (int i = 0; i < number.length(); i++) { // put the chars into an array as ints
    if (number[i] >= 65 && number[i] <= 90) { // for char capital letters 
      numArray[i] = (int)number[i] - charLetter2Int;
    } else if (number[i] >= 48 && number[i] <= 57) { // for char numbers
      numArray[i] = (int)number[i] - charNumber2Int; 
    }
    convertedBase10 += (numArray[i])*(pow(startBase, number.length() - i - 1));
  }
  return to_string(convertedBase10);
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    cout << "No command line parameters detected; exiting program" << endl;
    exit(1);
  }
  string s1(argv[1]);
  string s2(argv[2]);
  string s3(argv[3]);
  string s4(argv[4]);
  cout << s1 << " has " << bitCounter(stoi(s1)) << " bit(s)" << endl;
  cout << s2 << " (base " << s3 << ") = " << baseConverter(s2, stoi(s3), stoi(s4)) << " (base " << s4 << ")" << endl;
  return 0;
}
