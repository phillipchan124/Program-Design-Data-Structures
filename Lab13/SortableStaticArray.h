// Lab 13a, Write A Sortable SortableArray Class Template
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)

#ifndef SortableStaticArray_H
#define SortableStaticArray_H

#include <vector>
using namespace std;

template<class T, int CAPACITY>
class SortableStaticArray
{
  T values[CAPACITY];
  bool inUse[CAPACITY];
  T dummy;
public:
  SortableStaticArray(); // default constructor
  T& operator[](int); // lookup key is an index
  T operator[](int) const;
  int size() const; // #of keys "in use", initially zero
  int capacity() const;
  bool containsKey(int) const;
  void deleteKey(int); // set "in use" to false
  vector<int> keys() const; // all "in use" keys
  void clear();
  void sort();
};
template <class T, int CAPACITY>
SortableStaticArray<T, CAPACITY>::SortableStaticArray()
{
  for ( int i = 0; i < CAPACITY ; i++)
    inUse[i] = false;
}
template <class T, int CAPACITY>
T& SortableStaticArray<T, CAPACITY>::operator[](int key) // lookup key is an index
{
  if (key < 0 || key >= CAPACITY) return dummy;
  inUse[key] = true;
  return values[key];
}
template <class T, int CAPACITY>
T SortableStaticArray<T, CAPACITY>::operator[](int key) const
{
  if (key < 0 || key >= CAPACITY) return dummy;
  if (inUse[key] == false) return dummy;
  return values[key];
}
template <class T, int CAPACITY>
int SortableStaticArray<T, CAPACITY>::size() const // #of keys "in use", initially zero
{
  int count = 0;
  for ( int i = 0; i < CAPACITY ; i++)
    if ( containsKey(i) )
      count++;
  return count;
}
template <class T, int CAPACITY>
int SortableStaticArray<T, CAPACITY>::capacity() const
{
  return CAPACITY;
}
template <class T, int CAPACITY>
bool SortableStaticArray<T, CAPACITY>::containsKey(int index) const
{
  if (index < 0) return false;
  if (index >= CAPACITY) return false;
  return inUse[index];
}
template <class T, int CAPACITY>
void SortableStaticArray<T, CAPACITY>::deleteKey(int index) // set "in use" to false
{
  if (index < 0) return;
  if (index >= CAPACITY) return;
  inUse[index] = false;
}
template <class T, int CAPACITY>
vector<int> SortableStaticArray<T, CAPACITY>::keys() const // all "in use" keys
{
  vector<int> v;
  for ( int i = 0; i < CAPACITY ; i++)
    if ( containsKey(i) )
      v.push_back(values[i]);
  return v;
}
template <class T, int CAPACITY>
void SortableStaticArray<T, CAPACITY>::clear()
{
  for ( int i = 0; i < CAPACITY ; i++)
    inUse[i] = false;
}
template <class T, int CAPACITY>
void SortableStaticArray<T, CAPACITY>::sort()
{
  for (int i = 0; i < CAPACITY; i++) // stop at n
  {
    if (!containsKey(i)) continue; // in case of holes
    for (int j = i + 1; j < CAPACITY; j++)
    {
      if (!containsKey(j)) continue; // in case of holes
      if (values[j] < values[i]) swap(values[i], values[j]);
    }
  }
}
#endif