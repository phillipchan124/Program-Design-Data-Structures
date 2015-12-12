// Lab 10, Write, Test and Apply The HashTable Class Template
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)
#ifndef HashTable_h
#define HashTable_h

#include <vector>
#include <list> // for the list itself
#include <algorithm> // for searching the list
using namespace std;
template<class T, class U, int CAPACITY>
class HashTable
{
private:
  struct Node
  {
    T value;
    U key;
    void operator=(const T& v){ value = v;}
    bool operator==(const Node& n) const { return key == n.key; }
  };
  T dummy;
  mutable int sizes;
  list<Node> data[CAPACITY]; // an array of CAPACITY empty lists a data member
  int(*hashCode)(const U&);
public:
  HashTable( int(*)(const U&) ); // default constructor
  T& operator[](const U&);
  T operator[](const U&) const;
  void deleteKey(const U&); // set "in use" to false
  bool containsKey(const U&) const;
  vector<U> keys() const; // all "in use" keys
  int size() const { return sizes; }
  int capacity() const { return 0.8 * CAPACITY; }
  void clear();
};
template<class T, class U, int CAPACITY>
HashTable<T, U, CAPACITY>::HashTable( int(*hf)(const U&) )
{
  hashCode = hf;
  sizes = 0;
}
template<class T, class U, int CAPACITY>
T& HashTable<T, U, CAPACITY>::operator[](const U& key)
{
  typename list<Node>::iterator it;
  Node temp; temp.key = key; // key is parameter
  int wi = hashCode(key);
  wi = wi % CAPACITY;
  if (wi< 0)  wi += CAPACITY;
  it = find(data[wi].begin(), data[wi].end(), temp);
  if( it != data[wi].end() ) return it->value;
  else
  {
    sizes++;
    data[wi].push_back(temp);
    return data[wi].back().value;
  }
}
template<class T, class U, int CAPACITY>
T HashTable<T, U, CAPACITY>::operator[](const U& key) const
{
  typename list<Node>::const_iterator it;
  Node temp; temp.key = key; // key is parameter
  int wi = hashCode(key);
  wi = wi % CAPACITY;
  if (wi< 0)  wi += CAPACITY;
  it = find(data[wi].begin(), data[wi].end(), temp);
  if( it != data[wi].end() ) return it->value;
  else return dummy;
}
template<class T, class U, int CAPACITY>
void HashTable<T, U, CAPACITY>::deleteKey(const U& key)
{
  typename list<Node>::iterator it;
  Node temp; temp.key = key; // key is parameter
  int wi = hashCode(key);
  wi = wi % CAPACITY;
  if (wi< 0)  wi += CAPACITY;
  it = find(data[wi].begin(), data[wi].end(), temp);
  if( it != data[wi].end() )
  {
    data[wi].erase(it);
    --sizes;
  }
}
template<class T, class U, int CAPACITY>
bool HashTable<T, U, CAPACITY>::containsKey(const U& key) const
{
  typename list<Node>::const_iterator it;
  Node temp; temp.key = key; // key is parameter
  int wi = hashCode(key);
  wi = wi % CAPACITY;
  if (wi< 0)  wi += CAPACITY;
  it = find(data[wi].begin(), data[wi].end(), temp);
  if( it != data[wi].end() ) return true;
  else return false;
}
template<class T, class U, int CAPACITY>
vector<U> HashTable<T, U, CAPACITY>::keys() const
{
  vector<U> v;
  typename list<Node>::const_iterator it;
  for ( int wi = 0; wi < CAPACITY ; wi++)
    for( it = data[wi].begin(); it!= data[wi].end() ; it++ )
      v.push_back(it->key);
  return v;
}
template<class T, class U, int CAPACITY>
void HashTable<T, U, CAPACITY>::clear()
{
  sizes = 0;
  for ( int wi = 0; wi < CAPACITY ; wi++) data[wi].clear();
}

#endif /* HashTable_h */
