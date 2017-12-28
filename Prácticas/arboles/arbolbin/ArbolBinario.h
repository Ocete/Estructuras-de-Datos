/*____________________________________________________________ */
//               Fichero ArbolBinario.h
/*____________________________________________________________ */

#include <cassert>

using namespace std;
/**
  * @file ArbolBinario.h
  * @brief Fichero cabecera del TDA Arbol Binario
  * 
  */
  
#ifndef __ArbolBinario_h__
#define __ArbolBinario_h__

/**
  * @brief T.D.A. ArbolBinario
  *
  * Una instancia @e a del tipo de dato abstracto ArbolBinario sobre un
  * dominio Tbase se puede construir como
  * 
  * - Un objeto vacío (árbol vacío) si no contiene ningún elemento. Lo
  * denotamos {}
  * - Un árbol que contiene un elemento destacado, el nodo raíz, con un 
  * valor @e e en el dominio Tbase (denominado @e etiqueta), y dos 
  * subárboles (T<sub>i</sub>:izquierdo y T<sub>d</sub> derecho) del T.D.A. 
  * ArbolBinario sobre Tbase. 
  * Se establece una relación @e padre-hijo entre cada nodo y los nodos raíz
  * de los subárboles (si los hubiera) que cuelgan de él. Lo denotamos 
  * {@e e,{T<sub>i</sub>},{T<sub>d</sub>}}.
  * 
  * Para poder usar el TDA ArbolBinario se debe incluir el fichero
  *
  * <tt>\#include ArbolBinario.h</tt>
  * 
  * El espacio requerido para el almacenamiento es @e O(n). Donde @e n es el
  * número de nodos del árbol.
  * 
  * @author Antonio Garrido
  * @date 
  *
  */     
template <class Tbase>
class ArbolBinario {
/**
  * @page repConjunto Rep del TDA ArbolBinario
  *
  * @section invConjunto Invariante de la representación
  *
  * Sea @e T, un árbol binario sobre el tipo @e Tbase. Entonces el invariante 
  * de la representación es
  *
  * Si @e T es vacío, entonces T.laraiz = 0, y si no:
  *
  * T.laraiz->padre = 0 y
  *
  * \f$\forall n\f$ nodo de \e T, 
  *  n\f$\rightarrow\f$izqda \f$\neq\f$ n\f$\rightarrow\f$drcha y
  *
  * \f$\forall n,m\f$ nodos de \e T, si n\f$\rightarrow\f$izqda=m
  * ó n\f$\rightarrow\f$drcha=m, entonces m\f$\rightarrow\f$padre= n
  *
  * @section faConjunto Función de abstracción
  *
  * Sea @e T un árbol binario sobre el tipo @e Tbase, entonces si lo denotamos 
  * también Árbol(T.laraiz), es decir, como el árbol que cuelga de su raíz, 
  * entonces éste árbol del conjunto de valores en la representación se aplica 
  * al árbol
  *
  * \f[
  * T.laraiz \rightarrow etiqueta,
  * \{Arbol(T.laraiz \rightarrow izqda)\},
  * \{Arbol(T.laraiz \rightarrow drcha)\},
  *    \f]
  * donde {0} es el árbol vacío.
  *
  */

  private:
    /** @brief En cada  estructura nodo se almacena una etiqueta del árbol, que 
      * se implementa como un conjunto de nodos enlazados según la relación 
      * padre-hijo.
      */

    struct nodo {

      /** @brief Elemento almacenado. En este campo se almacena la etiqueta que 
        * corresponde a este nodo.
        */
      Tbase etiqueta;
        
      /** @brief Puntero al hijo izquierda. En este campo se almacena un puntero 
        * al nodo raíz del subárbol izquierdo, o el valor 0 si no tiene. 
        */
      struct nodo *izqda;
        
      /**@brief Puntero al hijo derecho. En este campo se almacena un puntero al
        * nodo raíz del subárbol derecho,  o el valor 0 si no tiene. 
        */
      struct nodo *drcha;
      
      /**@brief Puntero al padre. En este campo se almacena un puntero al nodo 
        * padre, o el valor 0 si es la raíz. 
        */
      struct nodo *padre;
    };
    
    
    /**
      * @brief Destruye el subárbol.
      * @param n Nodo a destruir, junto con sus descendientes.
      *
      * Libera los recursos que ocupan @e n y sus descendientes.
      */
    void destruir(nodo * n);
    
    /**
      * @brief Copia un subárbol.
      * @param dest Referencia al puntero del que cuelga la copia.
      * @param orig Puntero a la raíz del subárbol a copiar.
      *
      * Hace una copia de todo el subárbol que cuelga de @e orig en
	  * el puntero @e dest. Es importante ver que en @e dest->padre
	  * (si existe) no se asigna ningún valor, pues no se conoce.
      */
    void copiar(nodo * & dest, nodo * orig);
      
    /**
      * @brief Cuenta el número de nodos
      * @param n Nodo del que cuelga el subárbol de nodos a contabilizar
      *
      * Cuenta cuántos nodos cuelgan de @e n, incluido éste
      */
    int contar(nodo * n);
      
    /**
      * @brief Comprueba igualdad de dos subárboles
      * @param n1 Primer subárbol a comparar
      * @param n2 Segundo subárbol a comparar
      *
	  * Comprueba si son iguales los subárboles que cuelgan de @e n1 y @e n2. 
	  * Para ello deberán tener los mismos nodos en las mismas posiciones y 
	  * con las mismas etiquetas.
      */
    bool soniguales(nodo * n1, nodo * n2);
      
    /**
      * @brief Escribe un subárbol
      * @param out Stream de salida donde escribir
	  * @param nod Nodo del que cuelga el subárbol a escribir
	  *
	  * Escribe en la salida todos los nodos del subárbol que cuelga del nodo 
	  * @e nod siguiendo un recorrido en preorden. La forma de impresión de 
	  * cada nodo es:
	  *	- Si el nodo es nulo, imprime el carácter 'x'.
      *	- Si el nodo no es nulo, imprime el carácter 'n' seguido de un 
	  * 	 espacio, al que sigue la impresión de la etiqueta.
      */
    void escribe_arbol(std::ostream& out, nodo * nod) const;
      
    /**
      * @brief Lee un subárbol
      * @param in Stream de entrada desde el que leer
      * @param nod Referencia al nodo que contendrá el subárbol leído
      * @see escribe_arbol
      *
	  * Lee de la entrada @e in los elementos de un árbol según el formato 
	  * que se presenta en la función de escritura.
	  * 
      */
    void lee_arbol(std::istream& in, nodo *& nod);
      

  
  private: 
    /** @brief Puntero a la raíz. Este miembro es un puntero al primer nodo, 
      * que corresponde a la raíz del árbol. Vale 0 si el árbol es vacío
      */
    struct nodo *laraiz;

  public:
    /**
      * @brief Tipo Nodo
      *
      * Este tipo nos permite manejar cada uno de los nodos del árbol. Los 
	  * valores que tomará serán tantos como nodos en el árbol (para poder 
	  * referirse a cada uno de ellos) y además un valor destacado 
	  * @e nulo (0), que indica que no se refiere a ninguno de ellos.
	  *
	  * Una variable @e n de este tipo se declara
	  *
	  * <tt> ArbolBinario::Nodo n; </tt>
	  *
	  * Las operaciones válidas sobre el tipo nodo son:
      * - Operador de Asignación (=)
	  * - Operador de comprobación de igualdad (==)
	  * - Operador de comprobación de desigualdad (!=)
	  */
    typedef struct nodo * Nodo;
      

    /** @brief Constructor por defecto
      *
      * Reserva los recursos e inicializa el árbol a vacío {}. La operación se 
	  * realiza en tiempo O(1).
      *
      */
    ArbolBinario();
    
    /**
      * @brief Constructor de raíz
      *
      * @param e Etiqueta de la raíz
      *
      * Reserva los recursos e inicializa el árbol con un único nodo raíz que 
      * tiene la etiqueta @e e, es decir, el árbol {e,{},{}}. La operación se 
      * realiza en tiempo O(1).
      */
      ArbolBinario(const Tbase& e);
      
    /**
      * @brief Constructor de copias
      * @param v ArbolBinario a copiar
      * 
      * Construye el árbol duplicando el contenido de @e v en el árbol
      * receptor. La operación se realiza en tiempo O(n), donde n es el 
      * número de elementos de @e v.
      */
      ArbolBinario(const ArbolBinario<Tbase>& v);
      
    /**
      * @brief Destructor
      *
      * Libera los recursos ocupados por el árbol receptor. La operación se 
      * realiza en tiempo O(n), donde n es el número de elementos del árbol 
      * receptor.
      */
    ~ArbolBinario();
    
    /**
      * @brief Operador de asignación
      * @param v ArbolBinario a copiar
      * @return Referencia al árbol receptor.
      *
      * Asigna el valor del árbol duplicando el contenido de @e v en el árbol 
      * receptor. La operación se realiza en tiempo O(n), donde n es el número
      * de elementos de @e v.
      */
    ArbolBinario<Tbase> & operator = (const ArbolBinario<Tbase> & v);
      
    /**
      * @brief Asignar nodo raíz
      * @param e Etiqueta a asignar al nodo raíz
      *
      * Vacía el árbol receptor y le asigna como valor el árbol de un único 
      * nodo cuya etiqueta es @e e.
      */
    void AsignaRaiz(const Tbase & e);
      
    /**
      * @brief Raíz del árbol
      * @return Nodo raíz del árbol receptor.
      *
      * Devuelve el nodo raíz, que es el nodo nulo si el árbol está vacío. 
      * La operación se realiza en tiempo O(1).     
      */
    Nodo raiz() const;
      
    /**
      * @brief Hijo izquierda
      * @param n Nodo del que se quiere obtener el hijo a la izquierda
      * @pre @e n no es nulo.
      * @return Nodo hijo a la izquierda.
      *
      * Devuelve el nodo hijo a la izquierda de @e n, que será el nodo nulo si 
      * no tiene hijo a la izquierda. La operación se realiza en tiempo O(1).
      */
    Nodo izquierda(const Nodo n) const;
    
    /**
      * @brief Hijo derecha
      * @param n Nodo del que se quiere obtener el hijo a la derecha
      * @pre @e n no es nulo.
      * @return Nodo hijo a la derecha.
      *
      * Devuelve el nodo hijo a la derecha de @e n, que será el nodo nulo si 
      * no tiene hijo a la derecha. La operación se realiza en tiempo O(1).
      */
    Nodo derecha(const Nodo n) const;
    
    /**
      * @brief Nodo padre
      * @param n Nodo del que se quiere obtener el padre
      * @pre @e n no es nulo
      * @return Nodo padre.
      *
      * Devuelve el nodo padre de @e n, que será el nodo nulo si es la raíz. 
      * La operación se realiza en tiempo O(1).
      */
    Nodo padre(const Nodo n) const;
    
    /**
      * @brief Etiqueta de un nodo
      * @param n Nodo en el que se encuentra el elemento.
      * @pre @e n no es nulo
      * @return Referencia al elemento del nodo @e n.
      *
      * Devuelve una referencia al elemento del nodo @e n y por tanto se puede 
      * modificiar o usar el valor. La operación se realiza en tiempo O(1).     
      */
    Tbase& etiqueta(const Nodo n);
      
    /**
      * @brief Etiqueta de un nodo
      * @param n Nodo en el que se encuentra el elemento.
      * @pre @e n no es nulo
      * @return Referencia constante al elemento del nodo @e n.
      *
      * Devuelve una referencia al elemento del nodo @e n. Es constante y 
      * por tanto no se puede modificiar el valor. La operación se realiza en 
      * tiempo O(1).
      */
    const Tbase& etiqueta(const Nodo n) const;
    
    /**
      * @brief Copia subárbol
      * @param orig Árbol desde el que se va a copiar una rama
      * @param nod Nodo raíz del subárbol que se copia. Es un nodo del árbol 
      * @e orig y no es nulo
      *
      * El árbol receptor acaba con un valor copia del subárbol que cuelga del 
      * nodo @e nod en el árbol @e orig. La operación se realiza en tiempo 
      * O(n), donde @e n es el número de nodos del subárbol copiado.
      */
    void asignar_subarbol(const ArbolBinario<Tbase>& orig, const Nodo nod);

    /**
      * @brief Podar subárbol izquierda
      * @param n Nodo al que se le podará la rama hijo izquierda.
      * @param dest Árbol que recibe la rama cortada
      * @pre @e n no es nulo y es un nodo válido del árbol receptor.
      *
      * Asigna un nuevo valor al árbol @e dest, con todos los elementos del 
      * subárbol izquierdo del nodo @e n en el árbol receptor. Éste se queda 
      * sin dichos nodos. La operación se realiza en tiempo O(1).
      */
    void podar_izquierda(Nodo n, ArbolBinario<Tbase>& dest);
    
    /**
      * @brief Podar subárbol derecha
      * @param n Nodo al que se le podará la rama hijo derecha.
      * @param dest Árbol que recibe la rama cortada
      * @pre @e n no es nulo y es un nodo válido del árbol receptor.
      *
      * Asigna un nuevo valor al árbol @e dest, con todos los elementos del 
      * subárbol derecho del nodo @e n en el árbol receptor. Éste se queda 
      * sin dichos nodos. La operación se realiza en tiempo O(1).
      */
    void podar_derecha(Nodo n, ArbolBinario<Tbase>& dest);

    /**
      * @brief Insertar subárbol izquierda
      * @param n Nodo al que se insertará el árbol @e rama como hijo izquierdo.
      * @param rama Árbol que se insertará como hijo izquierdo.
      * @pre @e n no es nulo y es un nodo válido del árbol receptor.
      *
      * El árbol @e rama se inserta como hijo izquierda del nodo @e n del árbol
      * receptor. El árbol @e rama queda vacío y los nodos que estaban en el 
      * subárbol izquierdo de @e n se eliminan.
      */
    void insertar_izquierda(Nodo n, ArbolBinario<Tbase>& rama);

    /**
      * @brief Insertar subárbol derecha
      * @param n Nodo al que se insertará el árbol @e rama como hijo derecho.
      * @param rama Árbol que se insertará como hijo derecho.
      * @pre @e n no es nulo y es un nodo válido del árbol receptor.
      *
      * El árbol @e rama se inserta como hijo derecho del nodo @e n del árbol
      * receptor. El árbol @e rama queda vacío y los nodos que estaban en el 
      * subárbol derecho de @e n se eliminan.
      */
    void insertar_derecha(Nodo n, ArbolBinario<Tbase>& rama);

    /**
      * @brief Borra todos los elementos
      *
      * Borra todos los elementos del árbol receptor. Cuando termina, el árbol 
      * está vacía. La operación se realiza en tiempo O(n), donde n es el
      * número de elementos del árbol receptor.
      */
    void clear();
    
    /**
      * @brief Número de elementos
      * @return  El número de elementos del árbol receptor.
      *
      * La operación se realiza en tiempo O(n).
      * @see contar
      */
    int size() const;
    
    /**
      * @brief Vacío
      * @return Devuelve @e true si el número de elementos del árbol receptor 
      * es cero, @e false en otro caso.
      *
      * La operación se realiza en tiempo O(1).
      */
    bool empty() const;
    
    /**
      * @brief Operador de comparación (igualdad)
      * @param v ArbolBinario con el que se desea comparar
      * @return Devuelve @e true si el árbol receptor tiene los mismos
      * elementos y en el mismo orden, y @e false en caso contrario.
      *
      * La operación se realiza en tiempo O(n).
      * @see soniguales       
      */
    bool operator == (const ArbolBinario<Tbase>& v) const;
    
    /**
      * @brief Operador de comparación (diferencia)
      * @param v ArbolBinario con el que se desea comparar
      * @return Devuelve @e true si el árbol receptor no tiene los mismos
      * elementos y en el mismo orden, y @e false en caso contrario.
      *
      * La operación se realiza en tiempo O(n).
      */
    bool operator != (const ArbolBinario<Tbase>& v) const;

      
    /**
      * @brief Operador de extracción de flujo
      * @param in Stream de entrada
      * @param v Árbol que leer 
      * @return Referencia al stream de entrada.
      *
      * Lee de @e in un árbol y lo almacena en @e v. El formato aceptado para 
      * la lectura se puede consultar en la función de salida.
      * @see lee_arbol 
      */
    template <class T>
    friend std::istream& operator >> (std::istream& in, ArbolBinario<T>& v);
    
    /**
      * @brief Operador de inserción de flujo
      * @param out Stream de salida
      * @param v Árbol que escribir
      * @return Referencia al stream de salida.
      *
      * Escribe en la salida todos los nodos del árbol @e v siguiendo un 
      * recorrido en preorden. La forma de impresión de cada nodo es:
      * - Si el nodo es nulo, imprime el carácter 'x'.
      * - Si el nodo no es nulo, imprime el carácter 'n' seguido de 
      *   un espacio, al que sigue la impresión de la etiqueta.
      *
      * @see escribe_arbol
      */
    template <class T>
    friend std::ostream& operator << (std::ostream& out, 
                                      const ArbolBinario <T> & v);
};




/*____________________________________________________________ */
/*____________________________________________________________ */
//               FUNCIONES PRIVADAS
/*____________________________________________________________ */
/*____________________________________________________________ */

template <class Tbase>
void ArbolBinario <Tbase> :: destruir (nodo * n){
  if (n!=0){             //Si no es un nodo nulo,
    destruir(n->izqda);  //destruimos recursivamente su hijo izquierda y
    destruir(n->drcha);  //destruimos recursivamente su hijo derecha
    delete n;            //Una vez borrados los descendientes, borramos el nodo
  }
}

/*____________________________________________________________ */

template <class Tbase>
void ArbolBinario<Tbase>::copiar(nodo * & dest, nodo * orig){
  if (orig == 0)                      //Si el nodo origen es nulo,
    dest = 0;
  else{                               //Si no es el nodo nulo,
    dest = new nodo;                  //Reservamos el nodo destino
    dest->etiqueta = orig->etiqueta;  //Copiamos la etiqueta
    copiar(dest->izqda, orig->izqda); //Copiamos recursivamente el hijo izqda
    copiar(dest->drcha, orig->drcha); //Copiamos recursivamente el hijo drcha
    if (dest->izqda != 0)             //Si hay hijo izquierda,
      dest->izqda->padre = dest;      //actualizamos su padre
    if (dest->drcha != 0)             //Si hay hijo derecha,
      dest->drcha->padre = dest;      //actualizamos su padre
  }
}

/*____________________________________________________________ */

template <class Tbase>
int ArbolBinario<Tbase>::contar(nodo * n){
  if (n==0)      //Si es el nodo nulo,
    return 0;    //devuelve 0
  else 
    return 1+contar(n->izqda)+contar(n->drcha); //Caso general (recursivo)
}

/*____________________________________________________________ */

template <class Tbase>
bool ArbolBinario<Tbase>::soniguales(nodo * n1, nodo * n2){
  if (n1==0 && n2==0)                        //Si los dos nodos son nulos,
    return true;                             //devolvemos true
  else if (n1==0 || n2==0)                   //Si uno es nulo y el otro no
    return false;                            //devolvemos false
  else if (n1->etiqueta!=n2->etiqueta)       //Si sus etiquetas son distintas
    return false;                            //devolvemos false
  else if (!soniguales(n1->izqda,n2->izqda)) //Si los hijos izquierda no son =
    return false;                            //devolvemos false
  else if (!soniguales(n1->drcha,n2->drcha)) //Si los hijos derecha no son =
    return false;                            //devolemos false
  else                                       //En otro caso
    return true;                             //devolvemos true
}

/*____________________________________________________________ */

template <class Tbase>
void ArbolBinario <Tbase>::lee_arbol(std::istream& in, nodo * & nod){
  char c;
  in >> c;                     //Lectura de un carácter
  if (c=='n'){                 //Si es 'n'
    nod= new nodo;             //Reservamos un nuevo nodo
    in >> nod->etiqueta;       //Leemos la etiqueta
    lee_arbol(in,nod->izqda);  //Leemos recursivamente el hijo izquierda
    lee_arbol(in,nod->drcha);  //Leemos recursivamente el hijo derecha
    if (nod->izqda!=0)         //Si hay hijo izquierda,
      nod->izqda->padre=nod;   //actualizamos su padre
    if (nod->drcha!=0)         //Si hay hijo derecha,
      nod->drcha->padre=nod;   //actualizamos su padre
  }
  else nod= 0;                 //Si no es 'n' hay un error en la entrada
                               //o no hay más caracteres que leer,
                               //y devolvemos un árbol nulo
}

/*____________________________________________________________ */

template <class Tbase>
void ArbolBinario<Tbase>::escribe_arbol(std::ostream& out, nodo * nod) const{
  if (nod==0)                            //Si el nodo es nulo
    out << "x ";                         //escribimos 'x'
  else {                                 //Si el nodo no es nulo
    out << "n "<< nod->etiqueta << " ";  //escribimos su etiqueta
    escribe_arbol(out,nod->izqda);    //Escribimos el hijo izqda recursivamente
    escribe_arbol(out,nod->drcha);    //Escribimos el hijo drcha recursivamente
  }
}

/*____________________________________________________________ */
/*____________________________________________________________ */
//               FUNCIONES PUBLICAS
/*____________________________________________________________ */
/*____________________________________________________________ */


template <class Tbase>
inline ArbolBinario<Tbase>::ArbolBinario(){
  laraiz = 0;  //El constructor por defecto crea un árbol vacío
}

/*____________________________________________________________ */

template <class Tbase>
ArbolBinario<Tbase>::ArbolBinario(const Tbase& e){
  laraiz = new nodo;      //Crea el nodo raíz
  laraiz->padre =         //No tiene padre,
  laraiz->izqda =         //hijo izquierda
  laraiz->drcha = 0;      //ni hijo derecha.
  laraiz->etiqueta = e;   //Asignamos valor a la etiqueta de la raíz
}

/*____________________________________________________________ */

template <class Tbase>
ArbolBinario<Tbase>::ArbolBinario (const ArbolBinario<Tbase>& v){
  copiar (laraiz,v.laraiz); //Llamamos a copiar desde la raíz
  if (laraiz!=0)            //Si no es el árbol vacío
    laraiz->padre= 0;       //actualizamos el padre
}

/*____________________________________________________________ */

template <class Tbase>
inline ArbolBinario<Tbase>::~ArbolBinario(){
  destruir(laraiz);  //Destruye llamando a destruir desde la raíz 
}

/*____________________________________________________________ */

template <class Tbase>
ArbolBinario<Tbase> & 
ArbolBinario<Tbase>::operator = (const ArbolBinario<Tbase>&v){
  if (this!=&v){              //Comprobación de rigor. Si no es el mismo objeto
    destruir(laraiz);         //destruimos el objeto *this
    copiar (laraiz,v.laraiz); //Llamamos a copiar desde la raíz
    if (laraiz!=0)            //Si no es el árbol vacío
      laraiz->padre= 0;       //actualizamos el padre
  }
  return *this; //Devolvemos *this para permitir encadenamientos (a=b=c)
}

/*____________________________________________________________ */

template <class Tbase>
void ArbolBinario<Tbase>::AsignaRaiz(const Tbase& e){
  destruir(laraiz);     //Destruye el árbol actual
  laraiz = new nodo;    //Reservamos el nodo raíz
  laraiz->padre =       //No tiene padre,
  laraiz->izqda =       //ni hijo izquierda,
  laraiz->drcha = 0;    //ni hijo derecha.
  laraiz->etiqueta= e;  //Damos valor a la etiqueta de la raíz
}

/*____________________________________________________________ */

template <class Tbase>
inline typename ArbolBinario<Tbase>::Nodo 
                ArbolBinario<Tbase>::raiz() const{
  return laraiz;
}

/*____________________________________________________________ */

template <class Tbase>
inline typename ArbolBinario<Tbase>::Nodo 
                ArbolBinario<Tbase>::izquierda(const Nodo p) const{
  assert(p!=0);       //El nodo no debe ser nulo
  return (p->izqda);
}

/*____________________________________________________________ */

template <class Tbase>
typename ArbolBinario<Tbase>::Nodo ArbolBinario<Tbase>::derecha(const Nodo p) const{
  assert(p!=0);       //El nodo no debe ser nulo
  return (p->drcha);
}

/*____________________________________________________________ */

template <class Tbase>
typename ArbolBinario<Tbase>::Nodo ArbolBinario<Tbase>::padre(const Nodo p) const{
  assert(p!=0);       //El nodo no debe ser nulo
  return (p->padre);
}

/*____________________________________________________________ */

template <class Tbase>
Tbase& ArbolBinario<Tbase>::etiqueta(const Nodo p){
  assert(p!=0);          //El nodo no debe ser nulo
  return (p->etiqueta);
}

/*____________________________________________________________ */

template <class Tbase>
const Tbase& ArbolBinario<Tbase>::etiqueta(const Nodo p) const{
  assert(p!=0);          //El nodo no debe ser nulo
  return (p->etiqueta);
}

/*____________________________________________________________ */

template <class Tbase>
void ArbolBinario<Tbase>::asignar_subarbol(const ArbolBinario<Tbase>& orig, 
                                           const Nodo nod){
  destruir(laraiz);    //Destruye el árbol actual
  copiar(laraiz,nod);  //Copiamos el subárbol que cuelga de nod en la raíz
  if (laraiz!=0)       //Si el subárbol copiado no es vacío,
    laraiz->padre=0;   //actualizamos el padre
}


/*____________________________________________________________ */

template <class Tbase>
void ArbolBinario<Tbase>::podar_izquierda(Nodo n, ArbolBinario<Tbase>& dest){
  assert(n!=0);             //El nodo no debe ser nulo
  destruir(dest.laraiz);    //Destruimos el árbol destino
  dest.laraiz=n->izqda;     //Copia el hijo izquierda de n en la raíz de dest
  if (dest.laraiz!=0) {     //Si el subárbol copiado no es vacío,
    dest.laraiz->padre=0;   //actualizamos el padre
    n->izqda=0;             //y actualizamos el hijo a la izquierda
  }
}


/*____________________________________________________________ */

template <class Tbase>
void ArbolBinario<Tbase>::podar_derecha(Nodo n, ArbolBinario<Tbase>& dest){
  assert(n!=0);             //El nodo no debe ser nulo
  destruir(dest.laraiz);    //Destruimos el árbol destino
  dest.laraiz=n->drcha;     //Copia el hijo derecha de n en la raíz de dest
  if (dest.laraiz!=0) {     //Si el subárbol copiado no es vacío,
    dest.laraiz->padre=0;   //actualizamos el padre
    n->drcha=0;             //y actualizamos el hijo a la derecha
  }
}

/*____________________________________________________________ */

template <class Tbase>
void ArbolBinario<Tbase>::insertar_izquierda(Nodo n, ArbolBinario<Tbase>& rama){
  assert(n!=0);             //El nodo no debe ser nulo
  destruir(n->izqda);       //Destruimos el hijo izquierda
  n->izqda=rama.laraiz;     //Copia la rama en el hijo izquierda
  if (n->izqda!=0) {        //Si la rama copiada no es vacía,
    n->izqda->padre= n;     //actualizamos el padre
    rama.laraiz=0;          //y actualizamos la raíz en rama
  }
}

/*____________________________________________________________ */

template <class Tbase>
void ArbolBinario<Tbase>::insertar_derecha(Nodo n, ArbolBinario<Tbase>& rama){
  assert(n!=0);             //El nodo no debe ser nulo
  destruir(n->drcha);       //Destruimos el hijo izquierda
  n->drcha=rama.laraiz;     //Copia la rama en el hijo derecha
  if (n->drcha!=0) {        //Si la rama copiada no es vacía,
    n->drcha->padre= n;     //actualizamos el padre
    rama.laraiz=0;          //y actualizamos la raíz en rama
  }
}

/*____________________________________________________________ */

template <class Tbase>
void ArbolBinario<Tbase>::clear(){
  destruir(laraiz);    //Destruimos el árbol recursivamente desde la raíz
  laraiz= 0;           //Actualizamos la raíz del árbol
}

/*____________________________________________________________ */

template <class Tbase>
inline int ArbolBinario<Tbase>::size() const{
  return contar(laraiz);  //Contamos los nodos recursivamente desde la raíz
}

/*____________________________________________________________ */

template <class Tbase>
inline bool ArbolBinario<Tbase>::empty() const{
  return (laraiz==0);
}

/*____________________________________________________________ */

template <class Tbase>
inline bool ArbolBinario<Tbase>::operator==(const ArbolBinario<Tbase>& v) const{
  return soniguales(laraiz,v.laraiz); //Comparamos los árboles desde la raíz
}

/*____________________________________________________________ */

template <class Tbase>
inline bool ArbolBinario<Tbase>::operator!=(const ArbolBinario<Tbase>& v) const{
  return !(*this==v); //Comparamos los árboles desde la raíz
}

/*____________________________________________________________ */

template <class Tbase>
inline istream& operator>> (istream& in, ArbolBinario<Tbase>& v){
  v.lee_arbol(in,v.laraiz); //Lee el árbol
  return in;                //Devuelve in para permitir encadenamientos
}

/*____________________________________________________________ */

template <class Tbase>
inline ostream& operator<< (ostream& out, const ArbolBinario<Tbase>& v){
  v.escribe_arbol(out,v.laraiz); //Escribe el árbol
  return out;                    //Devuelve out para permitir encadenamientos
}

/*____________________________________________________________ */


#endif
