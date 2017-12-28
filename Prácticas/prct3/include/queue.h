// José Antonio Álvarez Ocete
// Yábir García Benchakhtir
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
class queue{
  private:
    struct Celda{
      T val;
      Celda *next;

      Celda():next(0){}
    };

    Celda *first; /**< Puntero al primer elemento introducido en la cola. */
    Celda *last;  /**< Puntero al último elemento introducido en la cola. */
    int n;  /**< Tamaño de la cola. */

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
    * @brief Consulta si la cola está vacía.
    * @return True si la cola está vacía. False en caso contrario.
    */
    bool isEmpty() const;

    /**
    * @brief Consulta el tamaño de la cola
    * @return int indicando el tamaño de la cola
    */
    int size() const;

    /**
    * @brief Añade un elemento de tipo T a la cola.
    * @param val será el elemento a añadir.
    */
    void push(const T& val);

    /**
    * @brief Saca un elemento de la cola (el primero introducido).
    * @return Elemento extraído.
    */
    T pop();

    /**
    * @brief Consulta el próximo elemento que saldrá de la cola. Lanza excepción si está vacía.
    * @return Elemento consultado.
    */
    T& front();

    /**
    * @brief Consulta el próximo elemento que saldrá de la cola. Lanza excepción si está vacía.
    * @return Elemento consultado.
    */
    const T& front() const;

    /**
    * @brief Consulta el último elemento que se ha añadido
    * @return Elemento consultado.
    */
    T& back();

    /**
    * @brief Consulta el último elemento que se ha añadido
    * @return Elemento consultado.
    */
    const T& back() const;
};

#include "../src/queue.cpp"
#endif
