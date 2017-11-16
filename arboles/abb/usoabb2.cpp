#include <iostream>
#include <ABB.h>

using namespace std;

// El programa lee de la entrada estándar un conjunto de enteros hasta el fin 
// de la entrada (EOF), borra todos los elementos impares del conjunto y 
// finalmente lista todos los pares, ordenados
 
int main (int argc, char *argv[]){
  ABB<int> a;
  int valor;
  ABB<int>::Iterador it;

  while (cin>>valor) {
    a.insertar(valor);
  }

  for (it=a.primero(); it!=a.final(); )
    if (a.etiqueta(it)%2==1)
      it = a.borrar(it);
    else
      it = a.siguiente(it);

  for (it=a.primero(); it!=a.final(); it=a.siguiente(it))
    cout << a.etiqueta(it) << ' ';
  cout << endl;

  return 0;
}
