// Lab 7c, Use A Stack
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)
#include <iostream>
#include <fstream> 
#include <string>
using namespace std;

#include "Stack.h"
struct Check
{
  char symbol;
  int lineNum;
};
int main()
{
  // print my name and this assignment's title
  cout << "Lab 7c, Use A Stack\n";
  cout << "Programmer: Kwun Hang Chan\n";
  cout << "Editor(s) used: Xcode\n";
  cout << "Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  // for parsing the inputfile
  char buf[1000];
  int n = 0;
  int i = 0;
  bool ignoring = false;
  bool commentIgnoring = false;
  Stack<Check> s;
  Check c;
  int lineCount = 0;

  // open the input file
  ifstream fin;
  cout << "Enter filename (H, CPP, JAVA, HTML, or JS): ";
  string filename;
  getline(cin, filename);
  fin.open(filename);
  if (!fin.good()) throw "I/O error";

  // read the input file
  while (fin.good())
  {
    // read the line
    lineCount++;
    string line;
    getline(fin, line);
    strcpy(buf, line.c_str());
    if (buf[0] == 0) continue;
    n = strlen(buf);
    ignoring = false;
    
    for ( i=0 ; i<n ; i++ )
    {
      if ( buf[i] == '/')
        if( i+1 < n && buf[i+1] == '*')
        {
          c.symbol = '/';
          c.lineNum = lineCount;
          s.push(c);
          commentIgnoring = true;
        }
      if ( buf[i] == '*')
        if ( i+1 < n && buf[i+1] == '/')
        {
          if ( !s.empty()) s.top(c);
          if ( s.empty() || c.symbol != '/')
          {
            cout << "Closing comment offsets found in line " << lineCount << " of " << filename << endl;
            cout << "But no matching comment offsets found." << endl;
            fin.close();
            return 0;
          }
          if ( c.symbol == '/') { s.pop(c); commentIgnoring = false; }
        }
      if (!commentIgnoring)
      {
        if ( buf[i]=='\"')
        {
          ignoring = !ignoring;
          if (ignoring)
          {
            c.symbol = buf[i];
            c.lineNum = lineCount;
            s.push(c);
          }
          if ( !ignoring ) s.pop(c);
        }
        if ( ignoring ) continue;
        if ( buf[i] == '/')
          if ( (i+1)<n && buf[i+1] == '/')
            break;
        if (  buf[i] == '{' || buf[i] == '(' || buf[i] == '[')
        {
          c.symbol = buf[i];
          c.lineNum = lineCount;
          s.push(c);
        }
        if ( buf[i] == '}')
        {
          if (!s.empty()) s.top(c);
          if ( s.empty() || c.symbol != '{')
          {
            cout << "Closing curly brace found in line " << lineCount << " of " << filename << endl;
            cout << "But no matching opening curly brace found." << endl;
            fin.close();
            return 0;
          }
          if ( c.symbol == '{') { s.pop(c); }
        }
        if ( buf[i] == ')')
        {
          if (!s.empty()) s.top(c);
          if ( s.empty() || c.symbol != '(')
          {
            cout << "Closing parenthesis found in line " << lineCount << " of " << filename << endl;
            cout << "But no matching opening parenthesis found." << endl;
            fin.close();
            return 0;
          }
          if ( c.symbol == '(') s.pop(c);
        }
        if ( buf[i] == ']')
        {
          if (!s.empty()) s.top(c);
          if ( s.empty() || c.symbol != '[')
          {
            cout << "Closing square bracket found in line " << lineCount << " of " << filename << endl;
            cout << "But no matching opening square bracket found." << endl;
            fin.close();
            return 0;
          }
          if ( c.symbol == '[') s.pop(c);
        }
      }
    }
    if ( !s.empty() )
    {
      s.top(c);
      if ( c.symbol == '\"')
      {
        cout << "Opening double quote found in line " << c.lineNum << " of " << filename << endl;
        cout << "But no closing double quote found." << endl;
        fin.close();
        return 0;
      }
    }
  }
  
  // close input file
  fin.close();
  
  if ( s.empty() ) cout << "No mismatches found by my preprocessor in " << filename << endl;
  else
  {
    s.top(c);
    string bracket;
    if (c.symbol == '(') bracket = "parenthesis";
    if (c.symbol == '{') bracket = "curly brace";
    if (c.symbol == '[') bracket = "square bracket";
    if (c.symbol == '/') bracket = "comment offset";
    if (c.symbol == '\"') bracket = "double quote";
    cout << "Opening "  << bracket << " found in line " << c.lineNum << " of " << filename << endl;
    cout << "But no closing "  << bracket << " found." << endl;
  }
}
