#include <iostream>
#include <string>
#include <sstream>
#include "fecha_historica.h"
#include "cronologia.h"
using namespace std;

bool Cronologia::accesoCorrecto(int i) const {
  return i >= 0 && i < getNumFechasHistoricas();
}

// Devuelve la posición de goal si esta en el vector y -1 si no.
int Cronologia::binarySearch (FechaHistorica* goal) const {
  int med, inf = 0, sup = getNumFechasHistoricas()-1;
  bool enc = false;
  while ((inf<sup) && !enc) {
    med = (inf+sup)/2;
    if (v[med]->getFecha() == goal->getFecha()) {
      enc = true;
    } else if (v[med]->getFecha() < goal->getFecha()) {
      inf = med+1;
    } else {
      sup = med-1;
    }
  }
  return enc ? med : -1;
}

void Cronologia::addOrdenado (FechaHistorica* in) {
  if (v.getElems() == 0) {
    v.add(in);
  } else {
    int i = binarySearch(in);
    if (i != -1) {
      v[i]->unir(*in);
    } else {
      i = getNumFechasHistoricas();
      // Ampliamos la CAP antes de empezar a iterar y actualizamos "elems++"
      v.add(NULL);
      while (i > 0 && in->getFecha() < v[i-1]->getFecha()) {
        v[i] = v [i-1];
        i--;
      }
      v[i] = in;
    }
  }
}

Cronologia::Cronologia() { }

Cronologia::Cronologia(const Cronologia &cron) {
  for (int i=0; i<cron.getNumFechasHistoricas(); i++) {
    v.add(cron.v[i]);
  }
}

Cronologia& Cronologia::operator = (const Cronologia &cron) {
  if (this != &cron) {
    v.destroy();
    for (int i=0; i<cron.getNumFechasHistoricas(); i++) {
      v.add(cron.v[i]);
    }
  }
  return *this;
}

void Cronologia::addFechaHistorica(FechaHistorica* fh) {
  addOrdenado(fh);
}

// Si no se encuentra la fecha devuelve una FechaHistorica vacia
FechaHistorica* Cronologia::getFechaHistorica(int fecha) const {
  FechaHistorica* aux = new FechaHistorica(fecha);
  int pos = binarySearch(aux);
  if (pos == -1) {
    return aux;
  } else {
    delete aux;
    return v[pos];
  }
}

int Cronologia::getNumFechasHistoricas() const {
  return v.getElems();
}

void Cronologia::print() const {
  for (int i=0; i<getNumFechasHistoricas(); i++) {
    v[i]->print();
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
