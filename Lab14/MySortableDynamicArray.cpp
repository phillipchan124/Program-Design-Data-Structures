// Lab 14a, Write A Sortable Array Class Template
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)
#include <iostream>
using namespace std;

#include <cstdlib>
#include <fstream>
#include <vector>

#include "SortableDynamicArray.h"

const char* const DELIMITER = " ";

int main()
{
  // print my name and this assignment's title
  cout << "Lab 14a, Write A Sortable Array Class Template\n";
  cout << "Programmer: Kwun Hang Chan\n";
  cout << "Editor(s) used: Xcode\n";
  cout << "Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  SortableDynamicArray<int> a;
  
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
  int number = 0;
  for(int i=0; i<a.capacity() ;i++)
    if(a.containsKey(i)) number++;
  cout << "Number of values actually entered by the user: " << number << endl;
  cout << "The values are:" << endl;
  const SortableDynamicArray<int> copy = a;
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
  
  // sorting and binary searching
  int num;
  {
    cout << "How many values include in sorting and binary searching: ";
    cin >> buf;
    num = atoi(buf);
    a.sort(num);
    cout << "The sorted values are:" << endl;
    const SortableDynamicArray<int> copy = a;
    for (int i = 0; i < copy.capacity(); i++)
      if (copy.containsKey(i))
        cout  << " " << i  << " " << copy[i] << endl;
  }
  
  // binary search lookups
  while (true)
  {
    cout << "Input an index for me to look up using binary search [Q to quit]:";
    cin >> buf;
    if (buf[0] == 'Q' || buf[0] == 'q') break;
    int param = atoi(buf);
    int index = a.bsearch(num, param);
    if ( index == -1) cout << "I didn't find it" << endl;
    else
      cout << "Found it -- " << param << " stored at " << index << endl;
  }
}