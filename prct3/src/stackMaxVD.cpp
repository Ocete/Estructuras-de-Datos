#include <cassert> // Para la funcion assert
using namespace std;

template <class T>
class stackMaxVD {
  struct pair {
    T max;
    T data;
  };
private:
  vector<pair> v;
public:
  stackMaxVD();
  ~stackMaxVD();
  void push(T data);
  T peak();
  T pop();
  T max();
  bool isEmpty();
};

template <class T>
stackMaxVD::stackMaxVD() { }

template <class T>
stackMaxVD::~stackMaxVD() { }

template <class T>
void stackMaxVD::add(T data) {
  pair pareja;
  pareja.data = data;
  pareja.max = data > max() ? data : max();
  v.add(pareja);
}

template <class T>
T stackMaxVD::peak() {
  return v[v.getElems()].data;
}

template <class T>
void stackMaxVD::remove() {
  return v.removeLast();
}

template <class T>
T stackMaxVD::max() {
  return v[v.getElems()].max;
}

template <class T>
bool stackMaxVD::isEmpty() {
  return v.getElems == 0;
}
