// José Antonio Álvarez Ocete
// Yábir García Benchakhtir

#include <iostream>
#include <stack.h>

using namespace std;



string metodo_compilacion(){
  string metodo;

  #if CUAL_COMPILA==1
  metodo = "Compilado usando Vector Dinamico.";
  #elif CUAL_COMPILA==2
  metodo = "Compilado usando Lista de Celdas enlazadas.";
  #else
  metodo = "Compilado usando Cola.";
  #endif

  return metodo;
}


int main() {
  StackMax<int> prueba;
  int numero;
  string mensaje;

  cout << metodo_compilacion() << endl;

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

  cout << "El tamaño de la pila es: " << prueba.size() << endl;
  cout << "El elemento en el tope es: " << prueba.peak() << endl;

  cout << "-------------" << endl;
  cout << "Quitar elementos de la pila: " << endl;

  int size = prueba.size();
  for(int i = 0; i < size; i++){
    cout << "Tope: (" << prueba.peak() << ", " << prueba.max() << "). ";
    cout << "Tamaño actual: " << prueba.size() << endl;
    cout << "Eliminando tope: " << prueba.pop() << ".";
  }

  if(prueba.isEmpty())
    mensaje = "Sí está vacio.";
  else
    mensaje = "No está vacio.";

  cout << endl << "¿Está vacio? " << mensaje << endl;

}
