#include "fecha_historica.h"
#include <iostream>
#include <sstream> // Para el flujo de entrada
using namespace std;

FechaHistorica::FechaHistorica(int anio){
  fecha = anio;
}

FechaHistorica::FechaHistorica(const FechaHistorica &fh) {
  fecha = fh.fecha;
  for (set<string>::iterator it=fh.s.begin(); it!=fh.s.end(); it++) {
    s.insert(*it);
  }
}

FechaHistorica& FechaHistorica::operator=(const FechaHistorica &fh) {
  if (this != &fh) {
    s.clear();
    fecha = fh.fecha;
    for (set<string>::iterator it=fh.s.begin(); it!=fh.s.end(); it++) {
      s.insert(*it);
    }
  }
  return *this;
}

bool FechaHistorica::operator==(FechaHistorica fh) {
  return fecha == fh.fecha;
}

bool FechaHistorica::operator<(FechaHistorica fh) {
  return fecha < fh.fecha;
}

bool FechaHistorica::operator>(FechaHistorica fh) {
  return fecha > fh.fecha;
}


void FechaHistorica::addEvento(string evento) {
  s.insert(evento);
}

// Si hay eventos dobles, set se encarga de ellos
void FechaHistorica::unir(const FechaHistorica &fh) {
  for (set<string>::iterator it=fh.s.begin(); it!=fh.s.end(); it++) {
    s.insert(*it);
  }
}

int FechaHistorica::getNumEventos() const {
  return s.size();
}

int FechaHistorica::getFecha() const {
  return fecha;
}

void FechaHistorica::print() const {
  cout << "Año " << fecha << ":" << endl;
  for (set<string>::iterator it=fh.s.begin(); it!=fh.s.end(); it++) {
    cout << "\t" << *it << endl;
  }
}

bool FechaHistorica::contieneClave(string clave) const {
  bool enc = false;
  set<string>::iterator it = s.begin();
  size_t pos;
  while (!enc && it != s.end()) {
    pos = it->find(clave);
    enc = pos != string::npos;
    it++;
  }
  return enc;
}

istream& operator >> (istream& is, FechaHistorica &fh) {
  string lectura;
  getline(is, lectura, fh.SEPARATOR);
  fh.fecha = stoi(lectura);

  while( is.good() ) {
      string evento;
      getline(is, evento, fh.SEPARATOR);
      fh.s.insert(evento);
  }
  return is;
}
