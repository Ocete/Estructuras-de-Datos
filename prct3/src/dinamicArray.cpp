// José Antonio Álvarez Ocete
// Yábir García Benchakhtir

//Manage input/output
#include <iostream>

//Manage exceptions
#include <exception>
#include <stdexcept>

//Headers
#include "dinamicArray.h"


template<class T>
DinamicArray<T>::DinamicArray(int n):elements(0){
  data = new T [n];
  max_elements = n;
}


template<class T>
DinamicArray<T>::~DinamicArray(){
  destroy();
}

template<class T>
void DinamicArray<T>::destroy(){

  if(data != 0)
    delete[] data;

  elements = 0;
  max_elements = 0;
}

template<class T>
int DinamicArray<T>::size() const{
  return max_elements;
}

template<class T>
int DinamicArray<T>::used() const{
  return elements;
}

template<class T>
int& DinamicArray<T>::used(){
  return elements;
}

template<class T>
DinamicArray<T>::DinamicArray(const DinamicArray<T>& original){

  elements = original.used();
  max_elements = original.size();

  data = new T [max_elements];

  for (int i = 0; i < used(); i++){
    data[i] = original[i];
  }

}

template<class T>
T& DinamicArray<T>::operator [] (int i){
  if(i > size() || i < 0)
    throw std::out_of_range("Trying to access invalid position");

  return data[i];
}

template<class T>
const T& DinamicArray<T>::operator [] (int i) const{
  if(i > used() || i < 0)
    throw std::out_of_range("Trying to access invalid position");

  return data[i];


}

template<class T>
DinamicArray<T>& DinamicArray<T>::operator=(const DinamicArray<T>& original){
  if (this == &original)
    return *this;

  delete [] data;
  elements = original.used();
  max_elements = original.size();

  data = new T [max_elements];

  for (int i = 0; i < used(); i++)
    data[i] = original[i];

  return *this;

}


//Increase size of dinamic array
template <class T>
void DinamicArray<T>::boost(){

  int newSize;
  //If size == 0 increase it to 2
  if (size() > 0)
    newSize = size() * 2;
  else
    newSize = 2;

  T* aux = new T[newSize];
  for(int i=0; i < used(); i++)
    aux[i] = data[i];

  delete[] data;
  max_elements = newSize;
  data = aux;

}

template <class T>
void DinamicArray<T>::push (T e){
  if(used() == size())
    boost();

   data[used()] = e;
   elements++;

}


template <class T>
bool DinamicArray<T>::insert(T e, int pos){

  bool success = false;

  if(pos >= 0 && pos < used()){
    if(used() == size())
      boost();

    for(int i= used(); i > pos; i--)
      data[i] = data[i-1];

    data[pos] = e;
    elements++;
    success = true;
  }
  else{
    push(e);
  }


  return success;
}

template <class T>
T DinamicArray<T>::pop_back (){
  if(used() == 0)
    throw std::out_of_range("Empty array");

  T aux = data[used()-1];
  elements--;
  return aux;
}

template <class T>
T& DinamicArray<T>::back (){
  return data[used()-1];
}

template <class T>
T& DinamicArray<T>::back () const{
  return data[used()-1];
}
