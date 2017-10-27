#include "myStack.h"
#include <iostream>

using namespace std;

int main(){


  myStack<int> prueba;
  int numero;

  cout << "Ejemplo usando enteros: " << endl;
  cout << "Introduzca los números que quiere introducir en la pila (-1 para parar): " << endl;

  cin >> numero;
  while(numero != -1){
    prueba.push(numero);
    cout << numero << " introducido. Siguiente: " << endl;
    cin >> numero;
  }

  cout << endl;

  cout << "El tamaño de la pila es: " << prueba.size() << endl;
  cout << "El elemento en el tope es: " << prueba.peak() << endl;

  cout << "-------------" << endl;
  cout << "Quitar elementos de la pila: " << endl;

  int size = prueba.size();
  for(int i = 0; i < size; i++){
    cout << "Nuevo tope: " << prueba.peak() << ".";
    cout << "Tamaño actual: " << prueba.size() << endl;
    cout << "Eliminando tope: " << prueba.pop() << ".";


  }

  cout << endl << "¿Está vacio?" << prueba.isEmpty() << endl;


}
