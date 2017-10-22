/**
 * @file vector_dinamico.h
 * @brief Fichero cabecera del vector dinámico.
 *
 * Se crea un vector con capacidad dinámica.
 *
 */

#ifndef _VECTOR_DINAMICO_H_
#define _VECTOR_DINAMICO_H_

/**
 * @brief Vector Dinamico
 *
 * Un vector cuya capacidad aumenta de forma transparente al usuario.
 * Esta clase es análoga a la clase @e vector de la stl.
 *
 */

template <class T>
class vector_dinamico {
private:
  int elems; /**< Número actual de elementos en el vector */
  int cap; /**< Capacidad máxima actual del vector*/
  T * v; /**< Referencia al vector estático que almacena los datos de tipo T */

/**
  * @brief Redimensiona el vector interno si es necesario. Eficiencia: O(n)
  */
  void resize();
public:
/**
  * @brief Constructor por defecto. Inicializa la capacidad a 1.
  */
  vector_dinamico();
/**
  * @brief Añade un elemento al final del vector. @e Siempre podemos añadir elementos de esta forma. Eficiencia: O(1) debido al tiempo amortizado.
  * @param in elemento de la clase T a añadir.
  */
  void add (T in);
/**
  * @brief Añade un elemento al vector de forma ordenada. Eficiencia: O(n)
  * @param t elemento de la clase T a añadir.
  */
  void addOrdenado (T t);
/**
  * @brief Acceso a una posición del vector. Lanza excepción si el acceso es incorrecto. Eficiencia: O(1)
  * @param i elemento de tipo int que representa la posición.
  * @return Referencia al elemento en la posición i
  */
  T& operator[] (int i);
/**
  * @brief Acceso a una posición del vector de sólo lectura. Lanza excepción si el acceso es incorrecto. Eficiencia: O(1)
  * @param i elemento de tipo int que representa la posición.
  * @return Referencia constante al elemento en la posición i.
  */
  const T& operator[] (int i) const;
/**
  * @brief Capacidad del vector.
  * @return Capacidad actual del vector.
  */
  int getCap() const;
/**
  * @brief Elementos del vector.
  * @return Número actual de elementos del vector.
  */
  int getElems() const;
/**
  * @brief Libera la memoria reservada y pone la capacidad del vector a 0.
  */
  void destroy();
/**
  * @brief Destructor de la clase
  */
  ~vector_dinamico();
};

#include "../src/vector_dinamico.cpp"
#endif
