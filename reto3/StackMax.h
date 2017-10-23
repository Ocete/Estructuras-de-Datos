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

public:
  StackMax();
  ~StackMax();
  void push(T data);
  T pop();
  T peak();
  T max();
  bool isEmpty();
};

#include "StackMax.cpp"
#endif
