/**
 * @file cronologia.h
 * @brief Fichero cabecera de la Cronologia.
 *
 * Almacena un conjunto ordenado de fechas históricas.
 */

#ifndef _Chronology_H_
#define _Chronology_H_

#include <string>
#include <map>
#include <utility>
#include "historic_date.h"

/**
 * @brief Chronology
 *
 * Conjunto ordenado de fechas históricas al que podemos aplicar diversas
 * operaciones como obtener una fecha histórica específica, la unión de dos
 * cronologías, la intersección o la subcronología entre dos años dados.
 *
 */

class Chronology{
private:
  map<int,HistoricDate> m; /**< Vector Dinamico que almacena las fechas históricas */
  const char SEPARATOR = '\r';  /**< Separdor entre fechas históricas utilizado al leer datos. */
public:

  typedef typename map<int, HistoricDate>::iterator iterator;
  typedef typename map<int, HistoricDate>::const_iterator const_iterator;

/**
  * @brief Constructor básico de la clase
  */
  Chronology();
/**
  * @brief Constructor de copia. Hace una copia @e no-profunda.
  * @param cron objeto a copiar.
  */
  Chronology(const Chronology &cron);
/**
  * @brief Sobrecarga del operador de asignación. Hace una copia @e no-profunda.
  * @param cron objeto a copiar.
  * @return Referencia al objeto copiado.
  */
  Chronology& operator = (const Chronology &cron);

/**
  * @brief Añade una fecha Histórica a la Chronology.
  * @param fh referencia a añadir.
  * @return devuelve un iterador al elemento insertado y si se insertó correctamente.
  */
  std::pair<iterator, bool> insert(HistoricDate fh);
/**
  * @brief Devuelve una HistoricDate. Devuelve una HistoricDate nula si no se encontró. Eficiencia: O(log(n)).
  * @param fecha por la que es buscada la HistoricDate
  * @return HistoricDate buscada.
  */
  HistoricDate getHistoricDate(int fecha);
/**
  * @brief Imprime la Cronología por pantalla.
  */
  void print() const;
/**
  * @brief Limpia todo el contenido de la cronología.
  */
  void clear();
/**
  * @brief Obtiene la subcronologia entre los dos años proporcionados, ambos inclusives. Eficiencia: O(n)
  * @param anioDesde representa la fecha a partir de la cual comenzamos a buscar.
  * @param anioHasta representa la fecha hasta la cual buscamos.
  * @return Subcronologia mencionada
  */
  Chronology subChronology(int anioDesde, int anioHasta) const;
/**
  * @brief Obtiene la subcronologia con aquellas fechas históricas contengan al menos una vez la string key. Eficiencia: O(n*O(f)), donde f es el método HistoricDate.includesKey(string key).
  * @param key es la string a buscar.
  * @return Subcronologia mencionada.
  */
  Chronology subChronology(string key) const;
/**
  * @brief Obtiene la unión entre dos cronologías, uniendo fechas históricas si es necesario. Eficiencia: O(m*k), en el peor caso (donde todas las fechas historicas esta duplicadas), donde m = cron.getNumHistoricDates() y k es el k = max{cron.v[i].getNumEventos() : 0 <= i < cron.getNumEventos()}.
  * @param cron es la cronología a unir.
  * @param result es la subcronologia resultado.
  */
  void mergeCron( Chronology &cron, Chronology &result);
/**
  * @brief Obtiene la intersección entre dos cronologías, uniendo las fechas históricas. Eficiencia: O(m*k), donde m = interseccion.getNumHistoricDates() y k es el k = max{intereseccion.v[i].getNumEventos() : 0 <= i < interseccion.getNumEventos()}.
  * @param cron es la cronología a intersectar.
  * @param result es la subcronologia resultado.
  */
  void intersecCron(Chronology &cron, Chronology &result);
/**
  * @brief Función amiga de la clase, lee una Cronología a través del flujo.
  * @param is referencia al flujo de entrada por el que se leerá el objeto.
  * @param cron referencia a un tipo Fecha Historica en la que se guardarán los datos.
  * @return flujo proporcionado como argumento.
  */
  friend istream& operator >> (istream& is, Chronology &cron);
/**
  * @brief Función amiga de la clase, escribe una Cronología a través del flujo.
  * @param os referencia al flujo de salida por el que se imprimirá el objeto.
  * @param cron referencia a un tipo HistoricDate que se imprimirá por el flujo.
  * @return flujo proporcionado como argumento.
  */
  friend ostream& operator << (ostream& os, const Chronology& cron);
/**
  * @brief Devuelve el año medio de la cronologia
  * @return Año medio de la cronologia.
  */
  double mean();
/**
  * @brief Devuelve el número de HistoricDates almacenadas.
  * @return Número actual de HistoricDates almacenados.
  */
  int numYears();
/**
  * @brief Devuelve el número de eventos totales almacenadas.
  * @return Número actual de eventos almacenados.
  */
  int numEvents();
/**
  * @brief Devuelve la HistoricDate con más eventos de la cronologia.
  * @return HistoricDate con más eventos de la cronologia.
  */
  HistoricDate trend();
/**
  * @brief Devuelve un iterador a la primera HistoricDate de la cronología
  * @return Iterador a la primera HistoricDate de la cronología
  */
  iterator begin ();
/**
  * @brief Devuelve un iterador constante a la primera HistoricDate de la cronología
  * @return Iterador constante a la primera HistoricDate de la cronología
  */
  const_iterator cbegin () const;
/**
  * @brief Devuelve un iterador a la última HistoricDate de la cronología
  * @return Iterador a la última HistoricDate de la cronología
  */
  iterator end ();
/**
  * @brief Devuelve un iterador constante a la última HistoricDate de la cronología
  * @return Iterador constante a la última HistoricDate de la cronología
  */
  const_iterator cend () const;
};

#endif
