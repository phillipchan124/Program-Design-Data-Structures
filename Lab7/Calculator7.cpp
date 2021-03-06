// Lab 7a, Write And Test A Stack Template
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)
#include <iostream>
using namespace std;

#include <cstdlib>

#include "Stack.h"

int main()
{
  // print my name and this assignment's title
  cout << "Lab 7a, Write And Test A Stack Template\n";
  cout << "Programmer: Kwun Hang Chan\n";
  cout << "Editor(s) used: Xcode\n";
  cout << "Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  double param;
  Stack<double> s; // declare stack
  char buf[100]; // declare buf as temp for input

  // Running the calculator
  while(true)
  {
    cout << "Enter: ";
    
    // output the data in stack
    for (Stack<double> copy = s; !copy.empty() ; copy.pop(param))
    {
      copy.top(param);
      cout << param << " ";
    }
    
    cin >> buf;
    
    if (buf[0] == 'Q' || buf[0] == 'q') break; // Quit for 'q' or 'Q'
    
    // +, -, *, / operation
    if( s.size() >= 2 )
    {
      if (buf[0] == '+' || buf[0] == '-' || buf[0] == '*' || buf[0] == '/' )
      {
        double num1, num2 ,result;
        s.pop(param); num1 = param;
        s.pop(param); num2 = param;
        if( buf[0] == '+') result = num2 + num1;
        else if( buf[0] == '-') result = num2 - num1;
        else if( buf[0] == '*') result = num2 * num1;
        else if(buf[0] == '/') result = num2 / num1;
        s.push(result);
      }
      else s.push(atof(buf));
    }
    else
    {
      s.push(atof(buf));
    }
  }
}
