/**
 * @file cronologia.h
 * @brief Fichero cabecera de la Cronologia.
 *
 * Almacena un conjunto ordenado de fechas históricas.
 */

#ifndef _CRONOLOGY_H_
#define _CRONOLOGY_H_

#include <string>
#include <map>
#include "historic_date.h"

/**
 * @brief Cronology
 *
 * Conjunto ordenado de fechas históricas al que podemos aplicar diversas
 * operaciones como obtener una fecha histórica específica, la unión de dos
 * cronologías, la intersección o la subcronología entre dos años dados.
 *
 */

class Cronology{
private:
  map<int,HistoricDate *> m; /**< Vector Dinamico que almacena las fechas históricas */
  const char SEPARATOR = '\n';  /**< Separdor entre fechas históricas utilizado al leer datos. */
public:
/**
  * @brief Constructor básico de la clase
  */
  Cronology();
/**
  * @brief Constructor de copia. Hace una copia @e no-profunda.
  * @param cron objeto a copiar.
  */
  Cronology(const Cronology &cron);
/**
  * @brief Sobrecarga del operador de asignación. Hace una copia @e no-profunda.
  * @param cron objeto a copiar.
  * @return Referencia al objeto copiado.
  */
  Cronology& operator = (const Cronology &cron);
/**
  * @brief Añade una fecha Histórica a la Cronology.
  * @param fh referencia a añadir.
  */
  void addHistoricDate(HistoricDate* fh);
/**
  * @brief Devuelve una Fecha Historica. Devuelve NULL si no se encuentra en la cronología. Eficiencia: O(log(n)).
  * @param fecha por la que es buscada la Fecha Historica
  * @return Referencia constante a la fecha historica.
  */
  HistoricDate* getHistoricDate(int fecha) const;
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
  * @brief Obtiene la subcronologia entre los dos años proporcionados, ambos inclusives. Eficiencia: O(n)
  * @param anioDesde representa la fecha a partir de la cual comenzamos a buscar.
  * @param anioHasta representa la fecha hasta la cual buscamos.
  * @return Subcronologia mencionada
  */
  Cronology subcronology(int anioDesde, int anioHasta) const;
/**
  * @brief Obtiene la subcronologia con aquellas fechas históricas contengan al menos una vez la string key. Eficiencia: O(n*O(f)), donde f es el método HistoricDate.includesKey(string key).
  * @param key es la string a buscar.
  * @return Subcronologia mencionada.
  */
  Cronology subcronology(string key) const;
/**
  * @brief Obtiene la unión entre dos cronologías, uniendo fechas históricas si es necesario. Eficiencia: O(m*k), en el peor caso (donde todas las fechas historicas esta duplicadas), donde m = cron.getNumHistoricDates() y k es el k = max{cron.v[i].getNumEventos() : 0 <= i < cron.getNumEventos()}.
  * @param cron es la cronología a unir.
  * @return Subcronologia mencionada.
  */
  Cronology mergeCron(const Cronology &cron) const;
/**
  * @brief Obtiene la intersección entre dos cronologías, uniendo las fechas históricas. Eficiencia: O(m*k), donde m = interseccion.getNumHistoricDates() y k es el k = max{intereseccion.v[i].getNumEventos() : 0 <= i < interseccion.getNumEventos()}.
  * @param cron es la cronología a intersectar.
  * @return Subcronologia mencionada.
  */
  Cronology intersecCron(const Cronology &cron) const;
/**
  * @brief Función amiga de la clase, lee una Cronología a través del flujo.
  * @param is referencia al flujo de entrada por el que se leerá el objeto.
  * @param cron referencia a un tipo Fecha Historica en la que se guardarán los datos.
  * @return flujo proporcionado como argumento.
  */
  friend istream& operator >> (istream& is, Cronology &cron);

  typedef typename map<int, HistoricDate*>::iterator iterator;
  typedef typename map<int, HistoricDate*>::const_iterator const_iterator;

  iterator begin ();
  const_iterator cbegin () const;
  iterator end ();
  const_iterator cend () const;
};

#endif
