#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include "fecha_historica.h"
#include "cronologia.h"
using namespace std;

Cronologia& Cronologia::operator = (const Cronologia &cron) {
  if (this != &cron) {
    m.clear();
    for (map<int,FechaHistorica*>::iterator it=cron.m.begin(); it!=cron.m.end(); it++) {
      m.insert(*it);
    }
  }
  return *this;
}

void Cronologia::addFechaHistorica(FechaHistorica* fh) {
  m[fh->getFechaHistorica()] = fh;
}

// Si no se encuentra la fecha devuelve NULL
FechaHistorica* Cronologia::getFechaHistorica(int fecha) const {
  map<int, FechaHistorica*>::iterator it = m.find(fecha);
  if (it != m.end()) {
    return it->second;
  } else {
    return NULL;
  }
}

int Cronologia::getNumFechasHistoricas() const {
  return m.size();
}

void Cronologia::print() const {
  for (map<int,FechaHistorica*>::iterator it=cron.m.begin(); it!=cron.m.end(); it++) {
    it->second->print();
  }
}

// subcronologia entre dos fechas
Cronologia Cronologia::subcronologia(int anioDesde, int anioHasta) const {
  Cronologia cron;
  FechaHistorica *aux = NULL;
  int i=0;
  while (i<getNumFechasHistoricas() && v[i]->getFecha() <= anioHasta) {
    if (v[i]->getFecha() >= anioDesde) {
      aux = v[i];
      cron.v.add(aux);
    }
    i++;
  }
  return cron;
}

Cronologia Cronologia::subcronologia(string clave) const {
  Cronologia cron;
  FechaHistorica *aux = NULL;
  for (int i=0; i<getNumFechasHistoricas(); i++) {
    if (v[i]->contieneClave(clave)) {
      aux = v[i];
      cron.v.add(aux);
    }
  }
  return cron;
}

// Unión de dos cronologías
Cronologia Cronologia::mergeCron(const Cronologia &cron) const {
  Cronologia result;
  FechaHistorica* fh;
  int i = 0, j = 0;

  while (i<getNumFechasHistoricas() && j<cron.getNumFechasHistoricas()) {
    if (v[i]->getFecha() < cron.v[j]->getFecha()) {
      fh = new FechaHistorica(*v[i]);
      i++;
    } else if (v[i]->getFecha() == cron.v[j]->getFecha()) {
      fh = new FechaHistorica(*v[i]);
      fh->unir(*cron.v[j]);
      i++;
      j++;
    } else {
      fh = new FechaHistorica(*cron.v[j]);
      j++;
    }
    result.v.add(fh);
  }

  while (i<getNumFechasHistoricas()) {
    fh = new FechaHistorica(*v[i]);
    result.v.add(fh);
    i++;
  }

  while (j<cron.getNumFechasHistoricas()) {
    fh = new FechaHistorica(*cron.v[j]);
    result.v.add(fh);
    j++;
  }

  return result;
}

// Toma unicamente las fechas que estén en ambas cronologías, tomando de ellas
// todos los eventos.
Cronologia Cronologia::intersecCron(const Cronologia &cron) const {
  Cronologia result;
  int i = 0, j = 0;
  FechaHistorica* fh;
  while (i<getNumFechasHistoricas() && j<cron.getNumFechasHistoricas()) {
    if (v[i]->getFecha() < cron.v[j]->getFecha()) {
      i++;
    } else if (v[i]->getFecha() == cron.v[j]->getFecha()) {
      fh = new FechaHistorica(*v[i]);
      fh->unir(*cron.v[j]);
      result.v.add(fh);
      i++;
      j++;
    } else {
      j++;
    }
  }
  return result;
}

istream& operator >> (istream& is, Cronologia &cron) {
  string line;
  cron.v.destroy();
  FechaHistorica* fh = NULL;
  while( is.good() ) {
    fh = new FechaHistorica(0);
    getline(is, line, cron.SEPARATOR);
    istringstream ss(line);
    ss >> *fh;
    cron.v.add(fh);
  }
  return is;
}
