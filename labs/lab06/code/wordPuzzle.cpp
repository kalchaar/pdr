// Keenan Alchaar | ka5nt | 04/02/2021 | wordPuzzle.cpp

#include <unordered_set>
#include <iostream>
#include <fstream>
#include <string>
#include "hashTable.h"
#include "timer.h"
using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

bool readInGrid(string filename, int& rows, int& cols);
string getWordInGrid(int startRow, int startCol, int dir, int len,
                     int numRows, int numCols);
hashTable readInDictionary(string filename, hashTable dictionaryA);
string getDir(int dir);
int max(int a, int b);
bool checkprime(unsigned int p);
int getNextPrime (unsigned int n);
unsigned int readInDictionarySize(string filename);

int main(int argc, char* argv[]) {
  int rows, cols;
  // timer t;
  string dictFile(argv[1]);
  string gridFile(argv[2]);
  int validWords = 0;
  int numWords = readInDictionarySize(dictFile);
  hashTable dictionary(getNextPrime(numWords*2));
  vector<string> output;
  dictionary = readInDictionary(dictFile, dictionary);
  readInGrid(gridFile, rows, cols);
  // t.start();
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      for (int d = 0; d <= 7; d++) {
	for (int l = 3; l <= 22; l++) {
	  string word = getWordInGrid(r, c, d, l, rows, cols);
	  if (word.size() == l && dictionary.find(word)) {
	    output.push_back(getDir(d) + " (" + to_string(r) + ", " + to_string(c) + "): " + word);
	    validWords++;
	  }
	}
      }
    }
  }
  // t.stop();
  for (int i = 0; i < output.size(); i++) {
    cout << output.at(i) << endl;
  }
  cout << validWords << " words found" << endl;
  // cout <<  t.getTime()*1000 << endl;
  return 0;
}

hashTable readInDictionary(string filename, hashTable dictionaryA) {
  string line;
  ifstream file(filename);
  if (!file.is_open()) {
    cout << "File not found" << endl;
    return dictionaryA;
  }
  while (getline(file,line)) {
    dictionaryA.insert(line);
  }
  file.close();
  return dictionaryA;
  // string words;
  // file >> words;
  
}

/** This function will read in a grid file, as per the format in the
 * CS 2150 lab 6 document, into a global grid[][] array.  It uses C++
 * file streams, and thus requires the the <fstream> #include header.
 *
 * @return true or false, depending on whether the file was
 *         successfully opened.
 * @param filename The file name to read in -- it's assumed to be in
 *                 the file format described in the lab document.
 * @param rows The number of rows as specified in the input file;
 *             as this is a reference, it is set by the function.
 * @param cols The number of columns as specified in the input file;
 *             as this is a reference, it is set by the function.
 */
bool readInGrid(string filename, int& rows, int& cols) {
    // try to open the file
    ifstream file(filename);
    // upon an error, return false
    if (!file.is_open()) {
        return false;
    }

    // first comes the number of rows
    file >> rows;

    // then the columns
    file >> cols;

    // and finally the grid itself
    string data;
    file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[pos++];
        }
    }
    return true;
}

/** This function will retrieve a word in a grid of letters in a given
 * direction.  If the end of the grid is encountered before the length
 * of the desired string is reached, then a shorter string will be
 * returned.  The data is retrieved from a global char grid[][]
 * array, which is assumed to be defined (and in scope).  NOTE: The
 * return value is a static string variable (for efficiency
 * reasons), so a successive return value will overwrite a previous
 * return value.
 *
 * @return A STATIC string containing the letters in the provided direction.
 * @param startRow The starting (row,col) position to find the word.
 * @param startCol The starting (row,col) position to find the word.
 * @param dir The direction to move: 0 is north (upwards), 1 is
 *            northeast, and it rotates around clockwise until it
 *            reaches 7 for northwest.
 * @param len The desired length of the string to return (assuming
 *            the edge of the grid is not reached--if the edge of the
 *            grid is reached, it will return as many characters as
 *            possible up to the edge of the grid, so the returned
 *            string may not have the same length as this parameter
 *            indicates).
 * @param numRows The number of rows in the global char grid[][]
 *                array.
 * @param numCols The number of columns in the global char grid[][]
 *                array.
 */
string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static string output;
    output.clear(); // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
            break;
        }

        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];

        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }

    return output;
}

int max(int a, int b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

string getDir(int dir) {
  if (dir == 0) {
    return "N ";
  } else if (dir == 1) {
    return "NE";
  } else if (dir == 2) {
    return "E ";
  } else if (dir == 3) {
    return "SE";
  } else if (dir == 4) {
    return "S ";
  } else if (dir == 5) {
    return "SW";
  } else if (dir == 6) {
    return "W ";
  } else if (dir == 7) {
    return "NW";
  }
  return "";
}

bool checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}

unsigned int readInDictionarySize(string filename) {
  string line;
  ifstream file(filename);
  if (!file.is_open()) {
    return 0;
  }
  unsigned int temp = 0;
  while (getline(file,line)) {
    temp++;
  }
  file.close();
  return temp;
}
