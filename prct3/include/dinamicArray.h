// José Antonio Álvarez Ocete
// Yábir García Benchakhtir
/**
  * @file dinamicArray.h
  * @brief Fichero cabecera del TDA Vector Dinamico
  *
  * Se crea un vector con capacidad de crecer y decrecer.
  *
  */

#ifndef DinamicArray_H
#define DinamicArray_H

/**
 *  @brief T.D.A. DinamicArray
 *
 *
 * Una instancia @e v del tipo de datos abstracto @c DinamicArray sobre el
 * tipo @c T es un array 1-dimensional de un determinado tamaño @e n, que
 * puede crecer y decrecer a petición del usuario. Lo podemos representar como
 *
 *  {v[0],v[1],...,v[n-1]}
 *
 * donde  v[i] es el valor almacenado en la posición  i del vector
 *
 * La eficiencia en espacio es @e O(n).
 *
 * Un ejemplo de su uso:
 * @include testDinamic.cpp
 *
 */

template<class T>

class DinamicArray{

 private:

   /**
      * @page repDinamicArray Rep del TDA DinamicArray
      *
      * @section invDinamicArray Invariante de la representación
      *
      * Un objeto válido @e v del TDA DinamicArray debe cumplir
      * - @c v.elements >= 0
      * - @c v.max_elements >= 0
      * - @c v.data apunta a una zona de memoria con capacidad para albergar
      *   @c max_elements valores de tipo @c T
      *
      * @section faDinamicArray  Función de abstracción
      *
      * Un objeto válido @e rep del TDA DinamicArray representa al vector de
      * tamaño @e n
      *
      * {v.data[0],v.data[1],...,v.data[v.elements-1]}
      *
   */

  T * data; /**< Apunta a los elementos del vector */
  int elements; /**< Número de posiciones en el vector siendo utilizadas */
  int max_elements; /**< Número máximo de posiciones disponibles */

  void destroy();

 public:
  // ---------------  Constructores ----------------
  /**
   * @brief Constructor por defecto
   * @param n indica el número de componentes inicial reservados
   *          para el vector
   */
  DinamicArray<T>(int n=0);
  /**
   * @brief Constructor de copia
   * @param original es otro DinamicArray para usarse en la copia
   */
  DinamicArray<T>(const DinamicArray<T>& original);

  // ------------------ Destructor ------------------
  ~DinamicArray<T>();

  // ------------------ Métodos ---------------------

  /**
  * @brief Operador de asignación de la clase
  * @param original @c DinamicArray a copiar
  * @return Referencia a this.
  */
  DinamicArray& operator=(const DinamicArray &original);


  /**
   * @brief Número de elementos que se encuentran en @c data
   * @return Entero que representa los elementos.
   */
  int used() const;

  /**
   * @brief Referencia al último elemento insertado en la lista
   * @return out @c T como referencia al ultimo elemento.
   */
  T& back() const;

  /**
   * @brief Referencia al último elemento insertado en la lista
   * @return out @c T como referencia al ultimo elemento.
   */

  T& back();

  /**
   * @brief Referencia al número de elementos que se encuentran en @c data
   * @return Referencia a un tipo @c int que representa los elementos.
   */
  int& used();

  /**
   * @brief Capacidad máxima de @c data
   * @return Entero que representa el número máximo de elementos que se puede
   * almacenar en @c data.
   */
  int size() const;
  /**
   * @brief Acceso a una posición de @c data.
   * @param i entero que representa la posición que se quiere acceder. 0 <= i < size()
   * @return Referencia a un elemento de tipo @c T contenido en @c data
   */
  T& operator [] (int i);
  /**
   * @brief Acceso a una posición de @c data. Acceso solo de lectura.
   * @param i entero que representa la posición que se quiere acceder. 0 <= i < used()
   * @return Referencia constante a un elemento de tipo @c T contenido en @c data
   */
  const T& operator [] (int i) const;

  /**
   * @brief Añade un elemento a @c data con la característica de añadirlo al final.
   * @param @c DinamicArray de tipo @c T
   * @see insert()
   */
  void push (T e);
  /**
   * @brief Incrementa el tamaño de @c data en cantidades multiplo de 2.
   */
  void boost();
  /**
   * @brief Añade un elemento a @c data en la posición @c pos.
   * @param e Un elemento de tipo @ T que será el elemento que se insertar
   * @param pos Un @int que indica la posición en la que se inserta
   * @see insert()
   */
  bool insert(T e, int pos);

  T pop_back();
};


#include "../src/dinamicArray.cpp"
#endif /* _vectorDinamico_h */
