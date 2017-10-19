
#ifndef _STACK_MAX_VD_H_
#define _STACK_MAX_VD_H_

template <class T>
class stackMaxVD {
  struct pair {
    T max;
    T data;
  };
private:
  vector<pair> v;
public:
  stackMaxVD();
  ~stackMaxVD();
  void add(T data);
  T peak();
  void remove();
  T max();
  bool isEmpty();
};

#include "../src/stackMaxVD.cpp"
#endif
