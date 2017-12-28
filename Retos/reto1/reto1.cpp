#include <iostream>
#include <cmath>
using namespace std;

int main() {
  const int MAX_TIEMPOS = 5, F=1000000;
  long int tiempos[MAX_TIEMPOS] = {1, 3600, 604800, 9198000, 9198000000},
    aux, j;
  int i, step;

  for (i=0; i<MAX_TIEMPOS; i++) {
    cout << "f(n) = log2(n), t = " << tiempos[i] << " -> n = 10^" <<
        F*tiempos[i]*log(2) << endl;
  }

  for (i=0; i<MAX_TIEMPOS; i++) {
    cout << "f(n) = n, t = " << tiempos[i] << " -> n = " <<
        F*tiempos[i] << endl;
  }

  // f(n) = n*log2(n);
  i=0;
  step = 10000;
  j=step;
  while (i<MAX_TIEMPOS) {
    if (i==4) {
      step*=100;
    }
    while (j*log2(j)/F < tiempos[i]) {
      j+=step;
      //cout << j*log2(j)/F << endl;
    }
    cout << "f(n) = n*log2(n), t = " << tiempos[i] << " -> n = " << j << endl;
    i++;
  }

  // f(n) = n^3;
  i=0;
  j=1;
  while (i<MAX_TIEMPOS) {
    while (j*j*j/F < tiempos[i]) {
      j+=1;
    }
    cout << "f(n) = n^3, t = " << tiempos[i] << " -> n = " << j-1 << endl;
    i++;
  }

  // f(n) = 2^n ;
  i=0;
  j=1;
  aux = 2;
  while (i<MAX_TIEMPOS) {
    while (aux/F < tiempos[i]) {
      j+=1;
      aux*=2;
    }
    cout << "f(n) = 2^n, t = " << tiempos[i] << " -> n = " << j-1 << endl;
    i++;
  }

  // f(n) = n! ;
  i=0;
  j=1;
  aux = 1;
  while (i<MAX_TIEMPOS) {
    while (aux/F < tiempos[i]) {
      j+=1;
      aux*=j;
    }
    cout << "f(n) = n!, t = " << tiempos[i] << " -> n = " << j-1 << endl;
    i++;
  }
}
