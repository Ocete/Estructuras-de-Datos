// José Antonio Álvarez Ocete
// Yábir García Benchakhtir
//Manage exceptions
#include <exception>
#include <stdexcept>
#include <iostream>
#include "StackMaxVD.h"

using namespace std;

//template <class T>
//StackMax<T>::StackMax() {}

/*
template <class T>
StackMax<T>::~StackMax() {}
*/

template <class T>
void StackMax<T>::push(T data) {
  Ownpair<T> pareja;
  pareja.data = data;
  if(isEmpty())
    pareja.max = data;
  else
    pareja.max = data > max() ? data : max();

  v.push(pareja);
}

template <class T>
T StackMax<T>::peak() {
  if(isEmpty())
    throw out_of_range("Empty vector");

  return v.back().data;
}

template <class T>
T StackMax<T>::pop() {
  return v.pop_back().data;
}

template <class T>
T StackMax<T>::max() {
  int si = v.used();
  if (si == 0)
    throw out_of_range("Empty vector");

  return v.back().max;
}

template <class T>
int StackMax<T>::size() {
  return v.used();
}


template <class T>
bool StackMax<T>::isEmpty() {
  return v.used() == 0;
}
