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
    map<int,HistoricDate*>::const_iterator it;
    for (it=cron.m.begin(); it!=cron.m.end(); it++) {
      addHistoricDate(it->second);
    }
  }
  return *this;
}

void Cronology::addHistoricDate(HistoricDate* fh) {
  m[fh->getDate()] = fh;
}

// Si no se encuentra la fecha devuelve NULL
HistoricDate* Cronology::getHistoricDate(int fecha) const {
  map<int, HistoricDate*>::const_iterator it = m.find(fecha);
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
  for (map<int,HistoricDate*>::const_iterator it=m.begin(); it!=m.end(); it++) {
    it->second->print();
  }
}

// subcronologia entre dos fechas
Cronology Cronology::subcronology(int anioDesde, int anioHasta) const {
  Cronology result;
  map<int, HistoricDate*>::const_iterator it = m.begin();
  while (it != m.end() && it->second->getDate() <= anioHasta) {
    if (it->second->getDate() >= anioDesde) {
      result.addHistoricDate(it->second);
    }
    it++;
  }
  return result;
}

Cronology Cronology::subcronology(string key) const {
  Cronology cron;
  map<int, HistoricDate*>::const_iterator it;
  for (it=m.begin(); it != m.end(); it++) {
    if (it->second->includesKey(key)) {
      cron.addHistoricDate(it->second);
    }
  }
  return cron;
}

// Unión de dos cronologías
Cronology Cronology::mergeCron(const Cronology &cron) const {
  Cronology result;
  map<int, HistoricDate*>::const_iterator it, aux;

  for (it = m.begin(); it!=m.end(); it++) {
    result.addHistoricDate(it->second);
  }
  for (it = cron.m.begin(); it!=cron.m.end(); it++) {
    aux = result.m.find(it->second->getDate());
    if (aux == result.end()) {
      result.addHistoricDate(aux->second);
    } else {
      aux->second->merge(*(it->second));
    }
  }
  return result;
}

// Toma unicamente las fechas que estén en ambas cronologías, tomando de ellas
// todos los eventos.
Cronology Cronology::intersecCron(const Cronology &cron) const {
  Cronology result;
  map<int, HistoricDate*>::const_iterator it, aux;
  for (it = m.begin(); it!=m.end(); it++) {
    aux = cron.m.find(it->second->getDate());
    if (aux != cron.m.end()) {
      result.addHistoricDate(aux->second);
      aux = result.m.find(it->second->getDate());
      aux->second->merge(*(it->second));
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
    cron.addHistoricDate(fh);
  }
  return is;
}

Cronology::iterator begin() {
  map<int, HistoricDate*>::iterator it = m.begin();
  return it;
}

Cronology::const_iterator Cronology::cbegin() {
  map<int, HistoricDate*>::const_iterator it = m.cbegin();
  return it;
}

Cronology::iterator Cronology::end() {
  map<int, HistoricDate*>::iterator it = m.end();
  return it;
}

Cronology::const_iterator Cronology::cend() {
  map<int, HistoricDate*>::const_iterator it = m.cend();
  return it;
}
