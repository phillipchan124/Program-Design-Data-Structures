// Lab 7b, Write And Test A Queue Template
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)
#ifndef Node_h
#define Node_h
template<class T>
struct Node
{
  T value;
  Node* next;
};
#endif

#ifndef Queue_h
#define Queue_h

template<class T>
class Queue
{
private:
  Node<T>* start;
  Node<T>* end;
  int siz; // track size
public:
  Queue();
  bool empty() const {return 0 == siz;} // inline
  int size() const {return siz;} // inline
  void push(const T&);
  bool peek(T&) const;
  bool top(T&) const;
  bool pop(T&);
  void clear();
  Queue<T>& operator=(const Queue<T>& a);
  Queue(const Queue<T>& a);
  ~Queue();
};
template<class T>
Queue<T>::Queue()
{
  start = 0; // empty list
  end = 0;
  siz = 0;
}
template<class T>
void Queue<T>::push(const T& parameter)
{
  Node<T>* node = new Node<T>;
  node->value = parameter;
  node->next = 0;
  if (end) end->next = node;
  else start = node;
  end = node;
  ++siz;
}
template<class T>
bool Queue<T>::peek(T& parameter) const
{
  if (0 == siz) return false; // failed
  parameter = start->value;
  return true; // success
}
template<class T>
bool Queue<T>::top(T& parameter) const
{
  if (0 == siz) return false; // failed
  parameter = start->value;
  return true; // success
}
template<class T>
bool Queue<T>::pop(T& parameter)
{
  if (0 == start) return false; // failed
  parameter = start->value;
  Node<T>* p = start->next;
  delete start;
  start = p;
  --siz;
  return true; // success
}
template<class T>
void Queue<T>::clear()
{
  while (start)
  {
    Node<T>* p = start->next;
    delete start;
    start = p;
  }
  end = 0;
  siz = 0;
}
template <class T>
Queue<T>::~Queue()
{
  while (start)
  {
    Node<T>* p = start->next;
    delete start;
    start = p;
  }
}
template <class T>
Queue<T>::Queue(const Queue<T>& a)
{
  start = 0;
  end = 0;
  siz = a.siz;
  for (Node<T>* p = a.start; p; p = p->next)
  {
    Node<T>* node = new Node<T>;
    node->value = p->value;
    node->next = 0;
    if (end) end->next = node;
    else start = node;
    end = node;
  }
}
template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& a)
{
  if (this == &a) return *this;
  
  // deallocate existing queue
  while (start)
  {
    Node<T>* p = start->next;
    delete start;
    start = p;
  }
  // build new queue
  end = 0; // temporary end pointer
  for (Node<T>* p = a.start; p; p = p->next)
  {
    Node<T>* node = new Node<T>;
    node->value = p->value;
    node->next = 0;
    if (end) end->next = node;
    else start = node;
    end = node;
  }
  siz = a.siz;
  
  return *this;
}

#endif /* Queue_h */
