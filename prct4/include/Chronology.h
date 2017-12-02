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
  */
  std::pair<iterator, bool> insert(HistoricDate fh);
/**
  * @brief Devuelve una Fecha Historica. Devuelve NULL si no se encuentra en la cronología. Eficiencia: O(log(n)).
  * @param fecha por la que es buscada la Fecha Historica
  * @return Referencia constante a la fecha historica.
  */
  HistoricDate getHistoricDate(int fecha);
/**
  * @brief Devuelve el número de fechas históricas almacenadas.
  * @return Número actual de fechas históricas almacenadas.
  */
  int getNumHistoricDates() const;
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
  * @return Subcronologia mencionada.
  */
  void mergeCron( Chronology &cron, Chronology &result);
/**
  * @brief Obtiene la intersección entre dos cronologías, uniendo las fechas históricas. Eficiencia: O(m*k), donde m = interseccion.getNumHistoricDates() y k es el k = max{intereseccion.v[i].getNumEventos() : 0 <= i < interseccion.getNumEventos()}.
  * @param cron es la cronología a intersectar.
  * @return Subcronologia mencionada.
  */
  void intersecCron(Chronology &cron, Chronology &result);
/**
  * @brief Función amiga de la clase, lee una Cronología a través del flujo.
  * @param is referencia al flujo de entrada por el que se leerá el objeto.
  * @param cron referencia a un tipo Fecha Historica en la que se guardarán los datos.
  * @return flujo proporcionado como argumento.
  */
  friend istream& operator >> (istream& is, Chronology &cron);

  friend ostream& operator << (ostream& os, const Chronology& cron);

  double mean();
  int numYears();
  int numEvents();
  HistoricDate trend();

  iterator begin ();
  const_iterator cbegin () const;
  iterator end ();
  const_iterator cend () const;
};

#endif
