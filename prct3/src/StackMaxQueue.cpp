#include <cassert>
using namespace std;

// Throws exception if isEmpty()
template <class T>
T StackMax<T>::peak () {
  assert (!isEmpty());
  return cola.peak()->data;
}

template <class T>
void StackMax<T>::push (T data) {
  pair newPair;
  newPair->data = data;
  if (isEmpty()) {
    newPair->max = data;
  } else {
    newPair->max = data > max()->max ? data : max()->max;
  }
  cola.push(newPair);
  for (int i=0; i<elems; i++) {
    cola.push(cola.pop());
  }
  elems++;
}

// Throws exception if isEmpty()
// Returns the element popped, not the max.
template <class T>
T StackMax<T>::pop () {
  assert (!isEmpty());
  elems--;
  return cola.pop()->data;
}

// Throws exception if isEmpty()
template <class T>
T StackMax<T>::max () {
  assert (!isEmpty());
  return cola.peak()->max;
}

template <class T>
int StackMax<T>::size() {
  return elems;
}

template <class T>
bool StackMax<T>::isEmpty () {
  return elems == 0;
}
