/**
 * @file historic_date.h
 * @brief Fichero cabecera de la date histórica.
 *
 * Se crea un int que almacena el año y un vector_dinamico<strings> para los eventos.
 *
 */

#ifndef _HITORIC_DATE_H_
#define _HITORIC_DATE_H_

#include <set>
#include <string>
using namespace std;

/**
 * @brief Fecha Historica
 *
 * Esta clase almacena un año, y un conjunto no ordenado de eventos.
 * Podemos, entre otras cosas, consultar el número de eventos, acceder a
 * uno específico o comprobar si contiene una key (string) en alguno de sus eventos.
 */

class HistoricDate{
private:
  int date; /**< Año que representa la fecha histórica. */
  set<string> s; /**< Vector dinámico que almacena los eventos. */
  const char SEPARATOR = '#'; /**< Separador entre eventos al leer datos. */

public:

  typedef typename set<string>::iterator iterator;
  typedef typename set<string>::const_iterator const_iterator;

  iterator begin ();
  const_iterator cbegin () const;
  iterator end ();
  const_iterator cend () const;

/**
  * @brief Constructor básico de la clase
  * @param year fecha en la que ocurren los eventos.
  */
  HistoricDate(int year=0);
/**
  * @brief Constructor de copia. Hace una copia @e profunda.
  * @param hf objeto a copiar.
  */
  HistoricDate(const HistoricDate &hf);
/**
  * @brief Sobrecarga del operador de asignación. Hace una copia @e profunda.
  * @param hf objeto a copiar.
  * @return Referencia al objeto copiado.
  */
  HistoricDate& operator = (const HistoricDate &hf);
/**
  * @brief Sobrecarga del operador de comparación.
  * @param hf Fecha a comprar.
  * @return True si el @año es el mismo, independientemente de los eventos.
  */
  bool operator == (HistoricDate hf) const;
/**
  * @brief Sobrecarga del operador de comparación menor.
  * @param hf Fecha Historica a comprar.
  * @return True si el @e año es el menor, independientemente de los eventos.
  */
  bool operator < (HistoricDate hf) const;
/**
  * @brief Sobrecarga del operador de comparación mayor.
  * @param hf Fecha Historica a comprar.
  * @return True si el @e año es el mayor, independientemente de los eventos.
  */
  bool operator > (HistoricDate hf) const;
/**
  * @brief Añade un evento a la Fecha Historica. Eficiencia: O(1).
  * @param hf Fecha Historica a comprar.
  * @return True si el @e año es el mayor, independientemente de los eventos.
  */
  void addEvent(string event);
/**
  * @brief Añade los eventos de la Fecha Historica proporcionado como parámetro. Eficiencia: O(k), k = hf.getNumEvents()
  * @param hf Fecha Historica a unir
  */
  void merge(const HistoricDate &hf);
/**
  * @brief Devuelve el número de eventos.
  * @return Número actual de eventos en la Fecha Historica.
  */
  int getNumEvents() const;
/**
  * @brief Devuelve el año de la Fecha Histórica.
  * @return Año de la Fecha Historica.
  */
  int getDate() const;
/**
  * @brief Imprime la Fecha Histórica por pantalla.
  */
  void print() const;
/**
  * @brief Comprueba si la Fecha Historica contiene la key en alguno de sus eventos. Eficiencia: O(getNumEvents()*m), m = max{getEvent(i).size() : 0 <= i < getNumEvents() }
  * @param key string a buscar.
  * @return True si la key aparece en algún evento. False en caso contrario.
  */
  bool includesKey(string key) const;
/**
  * @brief Función amiga de la clase, lee una Fecha Historica a través del flujo.
  * @param is referencia al flujo de entrada por el que se leerá el objeto.
  * @param hf referencia a un tipo Fecha Historica en la que se guardarán los datos.
  * @return flujo proporcionado como argumento.
  */
  friend istream& operator >> (istream& is, HistoricDate &hf);

  friend ostream& operator << (ostream& os, const HistoricDate &hf);



};

#endif
