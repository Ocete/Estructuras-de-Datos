/**
 * @file cronologia.h
 * @brief Fichero cabecera de la Cronologia.
 *
 * Almacena un conjunto ordenado de fechas históricas.
 */

#ifndef _CRONOLOGIA_H_
#define _CRONOLOGIA_H_

#include <string>
#include "fecha_historica.h"
#include "vector_dinamico.h"

/**
 * @brief Cronologia
 *
 * Conjunto ordenado de fechas históricas al que podemos aplicar diversas
 * operaciones como obtener una fecha histórica específica, la unión de dos
 * cronologías, la intersección o la subcronología entre dos años dados.
 *
 */

class Cronologia{
private:
  vector_dinamico<FechaHistorica *> v; /**< Vector Dinamico que almacena las fechas históricas */
  const char SEPARATOR = '\n';  /**< Separdor entre fechas históricas utilizado al leer datos. */
/**
  * @brief Comprueba si el acceso es correcto.
  * @param i entero cuyo acceso comprobamos: num_eventos > i >= 0.
  * @return True si el acceso es correcto. False en caso contrario.
  */
  bool accesoCorrecto(int i) const;
/**
  * @brief Busca un elemento por el año en el vector de fechas históricas. Eficiencia: O(log(n)).
  * @param goal referencia a un elemento con la fecha que buscamos.
  * @return Posición del objeto en el vector. En caso de no existir devuelve -1.
  */
  int binarySearch (FechaHistorica* goal) const ;
/**
  * @brief Añade un elemento de forma ordenada al vector. Eficiencia: O(n).
  * @param i entero cuyo acceso comprobamos: num_eventos > i >= 0.
  * @return True si el acceso es correcto. False en caso contrario.
  */
  void addOrdenado(FechaHistorica* in);
public:
/**
  * @brief Constructor básico de la clase
  */
  Cronologia();
/**
  * @brief Constructor de copia. Hace una copia @e no-profunda.
  * @param cron objeto a copiar.
  */
  Cronologia(const Cronologia &cron);
/**
  * @brief Sobrecarga del operador de asignación. Hace una copia @e no-profunda.
  * @param cron objeto a copiar.
  * @return Referencia al objeto copiado.
  */
  Cronologia& operator = (const Cronologia &cron);
/**
  * @brief Añade una fecha Histórica a la Cronologia.
  * @param fh referencia a añadir.
  */
  void addFechaHistorica(FechaHistorica* fh);
/**
  * @brief Devuelve una Fecha Historica. Devuelve una fecha Historica vacía si no se encuentra en la cronología. Eficiencia: O(log(n)).
  * @param fecha por la que es buscada la Fecha Historica
  * @return Referencia constante a la fecha historica.
  */
  FechaHistorica* getFechaHistorica(int fecha) const;
/**
  * @brief Devuelve el número de fechas históricas almacenadas.
  * @return Número actual de fechas históricas almacenadas.
  */
  int getNumFechasHistoricas() const;
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
  Cronologia subcronologia(int anioDesde, int anioHasta) const;
/**
  * @brief Obtiene la subcronologia con aquellas fechas históricas contengan al menos una vez la clave. Eficiencia: O(n*O(f)), donde f es el método FechaHistorica.contieneClave(string clave).
  * @param clave es la string a buscar.
  * @return Subcronologia mencionada.
  */
  Cronologia subcronologia(string clave) const;
/**
  * @brief Obtiene la unión entre dos cronologías, uniendo fechas históricas si es necesario. Eficiencia: O(m*k), en el peor caso (donde todas las fechas historicas esta duplicadas), donde m = cron.getNumFechasHistoricas() y k es el k = max{cron.v[i].getNumEventos() : 0 <= i < cron.getNumEventos()}.
  * @param cron es la cronología a unir.
  * @return Subcronologia mencionada.
  */
  Cronologia mergeCron(const Cronologia &cron) const;
/**
  * @brief Obtiene la intersección entre dos cronologías, uniendo las fechas históricas. Eficiencia: O(m*k), donde m = interseccion.getNumFechasHistoricas() y k es el k = max{intereseccion.v[i].getNumEventos() : 0 <= i < interseccion.getNumEventos()}.
  * @param cron es la cronología a intersectar.
  * @return Subcronologia mencionada.
  */
  Cronologia intersecCron(const Cronologia &cron) const;
/**
  * @brief Función amiga de la clase, lee una Cronología a través del flujo.
  * @param is referencia al flujo de entrada por el que se leerá el objeto.
  * @param cron referencia a un tipo Fecha Historica en la que se guardarán los datos.
  * @return flujo proporcionado como argumento.
  */
  friend istream& operator >> (istream& is, Cronologia &cron);
};

#endif
