#include <iostream>
#include <ctime>    // Recursos para medir tiempos
#include <cstdlib>  // Para generación de números pseudoaleatorios

using namespace std;

void mult(int **m1, int **m2, int **m3, int tam) {
  int result;
  for (int i=0; i<tam; i++) {
    for (int j=0; j<tam; j++) {
      result = 0;
      for (int k=0; k<tam; k++) {
        result += m1[i][k] * m2[k][j];
      }
      m3[i][j] = result;
    }
  }
}

void sintaxis()
{
  cerr << "Sintaxis:" << endl;
  cerr << "  TAM: Tamaño del vector (>0)" << endl;
  cerr << "Se generan matrices de tamaño TAM" << endl;
  exit(EXIT_FAILURE);
}

int main(int argc, char * argv[])
{
  // Lectura de parámetros
  if (argc!=2)
    sintaxis();
  int tam=atoi(argv[1]);     // Tamaño de la matriz
  if (tam<=0)
    sintaxis();

  // Generación de las matrices
  int **m1, **m2, **m3;
  m1 = new int*[tam];
  m2 = new int*[tam];
  m3 = new int*[tam];
  for (int i=0; i<tam; i++) {
    m1[i] = new int[tam];
    m2[i] = new int[tam];
    m3[i] = new int[tam];
    for (int j=0; j<tam; j++) {
      m1[i][j] = 2*i-j;
      m2[i][j] = 2*j-i;
    }
  }

  clock_t tini, tfin;
  tini=clock();
  mult(m1, m2, m3, tam);
  tfin=clock();

  cout << tam << "\t" << (tfin-tini)/(double)CLOCKS_PER_SEC << "\t" << (double)CLOCKS_PER_SEC << endl;

  // Liberamos memoria dinámica
  for (int i=0; i<tam; i++) {
    delete [] m1[i];
    delete [] m2[i];
    delete [] m3[i];
  }
  delete [] m1;
  delete [] m2;
  delete [] m3;
}
