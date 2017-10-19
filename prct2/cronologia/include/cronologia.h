#ifndef _CRONOLOGIA_H_
#define _CRONOLOGIA_H_

#include <string>
#include "fecha_historica.h"
#include "vector_dinamico.h"

class Cronologia{
private:
  vector_dinamico<FechaHistorica *> v;
  const char SEPARATOR = '\n';
  bool accesoCorrecto(int i) const;
  int binarySearch (FechaHistorica* goal) const ;
  void addOrdenado(FechaHistorica* in);
public:
  Cronologia();
  Cronologia(const Cronologia &cron);
  Cronologia& operator = (const Cronologia &cron);
  void addFechaHistorica(FechaHistorica* fh);
  FechaHistorica* getFechaHistorica(int fecha) const;
  int getNumFechasHistoricas() const;
  void print() const;
  Cronologia subcronologia(int anioDesde, int anioHasta) const;
  Cronologia subcronologia(string clave) const;
  Cronologia mergeCron(const Cronologia &cron) const;
  Cronologia intersecCron(const Cronologia &cron) const;
  friend istream& operator >> (istream& is, Cronologia &cron);
};

#endif
