#include <list>
#include <cassert>
#include "myStack.h"
using namespace std;

template <class T>
myStack<T>::myStack() { }

// Esto hace falta?  List ya tiene su propio destructor que la limpia, no?
template <class T>
myStack<T>::~myStack() {
  while (l.begin() != l.end()) {
    l.erase(l.begin());
  }
}

template <class T>
void myStack<T>::push (T data) {
  pushFront(data);
}

// Throws exception if isEmpty()
template <class T>
T myStack<T>::peak() {
  assert(!isEmpty()); // Esto podríamos dejarlo más bonito
  return *l.front(); // Devolvemos el elemento apuntado por el iterador
}

// Throws exception if isEmpty()
template <class T>
T myStack<T>::pop() {
  assert(!isEmpty()); // Esto podríamos dejarlo más bonito
  T aux = *l.front();
  l.erase(l.begin());
  return aux;
}

template <class T>
bool myStack<T>::isEmpty() {
  return l.empty();
}

template <class T>
int myStack<T>::size() {
  return l.size();
}
