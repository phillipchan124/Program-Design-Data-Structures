// Lab 7a, Write And Test A Stack Template
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)
#include <iostream>
using namespace std;

#include <cassert>

#include "Stack.h"
#include "Stack.h" // testing ifndef

int main()
{
  // print my name and this assignment's title
  cout << "Lab 7a, Write And Test A Stack Template\n";
  cout << "Programmer: Kwun Hang Chan\n";
  cout << "Editor(s) used: Xcode\n";
  cout << "Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  int param;
  
  cout << "Create a stack for storing int, a" << endl;
  Stack<int> a;
  cout << "Output size" << endl;
  cout << "Expected size: 0" << endl;
  cout << "Actual size: " << a.size() << endl;
  assert( 0 == a.size() );
  cout << "Expected empty test: True" << endl;
  if (a.empty()) cout << "Actual empty test: True" << endl << endl;
  else cout << "Actual empty test: False" << endl << endl;
  assert( true == a.empty() );
  
  cout << "Pushing 5 into a" << endl;
  a.push(5);
  cout << "Output size" << endl;
  cout << "Expected size: 1" << endl;
  cout << "Actual size: " << a.size() << endl;
  assert( 1 == a.size() );
  cout << "Expected empty test: False" << endl;
  if (a.empty()) cout << "Actual empty test: True" << endl << endl;
  else cout << "Actual empty test: False" << endl << endl;
  assert( false == a.empty() );
  
  cout << "Pushing 10 into a" << endl;
  a.push(10);
  cout << "Output size" << endl;
  cout << "Expected size: 2" << endl;
  cout << "Actual size: " << a.size() << endl << endl;
  assert( 2 == a.size() );
  
  cout << "Pushing 15 and 20 into a" << endl << endl;
  a.push(15); a.push(20);
  
  cout << "Testing pop function" << endl;
  if ( a.pop(param) )
  {
    cout << "pop works!" << endl;
    cout << "Expected param = 20, Actual param = " << param << endl;
    cout << "Expected size: 3" << endl;
    cout << "Actual size: " << a.size() << endl << endl;
  }
  else cout << "No value in stack" << endl;
  assert ( 20 == param );
  assert( 3 == a.size() );
  
  cout << "Testing peek function" << endl;
  if ( a.peek(param) )
  {
    cout << "peek works!" << endl;
    cout << "Expected param = 15, Actual param = " << param << endl;
    cout << "Expected size: 3" << endl;
    cout << "Actual size: " << a.size() << endl << endl;
  }
  else cout << "No value in stack" << endl;
  assert ( 15 == param );
  assert( 3 == a.size() );
  
  cout << "Testing top function" << endl;
  if ( a.top(param) )
  {
    cout << "top works!" << endl;
    cout << "Expected param = 15, Actual param = " << param << endl;
    cout << "Expected size: 3" << endl;
    cout << "Actual size: " << a.size() << endl << endl;
  }
  else cout << "No value in stack" << endl;
  assert ( 15 == param );
  assert( 3 == a.size() );
  
  {
    cout << "Testing copy constructor" << endl;
    cout << "Expected value in a: 5 10 15" << endl;
    cout << "Using pop to output the result." << endl;
    cout << "Expected: 15 10 5 \nActual: ";
    for (Stack<int> cpy = a; !cpy.empty(); cpy.pop(param))
    {
      cpy.top(param);
      cout << param << " ";
    }
    cout << endl << endl;
  }
  
  {
    cout << "Testing overloading operator =" << endl;
    cout << "Expected value in a: 5 10 15" << endl;
    cout << "Using pop to output the result." << endl;
    cout << "Expected: 15 10 5 \nActual: ";
    Stack<int> cpy; cpy = a;
    for (; !cpy.empty(); cpy.pop(param))
    {
      cpy.top(param);
      cout << param << " ";
    }
    cout << endl << endl;
  }
  
  cout << "Pushing 25 and 30 into a" << endl << endl;
  a.push(25); a.push(30);
  
  {
    cout << "Expected value in a: 5 10 15 25 30" << endl;
    cout << "Using pop to output the result." << endl;
    cout << "Expected: 30 25 15 10 5 \nActual: ";
    for (Stack<int> cpy = a; !cpy.empty(); cpy.pop(param))
    {
      cpy.top(param);
      cout << param << " ";
    }
    cout << endl << endl;
  }
  
  cout << "Clear the stack" << endl;
  a.clear();
  cout << "Expected size: 0" << endl;
  cout << "Actual size: " << a.size() << endl << endl;
  assert( 0 == a.size() );
}