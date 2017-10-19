#include <cassert> // Para la funcion assert
using namespace std;

template <class T>
class stackVD {
  struct pair {
    T max;
    T data;
  };
private:
  vector<pair> = v;
public:
  stackVD();
  ~stackVD();
  void push(T data);
  T peak();
  T pop();
  bool isEmpty();
};

template <class T>
stackVD::stackVD() { }

template <class T>
stackVD::~stackVD() { }

template <class T>
void stackVD::add(T data) {
  v.add(data);
}

template <class T>
T stackVD::peak() {
  return v[v.getElems()];
}

template <class T>
T stackVD::remove() {
  return v.removeLast();
}

template <class T>
bool stackVD::isEmpty() {
  return v.getElems == 0;
}
