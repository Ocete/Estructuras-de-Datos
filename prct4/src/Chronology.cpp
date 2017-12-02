#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <utility>
#include "historic_date.h"
#include "Chronology.h"
using namespace std;

Chronology::Chronology(){}

Chronology::Chronology(const Chronology &cron) {
  cout << "COPIANDO" << endl;
  m.clear();
  for (iterator it=begin(); it!=end(); it++) {
    insert(it->second);
  }
}

Chronology& Chronology::operator = (const Chronology &cron) {
  cout << "ASIGNANDO" << endl;

  if (this != &cron) {
    m.clear();
    iterator it;
    for (iterator it=begin(); it!=end(); it++) {
      insert(it->second);
    }
  }
  return *this;
}

std::pair<Chronology::iterator, bool> Chronology::insert(HistoricDate fh) {
  std::pair<Chronology::iterator, bool> inserted;
  int date = fh.getDate();

  inserted = m.insert(std::pair<int,HistoricDate> (date,fh));
  return inserted;
}

// Si no se encuentra la fecha devuelve NULL
HistoricDate Chronology::getHistoricDate(int fecha) {
  Chronology::const_iterator it = m.find(fecha);
  if (it != m.end()) {
    return it->second;
  } else {
    return HistoricDate(-1);
  }
}

void Chronology::print() const {
  for (Chronology::const_iterator it=cbegin(); it!=cend(); it++) {
    it->second.print();
    cout << "\n" << endl;
  }
}

void Chronology::clear() {
  m.clear();
}

// subcronologia entre dos fechas
Chronology Chronology::subChronology(int anioDesde, int anioHasta) const {
  Chronology result;
  Chronology::const_iterator it = m.begin();
  while (it != m.end() && it->second.getDate() <= anioHasta) {
    if (it->second.getDate() >= anioDesde) {
      result.insert(it->second);
    }
    it++;
  }
  return result;
}

Chronology Chronology::subChronology(string key) const {
  Chronology cron;
  Chronology::const_iterator it;
  HistoricDate::iterator hit;
  for (it=m.begin(); it != m.end(); it++) {
    if (it->second.includesKey(key)) {
      //We have to add just the events with the word
      HistoricDate event(it->first);
      //Insert a Historic Date with all the event only containing key
      event.merge(it->second.findAll(key));
      cron.insert(event);
    }
  }
  return cron;
}

// Unión de dos cronologías
void Chronology::mergeCron(Chronology &cron, Chronology &result) {
  result.clear();
  Chronology::iterator aux;
  Chronology::iterator it;

  for (it = begin(); it!=end(); it++) {
    result.insert(it->second);
  }
  for (it = cron.begin(); it!=cron.end(); it++) {
    aux = result.m.find(it->second.getDate());
    if (aux == result.end()) {
      result.insert(it->second);
    } else {
      aux->second.merge(it->second);
    }
  }
}

// Toma unicamente las fechas que estén en ambas cronologías, tomando de ellas
// todos los eventos.
void Chronology::intersecCron(Chronology &cron, Chronology &result) {
  result.clear();
  Chronology::iterator it;
  Chronology::iterator aux;
  for (it = begin(); it!=end(); it++) {
    aux = cron.m.find(it->second.getDate());
    if (aux != cron.end()) {
      result.insert(aux->second);
      aux = result.m.find(it->second.getDate());
      aux->second.merge(it->second);
    }
  }
}

istream& operator >> (istream& is, Chronology &cron) {
  string line;
  cron.m.clear();
  HistoricDate fh;
  while( is.good() ) {
    getline(is, line, cron.SEPARATOR);
    istringstream ss(line);
    ss >> fh;
    cron.insert(fh);
  }
  return is;
}

ostream& operator<<(ostream& os, const Chronology& cron) {
  Chronology::const_iterator it;
  for(it=cron.cbegin(); it!=cron.cend(); ++it){
    os << it->second << std::endl;
    cout << endl;
  }
  return os;
}

double Chronology::mean(){
  double result = (numEvents() + 0.0) / numYears();
  return result;
}

HistoricDate Chronology::trend(){
  Chronology::const_iterator it;
  int num_eventos = -1;
  int year;

  for (it=m.begin(); it != m.end(); it++) {
    if(it->second.getNumEvents() > num_eventos){
      num_eventos = it->second.getNumEvents();
      year = it->second.getDate();
    }
  }


  return m.at(year);
}

int Chronology::numYears(){
  return m.size();
}

int Chronology::numEvents(){
  Chronology::const_iterator it;
  int num = 0;
  for (it=m.begin(); it != m.end(); it++) {
    num += (it->second).getNumEvents();
  }
  return num;
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
