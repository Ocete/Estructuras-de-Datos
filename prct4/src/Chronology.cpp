#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <utility>
#include "historic_date.h"
#include "Chronology.h"
using namespace std;

Chronology::Chronology(){}

Chronology& Chronology::operator = (const Chronology &cron) {
  if (this != &cron) {
    m.clear();
    iterator it;
    for (it=begin(); it!=end(); it++) {
      insert(it->second);
    }
  }
  return *this;
}

std::pair<Chronology::iterator, bool> Chronology::insert(HistoricDate* fh) {

  std::pair<Chronology::iterator, bool> inserted;
  int date = fh->getDate();

  inserted = m.insert(std::pair<int,HistoricDate*> (date,fh));
  return inserted;
}

// Si no se encuentra la fecha devuelve NULL
HistoricDate* Chronology::getHistoricDate(int fecha) const {
  map<int, HistoricDate*>::const_iterator it = m.find(fecha);
  if (it != m.end()) {
    return it->second;
  } else {
    return NULL;
  }
}

int Chronology::getNumHistoricDates() const {
  return m.size();
}

void Chronology::print() const {
  for (Chronology::const_iterator it=cbegin(); it!=cend(); it++) {
    it->second->print();
  }
}

// subcronologia entre dos fechas
Chronology Chronology::subChronology(int anioDesde, int anioHasta) const {
  Chronology result;
  map<int, HistoricDate*>::const_iterator it = m.begin();
  while (it != m.end() && it->second->getDate() <= anioHasta) {
    if (it->second->getDate() >= anioDesde) {
      result.insert(it->second);
    }
    it++;
  }
  return result;
}

Chronology Chronology::subChronology(string key) const {
  Chronology cron;
  map<int, HistoricDate*>::const_iterator it;
  for (it=m.begin(); it != m.end(); it++) {
    if (it->second->includesKey(key)) {
      cron.insert(it->second);
    }
  }
  return cron;
}

// Unión de dos cronologías
Chronology Chronology::mergeCron(const Chronology &cron) const {
  Chronology result;
  Chronology::const_iterator it, aux;

  for (it = m.begin(); it!=m.end(); it++) {
    result.insert(it->second);
  }
  for (it = cron.begin(); it!=cron.end(); it++) {
    aux = result.m.find(it->second->getDate());
    if (aux == result.end()) {
      result.insert(aux->second);
    } else {
      aux->second->merge(*(it->second));
    }
  }
  return result;
}

// Toma unicamente las fechas que estén en ambas cronologías, tomando de ellas
// todos los eventos.
Chronology Chronology::intersecCron(const Chronology &cron) const {
  Chronology result;
  map<int, HistoricDate*>::const_iterator it, aux;
  for (it = m.begin(); it!=m.end(); it++) {
    aux = cron.m.find(it->second->getDate());
    if (aux != cron.m.end()) {
      result.insert(aux->second);
      aux = result.m.find(it->second->getDate());
      aux->second->merge(*(it->second));
    }
  }
  return result;
}

istream& operator >> (istream& is, Chronology &cron) {
  string line;
  cron.m.clear();
  HistoricDate* fh = NULL;
  while( is.good() ) {
    fh = new HistoricDate(0);
    getline(is, line, cron.SEPARATOR);
    istringstream ss(line);
    ss >> *fh;
    cron.insert(fh);
  }
  return is;
}

Chronology::iterator Chronology::begin() {
  return m.begin();
}

Chronology::const_iterator Chronology::cbegin() const {
  return m.cbegin();
}

Chronology::iterator Chronology::end() {
  return m.end();
}

Chronology::const_iterator Chronology::cend() const {
  return m.cend();
}
