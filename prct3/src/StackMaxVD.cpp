//Manage exceptions
#include <exception>
#include <stdexcept>
#include <iostream>
#include "StackMaxVD.h"

using namespace std;

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
  T d = v.back().data;
  v.pop_back();
  return d;
}

template <class T>
T StackMaxVD<T>::max() {
  int si = v.size();
  if (si == 0)
    throw out_of_range("Empty vector");

  return v[si].max;
}

template <class T>
int StackMaxVD<T>::size() {
  return v.size();
}


template <class T>
bool StackMaxVD<T>::isEmpty() {
  return v.size() == 0;
}
