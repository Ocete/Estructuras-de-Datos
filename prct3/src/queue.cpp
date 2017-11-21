#include <cassert>

template <class T>
queue<T>::queue(): first(0), last(0), n(0){}

template <class T>
queue<T>::~queue(){
  Celda *aux;
  while(first != 0){
    aux = first;
    first = first->next;
    delete aux;
  }
}

template <class T>
bool queue<T>::isEmpty() const{
  return n == 0;
}

template <class T>
int queue<T>::size() const{
  return n;
}

template <class T>
void queue<T>::push(const T& val){
  Celda *aux = new Celda;
  aux->val = val;
  if(isEmpty())
    first = last = aux;
  else{
    last->next = aux;
    last = aux;
  }
  n++;
}

template <class T>
T queue<T>::pop(){
  assert(!isEmpty());
    Celda *aux = first;
    T ret_val = first->val;
    first = first->next;
    delete aux;
    n--;
    if(isEmpty())
      last = 0;

    return ret_val;
}

template <class T>
T& queue<T>::front(){
  assert(!isEmpty());
  return first->val;
}

template <class T>
const T& queue<T>::front() const{
  assert(!isEmpty());
  return first->val;
}

template <class T>
T& queue<T>::back(){
  assert(!isEmpty());
  return last->val;
}

template <class T>
const T& queue<T>::back() const{
  assert(!isEmpty());
  return last->val;
}
