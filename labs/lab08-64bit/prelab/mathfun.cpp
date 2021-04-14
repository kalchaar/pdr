// Keenan Alchaar | ka5nt | 04/13/2021 | mathfun.cpp
#include <iostream>
using namespace std;
extern "C" long product(long x, long y);
extern "C" long power(long x, long y);

int main() {
  long x;
  long y;
  cout << "Enter integer 1: " << endl;
  cin >> x;
  cout << "Enter integer 2: " << endl;
  cin >> y;
  cout << "Product: " << product(x, y) << endl;
  cout << "Power: " << power(x, y) << endl;
  return 0;
}
