#ifndef _STACK_MAX_QUEUE_H_
#define _STACK_MAX_QUEUE_H_

#include "queue.h"

template <class T>
class StackMaxQueue {
  struct pair {
    T data;
    T max;
  };
private:
  queue<pair> cola;
  int elems = 0;

public:
  //StackMax();
  //~StackMax();
  void push(T data);
  T pop();
  T peak();
  T max();
  int size();
  bool isEmpty();
};

#include "../src/StackMaxQueue.cpp"
#endif
