#ifndef _FECHA_HISTORICA_H_
#define _FECHA_HISTORICA_H_

#include <string>
#include "vector_dinamico.h"
using namespace std;

class FechaHistorica{
private:
  int fecha;
  vector_dinamico<string> v;
  const char SEPARATOR = '#';
  bool accesoCorrecto(int i) const;
public:
  FechaHistorica(int anio);
  FechaHistorica(const FechaHistorica &fh);
  FechaHistorica& operator = (const FechaHistorica &fh);
  bool operator == (FechaHistorica fh);
  bool operator < (FechaHistorica fh);
  bool operator > (FechaHistorica fh);
  void addEvento(string evento);
  void unir(const FechaHistorica &fh);
  string getEvento(int i) const;
  int getNumEventos() const;
  int getFecha() const;
  void print() const;
  bool contieneClave(string clave) const;
  friend istream& operator >> (istream& is, FechaHistorica &fh);
};

#endif
