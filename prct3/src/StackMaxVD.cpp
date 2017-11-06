//Manage exceptions
#include <exception>
#include <stdexcept>
#include <iostream>
#include "StackMaxVD.h"

using namespace std;

template <class T>
StackMaxVD<T>::StackMaxVD() { }

template <class T>
StackMaxVD<T>::~StackMaxVD() {}

template <class T>
void StackMaxVD<T>::push(T data) {
  Ownpair<T> pareja;
  pareja.data = data;
  if(isEmpty())
    pareja.max = data;
  else
    pareja.max = data > max() ? data : max();

  v.push(pareja);
}

template <class T>
T StackMaxVD<T>::peak() {
  return v[v.used()].data;
}

template <class T>
T StackMaxVD<T>::pop() {
  return v.pop_back().data;
}

template <class T>
T StackMaxVD<T>::max() {
  int si = v.used();
  if (si == 0)
    throw out_of_range("Empty vector");

  return v[si].max;
}

template <class T>
int StackMaxVD<T>::size() {
  return v.used();
}


template <class T>
bool StackMaxVD<T>::isEmpty() {
  return v.used() == 0;
}
