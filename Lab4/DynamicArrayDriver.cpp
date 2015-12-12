// Lab 4a, Write A Dynamic Array Class Template
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)
#include <iostream>
using namespace std;

#include <cassert>
#include <vector>

#include "DynamicArray.h"
#include "DynamicArray.h" // testing ifndef

int main()
{
  // print my name and this assignment's title
  cout << "Lab 4a, Write A Dynamic Array Class Template\n";
  cout << "Programmer: Kwun Hang Chan\n";
  cout << "Editor(s) used: Xcode\n";
  cout << "Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  cout << "Creat an arry for storing 10 int, a" << endl;
  DynamicArray<int> a(10);
  cout << "Output size and capacity" << endl;
  cout << "Expected capacity: 10  size: 0" << endl;
  cout << "Actual capacity: " << a.capacity() << "  ";
  assert( 10 == a.capacity() );
  cout << "size: " << a.size() << endl;
  assert( 0 == a.size() );
  
  cout << "Creat an arry for storing int, using default cap, b" << endl;
  DynamicArray<int> b;
  cout << "Output size and capacity" << endl;
  cout << "Expected capacity: 100  size: 0" << endl;
  cout << "Actual capacity: " << b.capacity() << "  ";
  assert( 100 == b.capacity() );
  cout << "size: " << a.size() << endl << endl;
  assert( 0 == b.size() );
  
  
  cout << "Set a[1] = 10, a[3] = 5 and a[8] = 100" << endl;
  a[1] = 10; a[3] = 5; a[8] = 100;
  cout << "Expected a[1] = 10, a[3] = 5, a[8] = 100" << endl;
  cout << "Actual a[1] = " << a[1] << ", "
  << "a[3] = " << a[3] << ", "
  << "a[8] = " << a[8] << endl << endl;
  assert( 10 == a[1] );
  assert( 5 == a[3] );
  assert( 100 == a[8] );
  
  cout << "Increasing Capacity." << endl;
  cout << "Set a[12] = 50" << endl;
  a[12] = 50;
  cout << "Expected a[12] = 50" << endl;
  cout << "Actual a[12] = " << a[12] << endl;
  assert( 50 == a[12] );
  cout << "Output capacity" << endl;
  cout << "Expected capacity: 13" << endl;
  cout << "Actual capacity: " << a.capacity() << endl << endl;
  assert( 13 == a.capacity() );

  {
    cout << "Display the values in dynamic array." << endl;
    DynamicArray<int> copy = a;
    for ( int i = 0; i < copy.capacity(); i++)
      if (copy.containsKey(i))
        cout << "a[" << i << "] = " << copy[i] << endl;
    cout << "Expected size: 4 " << endl;
    cout << "Actual size: " << a.size() << endl << endl;
    assert( 4 == a.size() );
  }

  cout << "Delete a[1]" << endl << endl;
  a.deleteKey(1);
  
  {
    cout << "Display the values in static array." << endl;
    DynamicArray<int> copy = a;
    for ( int i = 0; i < copy.capacity(); i++)
      if (copy.containsKey(i))
        cout << "a[" << i << "] = " << copy[i] << endl;
    cout << "Expected size: 3 " << endl;
    cout << "Actual size: " << a.size() << endl << endl;
    assert( 3 == a.size() );
  }
  
  {
    cout << "Create a vector, keys" << endl;
    vector<int> keys = a.keys();
    cout << "Display keys." << endl;
    cout << "Expected: \nkeys[0] = 5 \nkey[1] = 100\nkey[2] = 50\nActual: \n";
    for ( int i = 0; i< keys.size() ; i++)
      cout << "keys[" << i << "] = " << keys[i] << endl;
  }
  
  {
    cout << "\nCreate a copy for testing [], getter version" << endl;
    const DynamicArray<int> copy = a;
    cout << "Expect: \ncopy[0] = dummy\ncopy[1] = dummy\ncopy[2] = dummy\n"
    << "copy[3] = 5\ncopy[4] = dummy\ncopy[5] = dummy\n"
    << "copy[6] = dummy\ncopy[7] = dummy\ncopy[8] = 100\n"
    << "copy[9] = dummy\ncopy[10] = dummy\ncopy[11] = dummy\n"
    << "copy[12] = 50\n"
    << "Actual: \n";
    for (int i = 0; i < copy.capacity(); i++)
      cout << "copy[" << i << "] = " << copy[i] << endl;
  }
  
  cout << "\nClear the Static Array, a" << endl;
  a.clear();
  
  {
    cout << "Display the values in static array." << endl;
    DynamicArray<int> copy = a;
    for ( int i = 0; i < copy.capacity(); i++)
      if (copy.containsKey(i))
        cout << "a[" << i << "] = " << copy[i] << endl;
    cout << "Expected size: 0 " << endl;
    cout << "Actual size: " << a.size() << endl << endl;
    assert( 0 == a.size() );
  }
}
