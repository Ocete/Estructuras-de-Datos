#include <iostream>
#include <set>
#include <ctime>
#include <cstdlib>
using namespace std;

/**
 * @brief Imprime un conjunto de tipo T sobre el flujo de salida
 * @param s: flujo de salida. Es MODIFICADO
 * @param l: el conjunto con los elementos a imprimi
 * */
template <class T>
ostream & operator<<(ostream & s, const set<T> & c){

  typename set<T>::const_iterator i;

  s << "{ ";
  for (i=c.begin(); i != c.end(); i++)
      s << (*i) << " ";
  s << "}";
  return s;
}

/**
 * @brief Inicializar el generador de numero aleatorios
 *        Esta funcion debe ser llamada antes de usar rand
**/

void InicializarSemilla(){
  srand(time(0));
}

/**
 * @brief Genera numero enteros positivos aleatorios en el rango [min,max]
**/

int generaEntero(int min, int max){
    int tam= max -min+1;
    return ((rand()%tam)+min);
}

/*
  Denotando S1 = s1.size(), S2 = s2.size() y S3 = s3.size(), la eficiencia de este algoritmo es:
    S1 * (log (S2) + log (S3))

  Suponiendo que el método size() fuese de orden O(1) ó O(log(n)), sería más eficiente
    calcular el tamaño de los tres y recorrer el más pequeño en vez de S1.
*/
template <class T>
void interseccionATres(const set<T>& s1, const set<T>& s2, const set<T>& s3, set<T>& result) {
  result.clear();
  typename set<T>::iterator it;
  for (it = s1.begin(); it != s1.end(); it++) {
    if (s2.count(*it) > 0 && s3.count(*it) > 0) {
      result.insert(*it);
    }
  }
}


/*
  Añade a result los elementos de s1 que no están ni en s2 ni en s3

  Manteniendo la misma notación, la eficiencia de esta función es de:
    S1 * (log (S2) + log (S3))
*/
template <class T>
void unionDiferencialParcial(const set<T>& s1, const set<T>& s2, const set<T>& s3, set<T>& result) {
  for (typename set<T>::iterator it = s1.begin(); it != s1.end(); it++) {
    if (s2.count(*it) == 0 && s3.count(*it) == 0) {
      result.insert(*it);
    }
  }
}

/*
    Podríamos calcular la unión de los tres conjuntos y quitarle la intersección
    dos a dos: AUBUC \ (intersec(A,B) U intersec(A,C) U intersec(B,C))
    Esto sería tremendamente más costoso ya que para conjuntos grandes con muchos
    elementos en la interseccion de los 3 estaríamos copiando los mismos valores varias veces.

    Manteniendo la misma notación, la eficiencia de esta función es de:
      S1 * (log (S2) + log (S3)) +
      S2 * (log (S1) + log (S3)) +
      S3 * (log (S1) + log (S2))
    Esto es lo mismo, en notación O(n), al máximo valor de los tres sumandos
*/
template <class T>
void unionDiferencial(const set<T>& s1, const set<T>& s2, const set<T>& s3, set<T>& result) {
  result.clear();
  unionDiferencialParcial(s1, s2, s3, result);
  unionDiferencialParcial(s2, s1, s3, result);
  unionDiferencialParcial(s3, s1, s2, result);
}

int main(){

  set<int> s1, s2, s3, result;

  InicializarSemilla();

  // He puesto estos valores para los números aleatorios (1, 20) porque creo que
  // se ve más clara la unión diferencial y es relativamente sencillo que la ç
  // interseccion no sea vacía.
  for (int i=0;i<10;i++) {
    s1.insert(generaEntero(1,20));
    s2.insert(generaEntero(1,20));
    s3.insert(generaEntero(1,20));
  }

  cout << "Conjunto A = " << s1 << endl << endl;
  cout << "Conjunto B = " << s2 << endl << endl;
  cout << "Conjunto C = " << s3 << endl << endl;

  interseccionATres(s1, s2, s3, result);
  cout << "Intersección de los tres = " << result << endl << endl;

  unionDiferencial(s1, s2, s3, result);
  cout << "Unión diferencial de los tres = " << result << endl;
}
