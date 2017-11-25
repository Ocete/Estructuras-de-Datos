/**
 * @file fecha_historica.h
 * @brief Fichero cabecera de la fecha histórica.
 *
 * Se crea un int que almacena el año y un vector_dinamico<strings> para los eventos.
 *
 */

#ifndef _FECHA_HISTORICA_H_
#define _FECHA_HISTORICA_H_

#include <set>
#include <string>
#include "vector_dinamico.h"
using namespace std;

/**
 * @brief Fecha Historica
 *
 * Esta clase almacena un año, y un conjunto no ordenado de eventos.
 * Podemos, entre otras cosas, consultar el número de eventos, acceder a
 * uno específico o comprobar si contiene una clave (string) en alguno de sus eventos.
 */

class FechaHistorica{
private:
  int fecha; /**< Año que representa la fecha histórica. */
  set<string> s; /**< Vector dinámico que almacena los eventos. */
  const char SEPARATOR = '#'; /**< Separador entre eventos al leer datos. */

public:
/**
  * @brief Constructor básico de la clase
  * @param anio fecha en la que ocurren los eventos.
  */
  FechaHistorica(int anio);
/**
  * @brief Constructor de copia. Hace una copia @e profunda.
  * @param fh objeto a copiar.
  */
  FechaHistorica(const FechaHistorica &fh);
/**
  * @brief Sobrecarga del operador de asignación. Hace una copia @e profunda.
  * @param fh objeto a copiar.
  * @return Referencia al objeto copiado.
  */
  FechaHistorica& operator = (const FechaHistorica &fh);
/**
  * @brief Sobrecarga del operador de comparación.
  * @param fh Fecha a comprar.
  * @return True si el @año es el mismo, independientemente de los eventos.
  */
  bool operator == (FechaHistorica fh);
/**
  * @brief Sobrecarga del operador de comparación menor.
  * @param fh Fecha Historica a comprar.
  * @return True si el @e año es el menor, independientemente de los eventos.
  */
  bool operator < (FechaHistorica fh);
/**
  * @brief Sobrecarga del operador de comparación mayor.
  * @param fh Fecha Historica a comprar.
  * @return True si el @e año es el mayor, independientemente de los eventos.
  */
  bool operator > (FechaHistorica fh);
/**
  * @brief Añade un evento a la Fecha Historica. Eficiencia: O(1).
  * @param fh Fecha Historica a comprar.
  * @return True si el @e año es el mayor, independientemente de los eventos.
  */
  void addEvento(string evento);
/**
  * @brief Añade los eventos de la Fecha Historica proporcionado como parámetro. Eficiencia: O(k), k = fh.getNumEventos()
  * @param fh Fecha Historica a unir
  */
  void unir(const FechaHistorica &fh);
/**
  * @brief Devuelve el número de eventos.
  * @return Número actual de eventos en la Fecha Historica.
  */
  int getNumEventos() const;
/**
  * @brief Devuelve el año de la Fecha Histórica.
  * @return Año de la Fecha Historica.
  */
  int getFecha() const;
/**
  * @brief Imprime la Fecha Histórica por pantalla.
  */
  void print() const;
/**
  * @brief Comprueba si la Fecha Historica contiene la clave en alguno de sus eventos. Eficiencia: O(getNumEventos()*m), m = max{getEvento(i).size() : 0 <= i < getNumEventos() }
  * @param clave string a buscar.
  * @return True si la clave aparece en algún evento. False en caso contrario.
  */
  bool contieneClave(string clave) const;
/**
  * @brief Función amiga de la clase, lee una Fecha Historica a través del flujo.
  * @param is referencia al flujo de entrada por el que se leerá el objeto.
  * @param fh referencia a un tipo Fecha Historica en la que se guardarán los datos.
  * @return flujo proporcionado como argumento.
  */
  friend istream& operator >> (istream& is, FechaHistorica &fh);
};

#endif
