#ifndef _STACK_CELDAS_H_
#define _STACK_CELDAS_H_

template <class T>
class StackCeldas {
  struct Node {
    Node * next;
    T data;
  };
private:
  Node * top;

public:
  StackCeldas();
  ~StackCeldas();
  void push(T data);
  T pop();
  T peak();
  bool isEmpty();
  int size();
};

#include "StackCeldas.cpp"
#endif
