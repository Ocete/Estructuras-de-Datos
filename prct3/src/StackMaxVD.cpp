//Manage exceptions
#include <exception>
#include <stdexcept>

#include "StackMaxVD.h"


template <class T>
StackMaxVD<T>::StackMaxVD() { }

template <class T>
StackMaxVD<T>::~StackMaxVD() { }

template <class T>
void StackMaxVD<T>::push(T data) {
  Ownpair<T> pareja;
  pareja.data = data;
  try{
    pareja.max = data > max() ? data : max();
  }catch(std::out_of_range & e){
    pareja.max = data;
  }

  v.push_back(pareja);
}

template <class T>
T StackMaxVD<T>::peak() {
  return v[v.size()].data;
}

template <class T>
T StackMaxVD<T>::pop() {
  return v.pop_back().data;
}

template <class T>
T StackMaxVD<T>::max() {
  int si = v.size();
  if (si == 0)
    throw std::out_of_range("Empty vector");

  return v[si].max;
}

template <class T>
int StackMaxVD<T>::size() {
  return v.getElems();
}


template <class T>
bool StackMaxVD<T>::isEmpty() {
  return v.size() == 0;
}
