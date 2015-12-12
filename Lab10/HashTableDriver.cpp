// Lab 10, Write, Test and Apply The HashTable Class Template
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)
#include <iostream> // for cout and endl
#include <string> // for string
using namespace std;

#include <cassert> // for assert
#include <fstream> // for ifstream

#include <vector>
#include <list> // for the list itself
#include <algorithm> // for searching the list

#include "HashTable.h"
#include "HashTable.h" // testing ifnsdef

int convertStrToInt (const string& str)
{
  char strPtr[20];
  int str_Int = 0;
  strcpy(strPtr, str.c_str());
  for (int i = 0; i < 20; i++) {
    str_Int  += atoi(&strPtr[i]);
  }
  return str_Int;
}

int main()
{
  // print my name and this assignment's title
  cout << "Lab 10, Write, Test and Apply The HashTable Class Template\n";
  cout << "Programmer: Kwun Hang Chan\n";
  cout << "Editor(s) used: Xcode\n";
  cout << "Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  cout << "Create a Associative Array, b, storing int value with string key" << endl;
  HashTable<int, string, 1009> b (convertStrToInt);
  cout << "Expected size of b: 0" << endl;
  cout << "Actual size of b: " << b.size() << endl << endl;
  assert( b.size()==0 );

  
  cout << "b[One] = 1, b[Two] = 2, b[Three] = 3, b[Four] = 4;" << endl;
  b["One"] = 1; b["Two"] = 2; b["Three"] = 3; b["Four"] = 4;
  
  cout << "Expected size of b: 4" << endl;
  cout << "Actual size of b: " << b.size() << endl << endl;
  assert( b.size() == 4 );

  cout << "Set b[One] = 3; " << endl;
  b["One"] = 3;
  cout << "Expected: b[One] = 3 " << endl << "Actual: ";
  cout << "b[One] = " << b["One"] << endl << endl;
  
  cout << "Delete b[One]" << endl;
  b.deleteKey("One");
  cout << "Expected size of b: 3 " << endl;
  cout << "Actual size of b: " << b.size() << endl << endl;
  assert( b.size()==3 );

  {
    cout << "Create a copy, c, to test getter function." << endl;
    HashTable<int, string, 1009> c = b;
    cout << "Expected size of c: 3" << endl;
    cout << "Actual size of c: " << c.size() << endl;
    cout << "Expected c[Two] = 2" << endl << "Actual: ";
    cout << "c[Two] = " << c["Two"] << endl << endl;
  }
  
  {
    cout << "Create an assocaite array, d, to test = operator." << endl;
    HashTable<int, string, 1009> d(convertStrToInt);
    d = b;
    cout << "Expected size of d: 4" << endl;
    cout << "Actual size of d: " << d.size() << endl;
    cout << "Expected d[Three] = 3, d[Four] = 4" << endl << "Actual: ";
    cout << "d[Three] = " << d["Three"] << " ";
    cout << "d[Four] = " << d["Four"] << endl << endl;
  }
  
  cout << "Testing vector to get keys from b" << endl;
  cout << "Expected: b[Two] = 2 b[Three] = 3 b[Four] = 4" << endl << "Actual: ";
  vector<string> keys = b.keys();
  for (int i = 0; i < keys.size(); i++)
    cout << "b[" << keys[i] << "] = " << b[keys[i]] << " ";
  cout << endl << endl;
  
  cout << "Clear b." << endl;
  b.clear();
  cout << "Expected size of b: 0" << endl;
  cout << "Actual size of b: " << b.size() << endl << endl;
  assert( b.size()==0 );
}