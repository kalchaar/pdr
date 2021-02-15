// Keenan Alchaar | ka5nt | 02/15/21 | xToN.cpp
#include <iostream>
using namespace std;
int xton(int base, int exp) {
  if (exp == 0) {
    return 1;
  } else {
    return base*xton(base, exp-1);
  }
}

int main () {
  int x, y, z;
  cin >> x;
  cin >> y;
  z = xton(x,y);
  cout << z << endl;
  return 0;
}
