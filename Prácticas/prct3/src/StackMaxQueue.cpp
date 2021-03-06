// José Antonio Álvarez Ocete
// Yábir García Benchakhtir
#include <cassert>
using namespace std;

// Throws exception if isEmpty()
template <class T>
T StackMax<T>::peak () {
  assert (!isEmpty());
  return cola.front().data;
}

template <class T>
void StackMax<T>::push (T data) {
  pair newPair;
  newPair.data = data;
  if (isEmpty()) {
    newPair.max = data;
  } else {
    newPair.max = data > max() ? data : max();
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
  return cola.pop().data;
}

// Throws exception if isEmpty()
template <class T>
T StackMax<T>::max () {
  assert (!isEmpty());
  return cola.front().max;
}

template <class T>
int StackMax<T>::size() {
  return elems;
}

template <class T>
bool StackMax<T>::isEmpty () {
  return elems == 0;
}
