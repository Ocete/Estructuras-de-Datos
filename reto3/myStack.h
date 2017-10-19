#include <list>

#ifndef _MY_STACK_H_
#define _MY_STACK_H_

template <class T>
class myStack{
 private:
  std::list<T> l;
 public:
  myStack();
  ~myStack();
  void push( T data );
  T pop();
  T peak();
  bool isEmpty();
  int size();
};

#include "myStack.cpp"
#endif
