#include <iostream>
#include <ABB.h>

using namespace std;

// El programa lee de la entrada estándar un conjunto de enteros hasta el fin 
// de la entrada (EOF). Después los lista todos, ordenados y sin repeticiones
    
int main (int argc, char *argv[]){
  ABB<int> a;
  int valor;
  ABB<int>::Iterador it;
  
  while (cin>>valor){
    a.insertar(valor);
  }

  for (it=a.primero(); it!=a.final(); it=a.siguiente(it))
    cout << a.etiqueta(it) << ' ';
  cout << endl;
    
  return 0;
}
