#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include "historic_date.h"
#include "cronology.h"
using namespace std;

Cronology& Cronology::operator = (const Cronology &cron) {
  if (this != &cron) {
    m.clear();
    for (map<int,HistoricDate*>::iterator it=cron.m.cbegin(); it!=cron.m.end(); it++) {
      m.addHistoricDate(it);
    }
  }
  return *this;
}

void Cronology::addHistoricDate(HistoricDate* fh) {
  m[fh->getDate()] = fh;
}

// Si no se encuentra la fecha devuelve NULL
HistoricDate* Cronology::getHistoricDate(int fecha) const {
  map<int, HistoricDate*>::iterator it = m.find(fecha);
  if (it != m.end()) {
    return it->second;
  } else {
    return NULL;
  }
}

int Cronology::getNumHistoricDates() const {
  return m.size();
}

void Cronology::print() const {
  for (map<int,HistoricDate*>::iterator it=cron.m.begin(); it!=cron.m.end(); it++) {
    it->second->print();
  }
}

// subcronologia entre dos fechas
Cronology Cronology::subcronology(int anioDesde, int anioHasta) const {
  Cronology result;
  map<int, HistoricDate*>::iterator it = m.begin();
  while (it != m.end() && it->getDate() <= anioHasta) {
    if (it->getDate() >= anioDesde) {
      result.addHistoricDate(it);
    }
    it++;
  }
  return cron;
}

Cronology Cronology::subcronology(string key) const {
  Cronology cron;
  map<int, HistoricDate*>::iterator it;
  for (it=m.begin(); it != m.end(); it++) {
    if (it->includesKey(key)) {
      cron.addHistoricDate(it);
    }
  }
  return cron;
}

// Unión de dos cronologías
Cronology Cronology::mergeCron(const Cronology &cron) const {
  Cronology result;
  map<int, HistoricDate*>::iterator it, aux;

  for (it = m.begin(); it!=m.end(); it++) {
    result.addHistoricDate(it);
  }
  for (it = cron.m.begin(); it!=cron.m.end(); it++) {
    aux = result.m.find(it->getDate());
    if (aux == result.end()) {
      result.addHistoricDate();
    } else {
      aux->merge(*it);
    }
  }
  return result;
}

// Toma unicamente las fechas que estén en ambas cronologías, tomando de ellas
// todos los eventos.
Cronology Cronology::intersecCron(const Cronology &cron) const {
  Cronology result;
  map<int, HistoricDate*>::iterator it, aux;
  for (it = m.begin(); it!=m.end(); it++) {
    aux = cron.m.find(it->getDate());
    if (aux != cron.m.end()) {
      result.addHistoricDate(aux);
      aux = result.m.find(it->getDate);
      aux->merge(*it);
    }
  }
  return result;
}

istream& operator >> (istream& is, Cronology &cron) {
  string line;
  cron.m.clear();
  HistoricDate* fh = NULL;
  while( is.good() ) {
    fh = new HistoricDate(0);
    getline(is, line, cron.SEPARATOR);
    istringstream ss(line);
    ss >> *fh;
    cron.m.addHistoricDate(fh);
  }
  return is;
}
