
#ifndef _VECTOR_DINAMICO_H_
#define _VECTOR_DINAMICO_H_


template <class T>
class vector_dinamico {
private:
  int elems;
  int cap;
  T * v;
  void resize();
public:
  vector_dinamico();
  void add (T in);
  void addOrdenado (T t);
  //T get (int i);
  T& operator[] (int i);
  const T& operator[] (int i) const;
  int getCap() const;
  int getElems() const;
  void destroy();
  ~vector_dinamico();
};

#include "vector_dinamico.cpp"
#endif
