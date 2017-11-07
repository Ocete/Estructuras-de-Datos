// José Antonio Álvarez Ocete
// Yábir García Benchakhtir
/**
 * @file StackMaxQueue.h
 * @brief Fichero cabecera de la Pila implementada con usando una cola.
 *
 * Almacena una pila que conoce el máximo a partir de una cola.
 */
#ifndef _STACK_MAX_QUEUE_H_
#define _STACK_MAX_QUEUE_H_

/**
 * @brief StackMaxQueue
 *
 * Esta clase representa una pila, conociendo el máximo de la misma.
 * Esta implementada usando una cola.
 * Al implementarlo de esta forma o bien la inserción o bien la consulta/extaracción
 * pasan a ser O(n). En este caso hemos decidido que fuese la insercción ya que en
 * el otro caso afectaría también al consultar el máximo.
 *
 */

#include "queue.h"

template <class T>
class StackMaxQueue {
  struct pair {
    T data;
    T max;
  };
private:
  queue<pair> cola; /**< Cola en la que se almacenan los datos */
  int elems = 0; /**< Número de elementos en la pila */

public:
  //StackMax();
  //~StackMax();
/**
  * @brief Añade un elemento de tipo T a la pila. Eficiencia: O(n).
  * @param data será el elemento a añadir.
  */
  void push(T data);
/**
  * @brief Saca un elemento de la pila (el último introducido).
  * @return Elemento extraído.
  */
  T pop();
/**
  * @brief Consulta el próximo elemento que saldrá de la pila. Lanza excepción si está vacía.
  * @return Elemento consultado.
  */
  T peak();
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

#include "../src/StackMaxQueue.cpp"
#endif
