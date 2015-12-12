// Lab 1a, Class Programming and Testing
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)

#ifndef _Road_h
#define _Road_h

class Road
{
private:
  int width;
  int length;
public:
  void setWidth(int widthInFeet); //setter
  void setLength(int lengthInMile); //setter
  int getWidth() const; //getter
  int getLength() const; //getter
  int asphalt(int thickness) const; // asphalt function
};

#endif
