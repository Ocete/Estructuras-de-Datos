#ifndef _ARBOLBINARIO__
#define _ARBOLBINARIO__
#include <cassert>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
/**
  TDA ArbolBinario de Busqueda
  @doc Definición : Una instancia \a a del tipo de dato abstracto ArbolBinario AVL sobre un
  dominio T se puede construir como:
	  - Un objeto vacío si no contiene ningun elemento
	  - Un arbol que contiene un elemento destacad la raíz con un valor e en el dominio T
	     denominado etiqueta y dos subarboles (Ti:subarbol izquierdo, y Td:subarbol derecho) del
	     T.D.A Arbolbinario sobre T. Se establece una relación padre-hijo entre cada nodo y los
	     nodos raíz de los subarboles ( si existen) que cuelgan de el. Lo denotamos como 
	     {e,{Ti},{Td}}. Además todas las etiquetas en {Ti} son menores o iguales a e y todas
	     las etiquetas {Td} son mayores que e. Además debe estar equilibrado en el sentido
	     AVL (las diferencias en altura entre {Ti} y {Td} no deben ser mayor que 1).
	  Para poder usar el TDA AVL_AVL se debe incluir avl.h
	  Son mutables. El espacio requerido para el almacenamiento es O(n) siendo n el numero de nodos.
*/

template <class T>
class AVL{
	  private:
	  struct info_nodo{
		    T et;
		    info_nodo * padre;
		    info_nodo * hizq;
		    info_nodo * hder;
		    int altura ;
		    info_nodo(){ padre=hizq=hder=0; altura =0; }
		    info_nodo(const T & e){ et = e; padre=hizq=hder=0; altura=0;}
	 };
	  //Funciones asociadas a info_nodo	
	  /**
	    @brief Copiar un subarbol en otro
	    @param dest: objeto donde queda la copia. ES MODIFICADO
	    @param source: objeto desde el que se copia.
	  */
	  
	  void CopiarInfo(info_nodo * &dest,const info_nodo*const &source);
	  /** 
	    @brief Borra toda la información asociada a un subarbol  
	    @param d: raiz del subarbol a borrar. ES MODIFICADO
	  */
	  
	  void BorrarInfo(info_nodo *&d);
	  
	  /**
	    @brief Devuelve el numero de nodos del subarbol
	    @param d: raiz del subarbol
	  */
	  unsigned int numero_nodos(const info_nodo*d)const ;
	  
	  
	  /**
	    @brief Devuelve true si los dos subarboles son iguales
	    @param s1: raiz del primer subarbol
	    @param s2: raiz del segundo subarbol
	    @note : el tipo T debe tener definido el operador ==
	  */
	  bool iguales(const info_nodo*s1,const info_nodo*s2)const ;
	  /**
	    @brief Obtiene la altura de un determinado nodo
	    @param n: nodo sobre el que se obtiene la altura
	    @return la altura del nodo
	  */
	  int Altura(const info_nodo *n)const{ return ((n==0)?-1:n->altura);}
	  
		    
	 /**
	    @brief Actualiza la altura de un nodo
	    @param n: nodo sobre el que se actualiza la altura
	  */
	 void ActualizarAltura(info_nodo * n){
		   n->altura = std::max(Altura(n->hizq),Altura(n->hder))+1;
	 }
	 
	  
	  /***Rotaciones*/
	  /**
	    @brief Rotacion simple derecha
	    @param n: nodo sobre el que se rota a la derecha. ES MODIFICADO
	  */
	  void SimpleDerecha(info_nodo* &n);
	  
	  /**
	    @brief Rotacion simple izquierda
	    @param n: nodo sobre el que se rota a la izquierda. ES MODIFICADO
	  */
	  void SimpleIzquierda(info_nodo *&n);
	  
	  
	  
	  /**
	    @brief Rotacion doble  izquierda derecha
	    @param n: nodo sobre el que se rota doble izquierda derecha. ES MODIFICADO
	  */
	  void DobleIzquierdaDerecha(info_nodo *&n);
	  
	  
	  /**
	    @brief Rotacion doble  derecha izquierda
	    @param n: nodo sobre el que se rota doble  derecha izquierda. ES MODIFICADO
	  */
	  void DobleDerechaIzquierda(info_nodo *&n);
	  
	  /**
	    @brief BUsca un elemento en el AVL
	    @param n: subarbol desde el que se empieza la búsqueda
	    @param x: elemento a buscar
	    @return devuelve la posicion donde está
	   */
	    info_nodo* Buscar(info_nodo *n,const T&e);
	  
	   
	   
	  /**
	    @brief. Inserta un subarbol como hijo a la derecha de uno dado que consta de un solo nodo
	    @param n: subarbol al que se le inserta un nuevo subarbol como hijo a la derecha.
            @param x: etiqueta de la raiz del subarbol que se inserta
            @return true si es insertado false en caso contrario
           */
	  
	  bool Insertar(info_nodo * &n,const T & x,info_nodo *padre);
	  
	  /**
	   @brief Modifica el hijo del padre de n
	   @param n: nodo hijo
	   @param nuevo: nodo que pone como hijo
	   
	  */
	  void PutHijo_Padre(info_nodo *n,info_nodo*nuevo);
	  
	  /**
	   @brief Elimina el elemento que está en n
	   @param n: nodo donde está la etiqueta a eliminar
	   
	  */
	  info_nodo *  EliminarRaiz(info_nodo *&n);
		    
		    
	  /**
	    @brief Elimina la etiqueta e buscandola a partir de n
	    @param n: subarbol sobre el que se busca la etiqueta
	    @param e : etiqueta a eliminar
	    @return true si ha decrecido en altura
	  */
	  info_nodo * Borrar(info_nodo *& n,const T &e);
	  
	  /**
	    @brief Ajusta la altura del arbol
	    @param n: nodo a partir del cual ajusta la altura hasta la raiz
	  */
	  
	  void AjustarArbol(AVL<T>::info_nodo* &n);
	  
	  
	  
	  
	  
	  info_nodo * raiz;
 	  public:
		    
		    //declaración adelantada del tipo nodo (posicionamiento en un arbolbinario)
		    class nodo;
		    
		    /**
			 @brief Constructor por defecto
		    */
		    AVL():raiz(0){}
		    
		    /**
		      @brief Constructor con parametros
		    */
		    
		    
		    AVL(const T &e);
		    AVL(typename AVL<T>::nodo n);
		    /**
		      @brief Constructor por copia
		    */
		    AVL(const AVL<T> & ab);
		    
		    /**
		      @brief Destructor
		     */
		    ~AVL(){ clear();}
		    /**
		      @brief Operador de asignacion
		      @param ab: arbol binario del que se copia
		    */
		    AVL<T> & operator=(const AVL<T> & ab);
		    
		    /**
		      @brief Obtiene un nodo apuntando a la raiz del arbol
		     */
		      
		    typename AVL<T>::nodo getRaiz()const;
		    
		    /**
			@brief Busca un elemento en el abb
			@param e:elemento a buscar
			@return true si el elemento esta false en caso contrario
			
		    */
		    bool Buscar(const T &e){
			      if (raiz==0) return false;
			      else
			      return !(Buscar(raiz,e)==0);
		    }
		    /**
		      @brief Inserta una nueva etiqueta en el arbol
		      @param e: etiqueta de la raiz del subarbol que se inserta
		      @return devuelve un nodo con la posicion insertada
		    */
		    bool Insertar( const T &e);
		    
		    /**
		      @brief Borra una etiqueta en el arbol
		      @param e: etiqueta de la raiz del subarbol que se inserta
		      
		    */
		    void Borrar(const T &e);
		   /**
		     @brief Borra todo arbol, dejandolo como un arbol vacio
		    */
		    void clear();
		    
		    /**
		      @brief Arbol vacio
		      @return Devuelve si el arbol es vacio (true), y falso en caso contrario
		    */
		    bool empty()const ;
		    
		    /**
		      @brief Tamaño de un arbol
		      @return Devuelve  el numero de nodos que tiene el arbol
		      
		    */  
		    unsigned int size()const ;
		    
		    /**
		      @brief Igualdad entre dos arboles
		      @param a: arbo binario con el que se compara
		      @return true si los dos arboles son iguales false en caso contrario
		    */  
		    bool operator==(const AVL<T> &a)const;
		    
		    /**
		      @brief Desigualdad entre dos arboles
		      @param a: arbo binario con el que se compara
		      @return true si los dos arboles son distintos false en caso contrario
		    */
		    bool operator!=(const AVL<T> &a)const;
		    
		    
		    
		    /******************************************************/
		    /*                   CLASE NODO			  */
		    /******************************************************/
		    class nodo{
			      private:
			         info_nodo *p;
				  /**
				  @brief Constructo con parametros
				  @param i: nodo que se copia
				  */
			         nodo (info_nodo * i):p(i){}
			      public:
				 /**
				  @brief Contructor por defecto
				 */
			         nodo ():p(0){}
			        
			         /**
				   @brief Constructo de copia
				   @param n: nodo fuente
				 */  
			         nodo (const nodo &n):p(n.p){}
			         /**
				   @brief acceso a la informacion del nodo
			         */  
			         const T& operator*()const { 
					   assert(p!=0);
					   return p->et;
				 }
			        T& operator*() { 
					   assert(p!=0);
					   return p->et;
				 }
			        /**
				   @brief operacion de igualdad entre dos posiciones
				   @param n: nodo con el que se compara
				   @return true si son iguales false en caso contrario
				  */ 
				 bool operator==(const nodo &n){
					   return p==n.p;
				 }
				 /**
				   @brief operacion de desigualdad entre dos posiciones
				   @param n: nodo con el que se compara
				   @return true si son desiguales false en caso contrario
				  */
				 bool operator!=(const nodo &n){
					   return p!=n.p;
				 }	
				 /**
				    @brief Nodo del padre
				    @return devuelve un nodo apuntando padre
				 */   
				 nodo padre(){
					   if (p->padre!=0)
					    return nodo(p->padre);
					   else return nodo();
				 }
				 /**
				    @brief Nodo del padre
				    @return devuelve un nodo apuntando al hijo a la izquierda
				 */   
				 nodo hi(){
					   if (p->hizq!=0)
					    return nodo(p->hizq);
					   else return nodo();
				 }
				 /**
				    @brief Nodo del padre
				    @return devuelve un nodo apuntando al hijo a la derecha
				 */   
				 nodo hd(){
					   if (p->hder!=0)
					    return nodo(p->hder);
					   else return nodo();
				 }
				 /**
				    @brief dice si un nodo es nulo
				    @return true si es nulo false en caso contrario
				 */   
				 bool nulo(){
					   return p==0;
				 }
				 /**
				    @brief Obtiene el siguiente nodo segun el orden inorden
				    
				 */   
				  nodo &operator++();
			
				 int altura() { 
					   assert(p!=0);
					   return p->altura;
				 }	
				 friend class AVL;
				 
				 
		    };		 
		   
		    /***FUNCIONES BEGIN y EN PARA NODO***/
		    /**
		     @brief Comienzo de nodo en orden inorden
		     @return un nodo apuntando al comienzo según el orden inorden
		    */
		    nodo  begin()const ;
		    /**
		     @brief Fin de nodo en orden inorden
		     @return un nodo apuntando al comienzo según el orden inorden
		    */
		    nodo end()const;
		    
		    	      
		    
		    
		  

		    
};
#include "avl.tpp"
#endif