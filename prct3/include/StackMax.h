#ifndef _STACK_MAX_H_
#define _STACK_MAX_H_

template <class T>
class StackMax {
  struct Node {
    Node * next;
    T data;
    T max;
  };
private:
  Node * top;
  int elems = 0;

public:
  StackMax();
  ~StackMax();
  void push(T data);
  T pop();
  T peak();
  T max();
  int size();
  bool isEmpty();
};

#include "../src/StackMax.cpp"
#endif
