#include <iostream>
#include <cstdlib>
#include <ctime>    // Recursos para medir tiempos

using namespace std;

void ordenar(int *v, int n) {
  for (int i=0; i<n-1; i++)
    for (int j=0; j<n-i-1; j++)
      if (v[j]>v[j+1]) {
        int aux = v[j];
        v[j] = v[j+1];
        v[j+1] = aux;
      }
}

void sintaxis()
{
  cerr << "Sintaxis:" << endl;
  cerr << "  TAM: Tamaño del vector (>0)" << endl;
  cerr << "  VMAX: Valor máximo (>0)" << endl;
  cerr << "Se genera un vector de tamaño TAM con elementos aleatorios en [0,VMAX[" << endl;
  exit(EXIT_FAILURE);
}

int main(int argc, char * argv[])
{
  // Lectura de parámetros
  if (argc!=4)
    sintaxis();
  int tam=atoi(argv[1]);     // Tamaño del vector
  int vmax=atoi(argv[2]);    // Valor máximo
  bool mejor=atoi(argv[3]);
  if (tam<=0 || vmax<=0)
    sintaxis();

  // Generación del vector aleatorio
  int *v=new int[tam];
  if (mejor) {
    for (int i=0; i<tam; i++) {
      v[i] = i;
    }
  } else {
    for (int i=0; i<tam; i++) {
      v[i] = tam - i;
    }
  }

  clock_t tini, tfin;
  tini=clock();
  ordenar(v,tam);
  tfin=clock();

  // Mostramos resultados
  cout << tam << "\t" << (tfin-tini)/(double)CLOCKS_PER_SEC << "\t" << (double)CLOCKS_PER_SEC << endl;

  delete [] v;
}
