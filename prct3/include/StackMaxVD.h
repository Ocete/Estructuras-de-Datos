// José Antonio Álvarez Ocete
// Yábir García Benchakhtir
/**
 * @file StackMaxVD.h
 * @brief Fichero cabecera de la Pila implementada con usando un vector dinamico.
 *
 * Almacena una pila que conoce el máximo a partir de una cola.
 */
#ifndef _STACK_MAX_VD_H_
#define _STACK_MAX_VD_H_

/**
 * @brief StackMaxQueue
 *
 * Esta clase representa una pila, conociendo el máximo de la misma.
 * Esta implementada usando un vector dinamico.
 *
 */

#include "dinamicArray.h"
template <class T>
struct Ownpair {
  T max;
  T data;
};  /**< Pare de tope máximo */

template <class T>
class StackMax {
private:
  DinamicArray<Ownpair<T> > v;  /**< Vector de parejas de tipo T */
public:
  //StackMax();
  //~StackMaxVD();
  /**
    * @brief Añade un elemento de tipo T a la pila.
    * @param data será el elemento a añadir.
    */
  void push(T data);
  /**
    * @brief Consulta el próximo elemento que saldrá de la pila. Lanza excepción si está vacía.
    * @return Elemento consultado.
    */
  T peak();
  /**
    * @brief Saca un elemento de la pila (el último introducido).
    * @return Elemento extraído.
    */
  T pop();
  /**
    * @brief Consulta el máximo actual de la pila
    * @return El valor máximo de la pila
    */
  T max();
  /**
    * @brief Consulta el tamaño de la pila
    * @return El número de elementos en la pila.
    */
  int size();
  /**
    * @brief Consulta si la pila está vacía.
    * @return True si la pila está vacía. False en caso contrario.
    */
  bool isEmpty();
};

#include "../src/StackMaxVD.cpp"
#endif
