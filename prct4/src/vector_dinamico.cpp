#include <iostream>
#include <cassert> // Para la funcion assert
using namespace std;

template <class T>
void vector_dinamico<T>::resize() {
  if (v == NULL) {
    elems = 0;
    cap = 1;
    v = new T [1];
  } else {
    T * aux = new T [2*cap];
    for (int i=0;i<cap;i++) {
      aux[i] = v[i];
    }
    delete [] v;
    v = aux;
    cap *= 2;
  }
}

template <class T>
vector_dinamico<T>::vector_dinamico(){
  elems = 0;
  cap = 1;
  v = new T [1];
}

template <class T>
void vector_dinamico<T>::add (T in) {
  if (cap == elems) {
    resize();
  }
  v[elems] = in;
  elems++;
}

template <class T>
void vector_dinamico<T>::addOrdenado (T t) {
  if (cap == elems) {
    resize();
  }
  if (elems == 0) {
    v[0] = t;
  } else {
    int i = elems-1;
    while (i > 0 && t < v[i-1]) {
      v[i] = v [i-1];
      i--;
    }
    v[i] = t;
  }
  elems++;
}

template <class T>
T& vector_dinamico<T>::operator[] (int i) {
  assert (0<=i && i<elems);
  return v[i];
}

template <class T>
const T& vector_dinamico<T>::operator[] (int i) const {
  assert (0<=i && i<elems);
  return v[i];
}

template <class T>
int vector_dinamico<T>::getCap() const {
  return cap;
}

template <class T>
int vector_dinamico<T>::getElems() const {
  return elems;
}

template <class T>
void vector_dinamico<T>::destroy() {
  if (v != NULL) {
    delete [] v;
    v = NULL;
    cap = 0;
    elems = 0;
  }
}

template <class T>
vector_dinamico<T>::~vector_dinamico() {
  destroy();
}
