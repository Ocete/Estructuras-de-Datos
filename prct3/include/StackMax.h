// José Antonio Álvarez Ocete
// Yábir García Benchakhtir
/**
 * @file StackMax.h
 * @brief Fichero cabecera de la Pila implementada con celdas.
 *
 * Almacena una pila que conoce el máximo a partir de celdas enlazadas.
 */
#ifndef _STACK_MAX_H_
#define _STACK_MAX_H_

/**
 * @brief StackMax
 *
 * Esta clase representa una pila, conociendo el máximo de la misma.
 * Esta implementada usando celdas enlazadas.
 * Todos los métodos son de eficiencia O(1).
 *
 */

template <class T>
class StackMax {
  struct Node {
    Node * next;
    T data;
    T max;
  };
private:
  Node * top; /**< Puntero al tope de la pila */
  int elems = 0; /**< Número de elementos en la pila */

public:
/**
  * @brief Constructor de la clase.
  */
  StackMax();
/**
  * @brief Destructor de la clase.
  */
  ~StackMax();
/**
  * @brief Añade un elemento de tipo T a la pila.
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

#include "../src/StackMax.cpp"
#endif
