// Lab 9, Write, Test and Apply The AssociativeArray Template
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)
#include <iostream> // for cout and endl
#include <string> // for string
using namespace std;

#include <cassert> // for assert
#include <fstream> // for ifstream

#include "AssociativeArray.h"
#include "AssociativeArray.h" // testing ifnsdef

struct TermSection
{
  string term;
  string section;
};
bool operator==(const TermSection& x, const TermSection& y)
{
  if (x.term != y.term) return false;
  if (x.section != y.section) return false;
  return true;
}
int main()
{
  // print my name and this assignment's title
  cout << "Lab 9, Write, Test and Apply The AssociativeArray Template\n";
  cout << "Programmer: Kwun Hang Chan\n";
  cout << "Editor(s) used: Xcode\n";
  cout << "Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  // problem setup goes here
  char* token;
  char buf[1000];
  const char* const tab = "\t";
  AssociativeArray<string,TermSection> a;
  
  // programmer customizations go here
  int n = 100;
  int ndup = 0; // duplicate count
  
  // open the file and read the record
  cout << "Read 102 lines to get record and store in Associative Array." << endl;
  ifstream fin;
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";
  //read the input file n lines
  for(int i = 0; i < n; i++)
  {
    string line;
    getline(fin, line);
    strcpy(buf, line.c_str());
    if (buf[0] == 0) continue;
    
    // parse the line
    const string term(token = strtok(buf, tab));
    const string section(token = strtok(0, tab));
    const string course((token = strtok(0, tab)) ? token : "");
    const string instructor((token = strtok(0, tab)) ? token : "");
    const string whenWhere((token = strtok(0, tab)) ? token : "");
    if (course.find('-') == string::npos) continue; // invalid line
    const string subjectCode(course.begin(), course.begin() + course.find('-'));
    
    // add to Associate Array
    TermSection ts = { term, section };
    if ( a.containsKey(ts)) ndup++;
    else a[ts] = course;
  }
  fin.close();
  cout << "Expected size of Associative Array = no. of lines read - 1 - no. of duplicate" << endl;
  cout << "(-1 as the first line is the column index)" << endl;
  cout << "Expected size of Associative Array: " << n - 1 - ndup << endl;
  cout << "Actual size of Associative Array: " << a.size() << endl << endl;
  assert( a.size()== n - 1 - ndup);
  
  // reopen the file and reread the record
  cout << "Reread lines to get 100 record and store in Associative Array." << endl;
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";
  //read the input file n lines
  for(int i = 0; i < n; i++)
  {
    string line;
    getline(fin, line);
    strcpy(buf, line.c_str());
    if (buf[0] == 0) continue;
    
    // parse the line
    const string term(token = strtok(buf, tab));
    const string section(token = strtok(0, tab));
    const string course((token = strtok(0, tab)) ? token : "");
    const string instructor((token = strtok(0, tab)) ? token : "");
    const string whenWhere((token = strtok(0, tab)) ? token : "");
    if (course.find('-') == string::npos) continue; // invalid line
    const string subjectCode(course.begin(), course.begin() + course.find('-'));
    
    // delete key if match
    TermSection ts = { term, section };
    if ( a.containsKey(ts)) a.deleteKey(ts);
  }
  fin.close();
  cout << "Expected size of Associative Array: 0" << endl;
  cout << "Actual size of Associative Array: " << a.size() << endl << endl;
  assert( a.size()==0 );
  
  cout << "Create a Associative Array, b, storing int value with string key" << endl;
  AssociativeArray<int,string> b;
  cout << "Expected size of b: 0 capacity: 0" << endl;
  cout << "Actual size of b: " << b.size() << " capacity: " << b.capacity() << endl << endl;
  assert( b.size()==0 );
  assert( b.capacity()==0 );
  
  cout << "b[One] = 1, b[Two] = 2, b[Three] = 3, b[Four] = 4;" << endl;
  b["One"] = 1; b["Two"] = 2; b["Three"] = 3; b["Four"] = 4;
  
  cout << "Expected size of b: 4 capacity: 4" << endl;
  cout << "Actual size of b: " << b.size() << " capacity: " << b.capacity() << endl << endl;
  assert( b.size() == 4 );
  assert( b.capacity() == 4 );
  
  {
    cout << "Create a copy, c, to test getter function." << endl;
    AssociativeArray<int,string> c = b;
    cout << "Expected size of c: 4 capacity: 4" << endl;
    cout << "Actual size of c: " << c.size() << " capacity: " << c.capacity() << endl;
    cout << "Expected c[One] = 1, c[Two] = 2" << endl << "Actual: ";
    cout << "c[One] = " << c["One"] << " ";
    cout << "c[Two] = " << c["Two"] << endl << endl;
  }
  
  {
    cout << "Create an assocaite array, d, to test = operator." << endl;
    AssociativeArray<int,string> d; d = b;
    cout << "Expected size of d: 4 capacity: 4" << endl;
    cout << "Actual size of d: " << d.size() << " capacity: " << d.capacity() << endl;
    cout << "Expected d[Three] = 3, d[Four] = 4" << endl << "Actual: ";
    cout << "d[Three] = " << d["Three"] << " ";
    cout << "d[Four] = " << d["Four"] << endl << endl;
  }
  
  cout << "Set b[One] = 3; " << endl;
  b["One"] = 3;
  cout << "Expected: b[One] = 3 " << endl << "Actual: ";
  cout << "b[One] = " << b["One"] << endl << endl;
  
  cout << "Delete b[One]" << endl;
  b.deleteKey("One");
  cout << "Expected size of b: 3 capacity: 4" << endl;
  cout << "Actual size of b: " << b.size() << " capacity: " << b.capacity() << endl << endl;
  assert( b.size()==3 );
  assert( b.capacity()==4 );
  
  cout << "Testing vector to get keys from b" << endl;
  cout << "Expected: b[Two] = 2 b[Three] = 3 b[Four] = 4" << endl << "Actual: ";
  vector<string> keys = b.keys();
  for (int i = 0; i < keys.size(); i++)
    cout << "b[" << keys[i] << "] = " << b[keys[i]] << " ";
  cout << endl << endl;
  
  cout << "Clear b." << endl;
  b.clear();
  cout << "Expected size of b: 0 capacity: 4" << endl;
  cout << "Actual size of b: " << b.size() << " capacity: " << b.capacity() << endl << endl;
  assert( b.size()==0 );
  assert( b.capacity()==4 );
}