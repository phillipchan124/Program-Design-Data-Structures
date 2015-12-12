// Term Project
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include <ctime>
#include <map>
#include <set>

int main()
{
  // print my name and this assignment's title
  cout << "Term Project\n";
  cout << "Programmer: Kwun Hang Chan\n";
  cout << "Editor(s) used: Xcode\n";
  cout << "Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  // for parsing the inputfile
  char* token;
  char buf[1000];
  const char* const tab = "\t";
  int n = 0, n_ts = 0; // count for duplicates
  set<string> c;
  set<string>::iterator itc;
  map<string, set<string> > s;
  map<string, set<string> >::iterator its;
  map<string, map<string, set<string> > > m;
  map<string, map<string, set<string> > >::iterator it;
  
  // start timer
  cout << "Timer starts.\n";
  clock_t startTime = clock();
  // open the input file
  ifstream fin;
  cout << "Open input file.\n";
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";
  // read the input file
  cout << "Process input file.\n";
  while (fin.good())
  {
    // read the line
    string line;
    getline(fin, line);
    strcpy(buf, line.c_str());
    if (buf[0] == 0) continue;
    if ( ++n % 1000 == 0 ) { cout << '.'; cout.flush(); }
    // parse the line
    const string term(token = strtok(buf, tab));
    const string section(token = strtok(0, tab));
    const string course((token = strtok(0, tab)) ? token : "");
    const string instructor((token = strtok(0, tab)) ? token : "");
    const string whenWhere((token = strtok(0, tab)) ? token : "");
    if (course.find('-') == string::npos) continue; // invalid line
    const string subjectCode(course.begin(), course.begin() + course.find('-'));

    it = m.find(term);
    if( it == m.end() ) m[term][section].insert(course);
    else
    {
      its = m[term].find(section);
      if (its == m[term].end()) m[term][section].insert(course);
      else
      {
        itc = m[term][section].find(course);
        if ( itc == m[term][section].end() )
        {
          m[term][section].insert(course);
          n_ts++;
        }
      }
    }
  }

  // close input file
  cout << "\nClose input file.";
  fin.close();
  // stop timer
  cout << "Timer stops\n";
  double elapsedSeconds = (double) (clock() - startTime) / CLOCKS_PER_SEC;
  // output result
  if (n_ts == 0 ) cout << "There are no term-section pairs duplicate records." << endl;
  else cout << "There are " << n_ts << " term-section pairs duplicate records." << endl;
  for( it = m.begin() ; it != m.end() ; it++)
    for( its = it->second.begin(); its != it->second.end() ; its++)
      if( its->second.size() > 1)
      {
        cout << it->first << " - " << its->first << endl;
        for( itc = its->second.begin(); itc != its->second.end() ; itc++)
        cout << "  " << *itc << endl;
      }
  
  cout << "The process took " << elapsedSeconds << " seconds to process and sort the file" << endl;
}