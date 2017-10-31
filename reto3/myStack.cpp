// José Antonio Álvarez Ocete
// Yábir García Benchakhtir
#include <cassert>
#include <exception>
#include <stdexcept>

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
  l.push_front(data);
}

// Throws exception if isEmpty()
template <class T>
T myStack<T>::peak() {
  if(isEmpty())
    throw  std::out_of_range("Empty stack");

  return l.front(); // Devolvemos el elemento apuntado por el iterador
}

// Throws exception if isEmpty()
template <class T>
T myStack<T>::pop() {
  if(isEmpty())
    throw  std::out_of_range("Empty stack");

  T aux = l.front();
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
