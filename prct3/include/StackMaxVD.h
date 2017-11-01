
#ifndef _STACK_MAX_VD_H_
#define _STACK_MAX_VD_H_

template <class T>
class StackMaxVD {
  struct pair {
    T max;
    T data;
  };
private:
  vector<pair> v;

public:
  StackMaxVD();
  ~StackMaxVD();
  void push(T data);
  T peak();
  T pop();
  T max();
  int size();
  bool isEmpty();
};

#include "../src/StackMaxVD.cpp"
#endif
