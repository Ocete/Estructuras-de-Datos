#include "fecha_historica.h"
#include <iostream>
#include <sstream> // Para el flujo de entrada
using namespace std;

bool FechaHistorica::accesoCorrecto(int i) const {
  return i >= 0 && i < getNumEventos();
}

FechaHistorica::FechaHistorica(int anio){
  fecha = anio;
}

FechaHistorica::FechaHistorica(const FechaHistorica &fh) {
  fecha = fh.fecha;
  for (int i=0; i<fh.getNumEventos(); i++) {
    v.add(fh.v[i]);
  }
}

FechaHistorica& FechaHistorica::operator=(const FechaHistorica &fh) {
  if (this != &fh) {
    v.destroy();
    fecha = fh.fecha;
    for (int i=0; i<fh.getNumEventos(); i++) {
      v.add(fh.v[i]);
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
  v.add(evento);
}

// Suponemos que no hay eventos dobles
void FechaHistorica::unir(const FechaHistorica &fh) {
  for (int i=0; i<fh.getNumEventos(); i++) {
    v.add(fh.v[i]);
  }
}

string FechaHistorica::getEvento(int i) const {
  return accesoCorrecto(i) ? v[i]: "ERROR";
}

int FechaHistorica::getNumEventos() const {
  return v.getElems();
}

int FechaHistorica::getFecha() const {
  return fecha;
}

void FechaHistorica::print() const {
  cout << "Año " << fecha << ":" << endl;
  for (int i=0; i<getNumEventos(); i++) {
    cout << "\t" << v[i] << endl;
  }
}

bool FechaHistorica::contieneClave(string clave) const {
  int i = 0;
  bool enc = false;
  std::size_t pos;
  while (!enc && i<getNumEventos()) {
    pos = v[i].find(clave);
    enc = pos != string::npos;
    i++;
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
      fh.v.add(evento);
  }
  return is;
}
