// Lab 0c, Console Programming Basics
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
  // print my name and this assignment's title
  cout << "Lab 0c, Console Programming Basics\n";
  cout << "Programmer: Kwun Hang Chan\n";
  cout << "Editor(s) used: Xcode\n";
  cout << "Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    
  // declare buf as temp for input
  char buf[100];
    
  //Ask the user to input age and calculate next year age
  int age, nage;
  cout << "Enter your age: ";
  cin >> buf; age = atoi(buf);
  cin.ignore(1000, 10);
  nage = age + 1;
    
  // Ask the user to input name
  string name;
  cout << "Enter your name: ";
  getline(cin, name);
    
  // Ask the user to input degree (in F) and calculate degree (in C)
  double fdegree, cdegree;
  cout << "Enter the temperature outside right now (degrees F): ";
  cin >> buf; fdegree = atof(buf);
  cin.ignore(1000, 10);
  cdegree = ( fdegree - 32.0 ) * 5.0 / 9.0;
    
  // Ask the user to input city
  string city;
  cout << "What city are you in right now? ";
  getline(cin, city);
    
  // Output the result
  cout << name << " is " << age << " years old now, and will be " << nage <<" a year from now.\n"
       << "It's " << fdegree << " degrees F in " << city;
  cout.setf (ios::fixed|ios::showpoint);
  cout << " -- that's " << setprecision(1) << cdegree << " degrees C\n\n";
}