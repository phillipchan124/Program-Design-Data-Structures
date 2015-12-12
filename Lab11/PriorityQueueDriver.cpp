// Lab 11, Write, Test A Priority Queue Template
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)
#include <iostream> // for cout and endl
using namespace std;

#include <cassert> // for assert
#include <algorithm> // for swap

#include "PriorityQueue.h"
#include "PriorityQueue.h" // testing ifnsdef


int main()
{
  // print my name and this assignment's title
  cout << "Lab 11, Write, Test A Priority Queue Template\n";
  cout << "Programmer: Kwun Hang Chan\n";
  cout << "Editor(s) used: Xcode\n";
  cout << "Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  cout << "Create a Prioruty Queue with capacity 5 (a) and default capacity (b)" << endl;
  cout << "PriorityQueue<int> a(5); PriorityQueue<int> b;" << endl;
  PriorityQueue<int> a(5);
  PriorityQueue<int> b;
  cout << "Expected size of a = 0, Expected size of b = 0" << endl;
  cout << "Actual size of a = " << a.size() << ", Actual size of b = " << b.size() << endl << endl;
  assert ( 0 == a.size() );
  assert ( 0 == b.size() );
  
  cout << "Testing empty()" << endl;
  a.empty()? cout << "a is empty.（CORRRET)" << endl : cout << "a is NOT empty.(INCORRECT)" << endl;
  b.empty()? cout << "b is empty.（CORRRET)" << endl : cout << "b is NOT empty.(INCORRECT)" << endl;
  cout << endl;
  
  cout << "Testing enquene(), adding 1 to 10 to a ascendingly and adding 1 to 4 to b ascendingly." << endl;
  for (int i = 1 ; i <= 10 ; i ++) a.enqueue(i);
  for (int i = 1 ; i <= 4 ; i ++) b.enqueue(i);
  cout << "Expected size of a = 10" << endl;
  cout << "Actual size of a = " << a.size() << endl;
  assert ( 10 == a.size() );
  cout << "Expected size of b = 4" << endl;
  cout << "Actual size of b = " << b.size() << endl << endl;
  assert ( 4 == b.size() );
  a.empty()? cout << "a is empty.（INCORRRET)" << endl : cout << "a is NOT empty.(CORRECT)" << endl;
  b.empty()? cout << "b is empty.（INCORRRET)" << endl : cout << "b is NOT empty.(CORRECT)" << endl;
  cout << endl;
  
  
  cout << "Testing dequene(), making copy of a, named as c." << endl;
  PriorityQueue<int> c = a;
  cout << "Expected size of c = 10" << endl;
  cout << "Actual size of c = " << c.size() << endl;
  assert ( 10 == c.size() );
  cout << "Expected values: 10 9 8 7 6 5 4 3 2 1" << endl << "Actual values: ";
  for (int i = 1 ; i <= 10 ; i ++)
  {

    cout << c.dequeue() << " ";
  }
  cout << endl;
  cout << "Expected size of c = 0" << endl;
  cout << "Actual size of c = " << c.size() << endl << endl;
  assert ( 0 == c.size() );
  
  cout << "Testing front() and back." << endl;
  cout << "Expected b.front() = 4 and b.back() = 1" << endl;
  cout << "Actual b.front() = " << b.front() << " and b.back() = " << b.back() << endl << endl;
  assert ( 4 == b.front() );
  assert ( 1 == b.back() );
  
  cout << "Testing clear()." << endl;
  a.clear();
  cout << "Expected size of a = 0" << endl;
  cout << "Actual size of a = " << a.size() << endl << endl;
  assert ( 0 == a.size() );
  a.empty()? cout << "a is empty.（CORRRET)" << endl : cout << "a is NOT empty.(INCORRECT)" << endl;
}