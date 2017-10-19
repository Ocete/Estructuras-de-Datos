#include <cassert> // Para la funcion assert
using namespace std;

template <class T>
queue<T>::queue() {
  top = NULL;
  tail = NULL;
}

template <class T>
queue<T>::~queue() {
  Node * aux;
  while (!isEmpty()) {
    aux = top;
    top = top->next;
    delete aux;
  }
}

template <class T>
void queue<T>::add(T data) {
  Node * newNode = new Node;
  newNode->data = data;
  newNode->next = NULL;
  if (isEmpty()) {
    top = newNode;
    tail = newNode;
  } else {
    top->next = newNode;
    top = top->next;
  }
}

// Throws exception if isEmpty
template <class T>
T queue<T>::peak() {
  assert(!isEmpty());
  return tail->data;
}

// Throws exception if isEmpty
template <class T>
T queue<T>::remove() {
  assert(!isEmpty());
  Node * aux = tail;
  T ret_val = tail->data;
  tail = tail->next;
  delete aux;
  return ret_val;
}

template <class T>
bool queue<T>::isEmpty() {
  return top == NULL;
}
