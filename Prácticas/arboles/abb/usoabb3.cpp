#include <iostream>
#include <ABB.h>

using namespace std;

// El programa lee de la entrada estándar dos conjuntos de enteros (número de 
// elementos más los elementos a continuación). Los inserta en dos Árboles 
// Binarios de Búsqueda. Los lista y finalmente los une para obtener el 
// resultado de la unión de ambos conjuntos
 
void listar_abb (const ABB<int>& a){
  ABB<int>::Iterador it;
  
  cout << "Arbol con " << a.size() << " elementos:" << endl;
  for (it=a.primero(); it!=a.final(); it=a.siguiente(it))
    cout << a.etiqueta(it) << ' ';
  cout << endl;
}

int main (int argc, char *argv[]){
  ABB<int> a,b;
  ABB<int>::Iterador it;
  int nelem, valor;
  
  cout << "Numero de elementos del primer arbol: " << endl;
  cin >> nelem;
  while (nelem!=0) {
    cin >> valor;
    a.insertar(valor);
    nelem--;
  }

  cout << "Numero de elementos del segundo arbol: " << endl;
  cin >> nelem;
  while (nelem!=0) {
    cin >> valor;
    b.insertar(valor);
    nelem--;
  }

  cout << "PRIMER ARBOL: "<< endl;
  listar_abb(a);
  cout << "SEGUNDO ARBOL: "<< endl;
  listar_abb(b);

  for (it=b.primero(); it!=b.final(); it=b.siguiente(it))
    a.insertar(b.etiqueta(it));
  
  cout << "UNION: " << endl;
  listar_abb(a);
  
  return 0;
}
