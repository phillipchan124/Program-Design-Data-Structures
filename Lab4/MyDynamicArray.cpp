// Lab 4b, Write A Dynamic Array Application
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)
#include <iostream>
using namespace std;

#include <cstdlib>
#include <fstream>
#include <vector>

#include "DynamicArray.h"

const char* const DELIMITER = " ";

int main()
{
  // print my name and this assignment's title
  cout << "Lab 4b, Write A Dynamic Array Application\n";
  cout << "Programmer: Kwun Hang Chan\n";
  cout << "Editor(s) used: Xcode\n";
  cout << "Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  DynamicArray<int> a;
  
  char buf [100];
  const char* token[3] = {};
  int index, value;
  
  // input loop
  while (true)
  {
    cout << "Input an index and a value [Q to quit]:";
    cin.getline(buf, 200);
    token[0] = strtok(buf, DELIMITER); // first token
    if(strcmp(token[0], "Q") == 0 || strcmp(token[0], "q") == 0) break;
    token[1] = strtok(0, DELIMITER); // second token
    index = atoi(token[0]);
    value = atoi(token[1]);
    a[index] = value;
  }
  
  // display all values in dynamic array
  cout << "\nI stored this many values: " << a.size() << endl;
  cout << "The values are:" << endl;
  const DynamicArray<int> copy = a;
  for (int i = 0; i < copy.capacity(); i++)
    if (copy.containsKey(i))
      cout  << " " << i  << " " << copy[i] << endl;

  // output loop
  while (true)
  {
    cout << "Input an index for me to look up [Q to quit]:";
    cin >> buf;
    if (buf[0] == 'Q' || buf[0] == 'q') break;
    index = atoi(buf);
    if (copy.containsKey(index))
      cout << "Found it -- the value stored at "
      << index << " is " << copy[index] << endl;
    else
      cout << "I didn't find it" << endl;
  }
}