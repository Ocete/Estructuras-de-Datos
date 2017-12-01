#include "historic_date.h"
#include <iostream>
#include <sstream> // Para el flujo de entrada
using namespace std;

HistoricDate::HistoricDate(int year){
  date = year;
}

HistoricDate::HistoricDate(const HistoricDate &hd) {
  date = hd.date;
  for (set<string>::iterator it=hd.s.begin(); it!=hd.s.end(); it++) {
    s.insert(*it);
  }
}

HistoricDate& HistoricDate::operator=(const HistoricDate &hd) {
  if (this != &hd) {
    s.clear();
    date = hd.date;
    for (set<string>::iterator it=hd.s.begin(); it!=hd.s.end(); it++) {
      s.insert(*it);
    }
  }
  return *this;
}

bool HistoricDate::operator==(HistoricDate hd) {
  return date == hd.date;
}

bool HistoricDate::operator<(HistoricDate hd) {
  return date < hd.date;
}

bool HistoricDate::operator>(HistoricDate hd) {
  return date > hd.date;
}


void HistoricDate::addEvent(string event) {
  s.insert(event);
}

// Si hay eventos dobles, set se foundarga de ellos
//pongo este const bien chulo de aquí porque si no las funciones constantes
//que lo llaman dan errores
void HistoricDate::merge(const HistoricDate &hd){
  for (HistoricDate::const_iterator it=hd.cbegin(); it!=hd.cend(); it++) {
    s.insert(*it);
  }
}

int HistoricDate::getNumEvents() const {
  return s.size();
}

int HistoricDate::getDate() const {
  return date;
}

void HistoricDate::print(){
  cout << "Año " << date << ":" << endl;
  for (HistoricDate::const_iterator it=cbegin(); it!=cend(); it++) {
    cout << "\t" << *it << endl;
  }
}

bool HistoricDate::includesKey(string key) const {
  bool found = false;
  set<string>::iterator it = s.begin();
  size_t pos;
  while (!found && it != s.end()) {
    pos = it->find(key);
    found = pos != string::npos;
    it++;
  }
  return found;
}

istream& operator >> (istream& is, HistoricDate &hd) {
  string lecture;
  getline(is, lecture, hd.SEPARATOR);
  hd.date = stoi(lecture);

  while( is.good() ) {
      string event;
      getline(is, event, hd.SEPARATOR);
      hd.s.insert(event);
  }
  return is;
}

ostream& operator<<(ostream& os, const HistoricDate& hd){
  HistoricDate::iterator it;
  os << hd.date;
  for(it=hd.cbegin(); it!=hd.cend(); ++it){
    os << '#';
    os << (*it);
  }
  return os;
}

HistoricDate::iterator HistoricDate::begin() {
  return s.begin();
}

HistoricDate::const_iterator HistoricDate::cbegin() const{
  return s.cbegin();
}

HistoricDate::iterator HistoricDate::end() {
  return s.end();
}

HistoricDate::const_iterator HistoricDate::cend() const{
  return s.cend();
}
