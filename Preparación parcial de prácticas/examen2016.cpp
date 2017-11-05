/**
 * @file puntuable1.cpp
 * @brief Prueba de laboratorio de ED
 * @author Antonio Coín Castro
 * @date 13 Diciembre 2016
 *
 */

 #include <iostream>
 #include <set>
 #include <ctime>
 #include <cstdlib>

 using namespace std;

 /**
  * @brief Imprime un conjunto de tipo @c T sobre el flujo de salida
  * @param s flujo de salida. Es MODIFICADO
  * @param l el conjunto con los elementos a imprimir
  */
 template <class T>
 ostream& operator<<(ostream& s, const set<T>& c)
 {
   typename set<T>::const_iterator i;

   s << "{ ";
   for (i = c.begin(); i != c.end(); ++i)
     s << (*i) << " ";
   s << "}";

   return s;
 }

 /**
  * @brief Inicializar el generador de numero aleatorios
  * Esta función debe ser llamada antes de usar rand()
  */
 void InicializarSemilla()
 {
   srand(time(0));
 }

 /**
  * @brief Genera numero enteros positivos aleatorios en el rango [min,max]
  */
 int GeneraEntero(int min, int max)
 {
     int tam = max - min + 1;
     return ((rand() % tam) + min);
 }

/**
 * @brief Calcula la intersección de dos conjuntos
 * @param s1 Primer conjunto
 * @param s2 Segundo conjunto
 * @param res Conjunto intersección. Parámetro de salida
 */
void Interseccion(const set<int>& s1, const set<int>& s2, set<int>& res)
{
  res.clear();

  set<int>::iterator p;
  for (p = s1.begin(); p != s1.end(); ++p)
    if (s2.count(*p) > 0)
      res.insert(*p);
}

/**
 * @brief Calcula los elementos de tres conjuntos que solo están
 * presentes en dos de ellos
 * @param s1 Primer conjunto
 * @param s2 Segundo conjunto
 * @param s3 Tercer conjunto
 * @param res Conjunto unión. Parámetro de salida
 */
 void Union(const set<int>& s1, const set<int>& s2, const set<int>& s3,
            set<int>& res)
 {
   res.clear();
   set<int>::iterator p;

   // Elementos de A que: están en B y no en C, o que están en C y no en B
   for (p = s1.begin(); p != s1.end(); ++p) {
     if (s2.count(*p) > 0 && s3.count(*p) == 0) {
       res.insert(*p);
     }
     else if (s2.count(*p) == 0 && s3.count(*p) > 0) {
       res.insert(*p);
     }
   }

   // Elementos de B que: están en C y no en A
   for (p = s2.begin(); p != s2.end(); ++p) {
     if (s3.count(*p) > 0 && s1.count(*p) == 0) {
       res.insert(*p);
     }
   }
 }

 int main()
 {
   set<int> c1, c2, c3, res;

   InicializarSemilla();

   // Inicializar conjuntos
   for (int i=0;i<=10;i++) {
     // Inserta un entero generado aleatoriamente en el rango [1,100]
     c1.insert(GeneraEntero(1,100));
     c2.insert(GeneraEntero(1,100));
     c3.insert(GeneraEntero(1,100));
   }

   // Imprimir conjuntos
   cout << "A = " << c1 << endl;
   cout << "B = " << c2 << endl;
   cout << "C = " << c3 << endl;
   cout << endl;

   // Intersección
   Interseccion(c1,c2,res);
   cout << "A Intersección B = " << res << endl;
   Interseccion(c1,c3,res);
   cout << "A Intersección C = " << res << endl;
   Interseccion(c2,c3,res);
   cout << "B Intersección C = " << res << endl;
   cout << endl;

   // Unión
   Union(c1,c2,c3,res);
   cout << "Elementos de A, B y C que están solo en dos de ellos = "
        << res << endl;

   return 0;
 }

/* Fin fichero: puntuable1.cpp */
