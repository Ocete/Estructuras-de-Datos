
#ifndef _STACK_VD_H_
#define _STACK_VD_H_

template <class T>
class stackVD {
  struct pair {
    T max;
    T data;
  };
private:
  vector<pair> = v;
public:
  stackVD();
  ~stackVD();
  void add(T data);
  T peak();
  T remove();
  bool isEmpty();
};

#include "../src/stackVD.cpp"
#endif
