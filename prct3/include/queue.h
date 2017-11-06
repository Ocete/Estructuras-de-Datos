/**
 * @file queue.h
 * @brief Fichero cabecera de la Cola.
 *
 * Almacena un conjunto de celdas en formato LIFO.
 */
#ifndef _QUEUE_H_
#define _QUEUE_H_

/**
 * @brief Queue
 *
 * Esta clase representa una cola. Es decir, un cojunto de elementos
 * de tipo T de tipo LIFO. Disponemos de los 4 métodos estándar de
 * uso de colas.
 *
 */

template <class T>
class queue {
  struct Node {
    Node * next;
    T data;
  };
private:
  Node * top; /**< Puntero al primer elemento introducido en la cola. */
  Node * tail; /**< Puntero al último elemento introducido en la cola. */
public:
/**
  * @brief Constructor de la clase.
  */
  queue();
/**
  * @brief Destructor de la clase.
  */
  ~queue();
/**
  * @brief Añade un elemento de tipo T a la cola.
  * @param data será el elemento a añadir.
  */
  void add(T data);
/**
  * @brief Consulta el próximo elemento que saldrá de la cola. Lanza excepción si está vacía.
  * @return Elemento consultado.
  */
  T peak();
/**
  * @brief Saca un elemento de la cola (el primero introducido).
  * @return Elemento extraído.
  */
  T remove();
/**
  * @brief Consulta si la cola está vacía.
  * @return True si la cola está vacía. False en caso contrario.
  */
  bool isEmpty();
};

#include "../src/queue.cpp"
#endif
