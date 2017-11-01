#include <cassert> // Para la funcion assert
using namespace std;

template <class T>
StackMaxVD::StackMaxVD() { }

template <class T>
StackMaxVD::~StackMaxVD() { }

template <class T>
void StackMaxVD::push(T data) {
  pair pareja;
  pareja.data = data;
  pareja.max = data > max() ? data : max();
  v.add(pareja);
  elems++;
}

template <class T>
T StackMaxVD::peak() {
  return v[v.getElems()].data;
}

template <class T>
T StackMaxVD::pop() {
  return v.removeLast().data;
}

template <class T>
T StackMaxVD::max() {
  return v[v.getElems()].max;
}

template <class T>
int StackMaxVD::size() {
  return v.getElems();
}


template <class T>
bool StackMaxVD::isEmpty() {
  return v.getElems == 0;
}
