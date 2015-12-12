// Lab 1a, Class Programming and Testing
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)

#include "Road.h"

// setter for length in Road
void Road::setLength(int lengthInMile)
{
  length = lengthInMile;
}
// setter for width in Road
void Road::setWidth(int widthInFeet)
{
  width = widthInFeet;
}
// getter for length in Road
int Road::getLength() const
{
  return length;
}
// getter for width in Road
int Road::getWidth() const
{
  return width;
}
// calculation of asphalt
int Road::asphalt(int thickness) const
{
  int volume; // volume of asphalt in cuble feet
  const int feetPerMile = 5280; // feet per mile
  const double feetPerInche = 0.0833333; // feet per inch (up to 6 sig fig)
  volume = (thickness * feetPerInche)  * (length * feetPerMile) * width;
  return volume;
}