// José Antonio Álvarez Ocete
// Yábir García Benchakhtir
#include <cassert>
using namespace std;

template <class T>
StackCeldas<T>::StackCeldas () {
  top = NULL;
}

template <class T>
StackCeldas<T>::~StackCeldas() {
  Node * aux;
  while (top != NULL) {
    aux = top;
    top = top->next;
    delete aux;
  }
}

// Throws exception if isEmpty()
template <class T>
T StackCeldas<T>::peak () {
  assert (!isEmpty());
  return top->data;
}

template <class T>
void StackCeldas<T>::push (T data) {
  Node * newTop = new Node;
  newTop->data = data;
  if (top == NULL) {
    newTop->next = NULL;
  } else {
    newTop->next = top;
  }
  top = newTop;
}

// Throws exception if isEmpty()
template <class T>
T StackCeldas<T>::pop () {
  assert (!isEmpty());
  T result = top->data;
  Node * aux = top->next;
  delete top;
  top = aux;
  return result;
}


template <class T>
bool StackCeldas<T>::isEmpty () {
  return top == NULL;
}

template <class T>
int StackCeldas<T>::size () {
  int counter = 1;

  Node * aux = top-> next;

  while(aux != 0){
    aux = aux->next;
    counter++;
  }

  return counter;
}
