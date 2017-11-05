//https://isocpp.org/wiki/faq/templates#nondependent-name-lookup-members

#ifndef _STACK_MAX_VD_H_
#define _STACK_MAX_VD_H_

#include <vector>
template <class T>
struct Ownpair {
  T max;
  T data;
};

template <class T>
class StackMaxVD {
private:
  std::vector<Ownpair<T> > v;
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
