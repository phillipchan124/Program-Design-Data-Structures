// Lab 3a, Write A Static Array Class Template
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)
#include <iostream>
using namespace std;

#include <cassert>
#include <vector>

#include "StaticArray.h"

int main()
{
  // print my name and this assignment's title
  cout << "Lab 3a, Write A Static Array Class Template\n";
  cout << "Programmer: Kwun Hang Chan\n";
  cout << "Editor(s) used: Xcode\n";
  cout << "Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  cout << "Creat an arry for storing 10 int, a" << endl;
  StaticArray<int, 10> a;
  cout << "Output size and capacity" << endl;
  cout << "Expected capacity: 10  size: 0" << endl;
  cout << "Actual capacity: " << a.capacity() << "  ";
  assert( 10 == a.capacity() );
  cout << "size: " << a.size() << endl;
  assert( 0 == a.size() );
  
  cout << "Set a[1] = 10, a[3] = 5 and a[8] = 100" << endl;
  a[1] = 10; a[3] = 5; a[8] = 100;
  cout << "Expected a[1] = 10, a[3] = 5, a[8] = 100" << endl;
  cout << "Actual a[1] = " << a[1] << ", "
  << "a[3] = " << a[3] << ", "
  << "a[8] = " << a[8] << endl;
  assert( 10 == a[1] );
  assert( 5 == a[3] );
  assert( 100 == a[8] );
  
  cout << "Expected a[18] = dummy, a[12] = dummy" << endl;
  cout << "Actual a[18] = " << a[18] << ", " << "a[12] = " << a[12] << endl << endl;
  
  {
    cout << "Display the values in static array." << endl;
    StaticArray<int, 10> copy = a;
    for ( int i = 0; i < copy.capacity(); i++)
      if (copy.containsKey(i))
        cout << "a[" << i << "] = " << copy[i] << endl;
    cout << "Expected size: 3 " << endl;
    cout << "Actual size: " << a.size() << endl << endl;
    assert( 3 == a.size() );
  }

  cout << "Delete a[1]" << endl << endl;
  a.deleteKey(1);
  
  {
    cout << "Display the values in static array." << endl;
    StaticArray<int, 10> copy = a;
    for ( int i = 0; i < copy.capacity(); i++)
      if (copy.containsKey(i))
        cout << "a[" << i << "] = " << copy[i] << endl;
    cout << "Expected size: 2 " << endl;
    cout << "Actual size: " << a.size() << endl << endl;
    assert( 2 == a.size() );
  }
  
  {
    cout << "Create a vector, keys" << endl;
    vector<int> keys = a.keys();
    cout << "Display keys." << endl;
    cout << "Expected: \nkeys[0] = 5 \nkey[1] = 100\nActual: \n";
    for ( int i = 0; i< keys.size() ; i++)
      cout << "keys[" << i << "] = " << keys[i] << endl;
    
  }
  
  {
    cout << "\nCreate a copy for testing [], getter version" << endl;
    const StaticArray<int, 10> copy = a;
    cout << "Expect: \ncopy[0] = dummy\ncopy[1] = dummy\ncopy[2] = dummy\n"
    << "copy[3] = 5\ncopy[4] = dummy\ncopy[5] = dummy\n"
    << "copy[6] = dummy\ncopy[7] = dummy\ncopy[8] = 100\n"
    << "copy[9] = dummy\n"
    << "Actual: \n";
    for (int i = 0; i < copy.capacity(); i++)
      cout << "copy[" << i << "] = " << copy[i] << endl;
  }
  
  cout << "\nClear the Static Array, a" << endl;
  a.clear();
  
  {
    cout << "Display the values in static array." << endl;
    StaticArray<int, 10> copy = a;
    for ( int i = 0; i < copy.capacity(); i++)
      if (copy.containsKey(i))
        cout << "a[" << i << "] = " << copy[i] << endl;
    cout << "Expected size: 0 " << endl;
    cout << "Actual size: " << a.size() << endl << endl;
    assert( 0 == a.size() );
  }
}
