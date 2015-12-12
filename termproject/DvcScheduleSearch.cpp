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
  int n = 0; // count
  const char* const DELIMITER = " ";
  set<string> s;
  set<string>::iterator its;
  map<string, set<string> > y;
  map<string, set<string> >::iterator ity;
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

    const string termSem(term.begin(), term.begin() + term.find(' '));
    const string termYear(term.begin() + term.find(' ') + 1, term.end());

    it = m.find(course);
    if( it == m.end() ) m[course][termYear].insert(termSem);
    else
    {
      ity = m[course].find(termYear);
      if (ity == m[course].end()) m[course][termYear].insert(termSem);
      else
      {
        its = m[course][termYear].find(termSem);
        if ( its == m[course][termYear].end() )
        {
          m[course][termYear].insert(termSem);
        }
      }
    }
  }
  // close input file
  cout << "\nClose input file." << endl;
  fin.close();
  // search
  while (true)
  {
    cout << "Input a course to look up [X or x to quit]:";
    cin.getline(buf, 200);
    token = strtok(buf, DELIMITER);
    if(strcmp(token, "X") == 0 || strcmp(token, "x") == 0) break;
    it = m.find(string(token));
    if( it != m.end() )
    {
      ity = prev(it->second.end());
      string year = ity->first;
      string semester;
      set<string> s = ity->second;
      its = s.find("Spring"); if(its!=s.end()) semester = "Spring";
      its = s.find("Summer"); if(its!=s.end()) semester = "Summer";
      its = s.find("Fall"); if(its!=s.end()) semester = "Fall";
      cout << token << " was last offered in " <<  semester << " " << year << endl;
    }
    else cout << token << " has not been offered since the year 2000" << endl;
  }
}