// José Antonio Álvarez Ocete
// Yábir García Benchakhtir
#include <cassert>
using namespace std;

template <class T>
StackMax<T>::StackMax () {
  std::cout << "CELDAS ENLAZADAS" << std::endl;
  top = NULL;
}

template <class T>
StackMax<T>::~StackMax() {
  Node * aux;
  while (top != NULL) {
    aux = top;
    top = top->next;
    delete aux;
  }
}

// Throws exception if isEmpty()
template <class T>
T StackMax<T>::peak () {
  assert (!isEmpty());
  return top->data;
}

template <class T>
void StackMax<T>::push (T data) {
  Node * newTop = new Node;
  newTop->data = data;
  if (top == NULL) {
    newTop->max = data;
    newTop->next = NULL;
  } else {
    newTop->max = data > top->max ? data : top->max;
    newTop->next = top;
  }
  top = newTop;
  elems++;
}

// Throws exception if isEmpty()
template <class T>
T StackMax<T>::pop () {
  assert (!isEmpty());
  T result = top->data;
  Node * aux = top->next;
  delete top;
  top = aux;
  elems--;
  return result;
}

// Returns 0 if isEmpty
template <class T>
T StackMax<T>::max () {
  assert (!isEmpty());
  return top->max;
}

template <class T>
int StackMax<T>::size() {
  return elems;
}

template <class T>
bool StackMax<T>::isEmpty () {
  return top == NULL;
}
