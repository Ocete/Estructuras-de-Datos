#include <iostream>
#include "StackMax.h"
using namespace std;

int main() {
  StackMax<int> prueba;
  int numero;
  string mensaje;

  cout << "Ejemplo usando enteros: " << endl;
  cout << "Introduzca los números que quiere introducir en la pila (-1 para parar): " << endl;

  cin >> numero;
  while(numero != -1){
    prueba.push(numero);
    //prueba_own.push(numero);
    cout << numero << " introducido. Siguiente: " << endl;
    cin >> numero;
  }

  cout << endl;

}
