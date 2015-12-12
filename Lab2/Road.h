// Lab 2b, Writing Templates And Overloading Operators
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)

#ifndef _Road_h
#define _Road_h

template <class DataType>
class Road
{
private:
  DataType width;
  DataType length;
public:
  void setWidth(DataType w) { width = w; } //setter
  void setLength(DataType l) { length = l; } //setter
  DataType getWidth() const { return width; } //getter
  DataType getLength() const { return length; } //getter
  DataType asphalt(DataType thickness) const
  {
    DataType volume; // volume of asphalt in cuble feet
    const int feetPerMile = 5280; // feet per mile
    const double feetPerInche = 0.0833333; // feet per inch (up to 6 sig fig)
    volume = (feetPerInche * thickness )  * (length * feetPerMile) * width;
    return volume;
  } // asphalt function
};
// overloading operator <
template <class DataType>
bool operator< (const Road<DataType>& r1, const Road<DataType>& r2)
{
  return r1.getLength() < r2.getLength();
}
// overloading operator ==
template <class DataType>
bool operator== (const Road<DataType>& r1, const Road<DataType>& r2)
{
  return (r1.getLength() == r2.getLength() && r1.getWidth() == r2.getWidth());
}

#endif
