#include <list>
#include <iostream>
using namespace std;

template <class T>
myStack::myStack() { }

// Esto hace falta?  List ya tiene su propio destructor que la limpia, no?
myStack::~myStack() {
  while (l.begin() != l.end()) {
    l.erase(l.begin());
  }
}

template <class T>
void myStack::push (<T> data) {
  pushFront(data);
}

// Throws exception if isEmpty()
template <class T>
int myStack::peak() {
  assert(isEmpty()); // Esto podríamos dejarlo más bonito
  return *l.front(); // Devolvemos el elemento apuntado por el iterador
}

// Throws exception if isEmpty()
template <class T>
int myStack::pop() {
  assert(isEmpty()); // Esto podríamos dejarlo más bonito
  T aux = *l.front();
  l.erase(l.begin());
  return aux;
}

template <class T>
bool myStack::isEmpty() {
  return l.empty();
}

template <class T>
int myStack::size() {
  return l.size();
}

// Este main hay que rehacerlo y llevarlo a otro archivo test.cpp
int main() {
  myStack S;
  cout << "Peak: " << S.peak()  << " " << S.isEmpty() << endl;
  cout << "Pop: " << S.pop() << " " << S.isEmpty() << endl;
  S.push(1);
  S.push(2);
  S.push(3);
  S.push(4);
  S.push(5);
  cout << "Peak: " << S.peak()  << " " << S.isEmpty() << endl;
  cout << "Pop: " << S.pop() << " " << S.isEmpty() << endl;
  cout << "Pop: " << S.pop() << " " << S.isEmpty() << endl;
}
