/*******************************************/
/* IMPLEMENTACION***************************/
/*******************************************/

/*
  Funcion de Abstraccion

   Dado el objeto del tipo rep r, r = {raiz}, el objeto
  abstracto al que representa es:                       
  a) Arbol nulo, si r.raiz == 0.                      
  b) Arbol con un unico nodo de etiqueta r.raiz->et,
     si r.raiz->hizq == 0 y r.raiz->hder == 0.         

  c)                r.raiz->et
                         /       \
                        /         \
      Arbol(r.raiz->hizq)    Arbol(r.raiz->hder)


  Invariante de Representacion:
  
  Si r.raiz != 0,
  -  r.raiz->padre == 0.
  - Para todo nodo n en el arbol con raiz r.raiz n->hizq<>n->hder y
  - Para todo par de nodos n y m en el arbol con raiz r.raiz si n->hizq=m o n->hder=m 
    entonces m->padre=n
   - Para todo par de nodos n y m si n está en el subarbo izquierdo que cuelga de m n->et<m->et o si
    n está en el subarbol derecho n->et>m->et
   -Ademas la diferencia en altura entre la r.raiz->hizq y r.raiz->hder no debe ser mayor que 1.

*/

#include <cassert>

//FUNCIONES ASOCIADAS a info_nodo
bool deb=false;
template <class T>
void AVL<T>::CopiarInfo(AVL<T>::info_nodo * &dest, const AVL<T>::info_nodo*const &source){
	 if (source!=0){
	  dest=new info_nodo(source->et);
	  CopiarInfo(dest->hizq,source->hizq);
	  if (dest->hizq!=0){
	    dest->hizq->padre= dest;
	  }
	  CopiarInfo(dest->hder,source->hder);
	  if (dest->hder!=0) dest->hder->padre=dest;
	  }
	  else dest=0;
}


template <class T>
void AVL<T>::BorrarInfo(AVL<T>::info_nodo *&d){
	  if (d!=0){
	   BorrarInfo(d->hizq);
	   BorrarInfo(d->hder);
	   delete d;
	  } 
  
}	  


template <class T>
unsigned int  AVL<T>::numero_nodos(const AVL<T>::info_nodo*d)const{
	  if (d==0) return 0;
	  else return 1+numero_nodos(d->hizq)+numero_nodos(d->hder);
}

template <class T>
bool  AVL<T>::iguales(const AVL<T>::info_nodo *s1,const AVL<T>::info_nodo *s2)const {
	  if (s1==0 && s2==0) return true;
	  else
	  if (s1==0 || s2==0) return false;
	  if (s1->et!=s2->et) return false;
	  else return iguales(s1->hizq,s2->hizq) && iguales(s1->hder,s2->hder);
}	  


/****ROTACIONES*********/
template <class T>
void AVL<T>::SimpleDerecha(AVL<T>::info_nodo *&n){
   typename AVL<T>::info_nodo *aux = n->hizq;
   typename AVL<T>::info_nodo *padre = n->padre;
   int hijo=0;
    if (padre!=0){
	    if (padre->hder==n) hijo=2;
	    else hijo=1;
   }	 
   n->hizq=aux->hder;
   if (n->hizq!=0) 
	     n->hizq->padre=n;
   n->padre = aux;
   aux->padre=padre;
   aux->hder=n;
   if (aux->hder!=0) 
	     aux->hder->padre=aux;
   if (n==raiz)
	raiz = aux;     
   n=aux;
   if (padre!=0){
     if (hijo==2) padre->hder=n;
    else if (hijo==1) padre->hizq=n;
   }
   ActualizarAltura(n->hder);
   ActualizarAltura(n);
   
}	  

template <class T>
void AVL<T>::SimpleIzquierda(AVL<T>::info_nodo *&n){
   	  
   typename AVL<T>::info_nodo *aux = n->hder;
   typename AVL<T>::info_nodo *padre = n->padre;
   int hijo=0;
   if (padre!=0){   
	        if (padre->hder==n) hijo=2;
	    else
	     hijo=1;
   }	    
  
   n->hder=aux->hizq;
   if (n->hder!=0) 
	 n->hder->padre=n;
   n->padre = aux;
   aux->padre=padre;
   aux->hizq=n; 
   if (aux->hizq!=0) aux->hizq->padre=aux;
   
   if (n==raiz)
	raiz = aux;
   n=aux;
   if (padre!=0){
    if (hijo==2) padre->hder=n;
    else if (hijo==1) padre->hizq=n;
   } 
   ActualizarAltura(n->hizq);
   ActualizarAltura(n);
   
}	

template <class T>
void AVL<T>::DobleIzquierdaDerecha(AVL<T>::info_nodo *&n){
   
   SimpleIzquierda(n->hizq);
   
   SimpleDerecha(n);
   
}	

template <class T>
void AVL<T>::DobleDerechaIzquierda(AVL<T>::info_nodo *&n){
   SimpleDerecha(n->hder);
  
   SimpleIzquierda(n);
}	


template <class T>
typename  AVL<T>::info_nodo* AVL<T>::Buscar( AVL<T>::info_nodo * n,const T &e){
	  if (n==0) return n;
	  else {
		if (n->et==e) return n;
		else
		 if (n->et>e) return Buscar(n->hizq,e);
		 else 
		    return Buscar(n->hder,e);
	  }
	 
}	

template <class T>
bool AVL<T>::Insertar(typename AVL<T>::info_nodo * &n,const T & x,typename AVL<T>::info_nodo *padre){
	if (n==0){
	 n = new info_nodo(x);
	
	 if (padre!=0)
	   n->padre=padre;
	 return true;
	}
	else if (x<n->et){
	       
	       if (Insertar(n->hizq,x,n)){
		
		
		switch(abs(Altura(n->hizq)-Altura(n->hder))){
			  case 0: return false;
			  case 1: 
				  n->altura++;
				  return true;
			  case 2: 
				    //caso A
				  if (Altura(n->hizq->hizq)>Altura(n->hizq->hder)){

					    SimpleDerecha(n);
				  }	    
				  else{ //caso B
						       
					    DobleIzquierdaDerecha(n);
				  }	    
				  return false;
		}//switch
	       }//if
	       	  
	}//else if 
	else if (x>n->et){
		 
	       if (Insertar(n->hder,x,n)){
			
			 switch (abs(Altura(n->hder)-Altura(n->hizq))){
				   case 0: return false;
				   case 1:
					   n->altura++;
					   return true;
				   case 2:
					     if (Altura(n->hder->hder)>Altura(n->hder->hizq)){

						       SimpleIzquierda(n);
					     }
					     else {

						       DobleDerechaIzquierda(n);
					     }    
					     return false;
			 }//switch
	       }//if
	       
	}//else if
}
	
template <class T>
void AVL<T>::PutHijo_Padre(AVL<T>::info_nodo *n,AVL<T>::info_nodo *nuevo){
		  if (n->padre!=0){
			    if (nuevo!=0)
				      nuevo->padre = n->padre;  
			    if (n->padre->hder==n){
					n->padre->hder = nuevo;
			    }
			    else n->padre->hizq=nuevo;
			    
		  }
}	
template <class T>
typename AVL<T>::info_nodo * AVL<T>::EliminarRaiz(AVL<T>::info_nodo *&n){
		if (n->hizq==0 && n->hder==0){
			     
			      typename AVL<T>::info_nodo * padre= n->padre;
			      PutHijo_Padre(n,0);
			      delete n;
			      typename AVL<T>::info_nodo * pp=padre;
			      if (padre!=0){
			       
			        AjustarArbol(pp);   
			      }
			      else raiz=0;
			      
			      return 0;
		}
		else if (n->hizq==0){
			    
			      AVL<T>::info_nodo *aux=n;
			      PutHijo_Padre(n,n->hder);
			      if (n==raiz){
			       n= n->hder;
			       	n->padre=0;
			      }
			     
			      delete aux;
			      typename AVL<T>::info_nodo * pp=n;
			   
			      AjustarArbol(pp);   
			      
			      return n;
			  
		}
		else if (n->hder==0){
			      AVL<T>::info_nodo *aux=n;
			      PutHijo_Padre(n,n->hizq);
			      if (n==raiz) {
					n = n->hizq;
					n->padre=0;
			      }		
			      delete aux;
			      typename AVL<T>::info_nodo * pp=n;
			      
			      AjustarArbol(pp);   
			      
			      return n;
		}
		else{
			 //buscamos el siguiente 
			
			AVL<T>::info_nodo *aux=n->hder;
			while (aux->hizq!=0){
				  aux=aux->hizq;
			}
			  
			n->et=aux->et;
			return Borrar(n->hder,aux->et);
			
		}
	  
}	  
template <class T>
typename AVL<T>::info_nodo * AVL<T>::Borrar(AVL<T>::info_nodo * &n,const T &e){
	  if (n!=0){
		 if (e==90) deb=true;
		 else deb=false;
		if (n->et==e){
		          
			return  EliminarRaiz(n);  
		}	  
		else if (n->et<e) 
			 return  Borrar(n->hder,e);
			  
		else return Borrar(n->hizq,e);
	  }
	  else return 0;
}
template <class T>
void AVL<T>::AjustarArbol(AVL<T>::info_nodo*& n){
     while (n!=0){
	      
	       
	       
	       ActualizarAltura(n);
	       int ahizq=Altura(n->hizq);
	       int ahder=Altura(n->hder);
	       
	       if (abs(ahizq-ahder)>1){
	         if (ahizq>ahder){
			  typename AVL<T>::info_nodo* hijo_izq=n->hizq;
			  if (Altura(hijo_izq->hizq)>=Altura(hijo_izq->hder))
					SimpleDerecha(n);
			  else
				     DobleIzquierdaDerecha(n);
		 }
		 else{
		      typename AVL<T>::info_nodo* hijo_der=n->hder;
			  if (Altura(hijo_der->hder)>=Altura(hijo_der->hizq))
					SimpleIzquierda(n);
			  else
				     DobleDerechaIzquierda(n);
		 }
	       }
	     
	       
	       n= n->padre;
	     
	       
	       
     }
}     
			  





/********************************************************/
/* 	FUNCIONES DE AVL                     */
/********************************************************/
template <class T>
AVL<T>::AVL(typename AVL<T>::nodo n){
	  raiz=n.p;
}	  



template <class T>
AVL<T>::AVL(const T &e){
	  raiz=new info_nodo(e);
}	  

template <class T>
AVL<T>::AVL(const AVL<T> & ab){
	  if (ab.raiz==0) raiz=0;
	  else
		    CopiarInfo(raiz,ab.raiz);
}		    

template <class T>
AVL<T> & AVL<T>::operator=(const AVL<T> & ab){
	  if (this!=&ab){
		    BorrarInfo(raiz);
		    CopiarInfo(raiz,ab.raiz);
	  }
}	  
	  
template <class T>	  
typename AVL<T>::nodo AVL<T>::getRaiz()const{
	 if (raiz!=0)
	   return typename AVL<T>::nodo(raiz);
	 else 
	 return typename AVL<T>::nodo();
}	 
template <class T>	 
bool AVL<T>::Insertar( const T &e){
	  
	  return Insertar(raiz,e,0);
}	  
template <class T>
void AVL<T>::Borrar(const T &e){
	  typename AVL<T>::info_nodo* aux=Borrar(raiz,e);
	  //cout<<"Vamos a ajustar desde "<<aux->et;
	  //AjustarArbol(aux);
}	  


template <class T>
void AVL<T>::clear(){
	  BorrarInfo(raiz);
	  raiz=0;
}	  
template <class T>
bool AVL<T>::empty()const {
	  return raiz==0;
}	  
template <class T>
unsigned int AVL<T>::size()const {
	  return numero_nodos(raiz);
}	  
template <class T>
bool AVL<T>::operator==(const AVL<T> &a)const {
	  return iguales(raiz,a.raiz);
}	  
	  
template <class T>
bool AVL<T>::operator!=(const AVL<T> &a)const{
	  return !(*this==a);
}	  




/***************************INORDEN_ITERDOR operator++**********************/
template <class T>
typename AVL<T>::nodo & AVL<T>::nodo::operator++(){
          if (p==0)
	    return *this;
          if (p->hder!=0) {
	       p= p->hder;
               while (p->hizq!=0)
                  p = p->hizq;
	  }
	  else {
	      while (p->padre!=0 &&
	         p->padre->hder == p)
	        p = p->padre;
	       // Si (padre de p es nulo), hemos terminado En caso contrario, 
		        //el siguiente a p es el padre
	      p  = p->padre;

           }
      return *this;
	  
}

/**FUNCIONES BEGIN y END */
template <class T>
typename AVL<T>::nodo AVL<T>::begin()const {
	   typename AVL<T>::info_nodo * n = raiz;

	  if (n!=0)
		 while (n->hizq!=0)
		    n = n->hizq;
 
	  typename AVL<T>::nodo nuevo(n);
	  return nuevo;
}	  
template <class T>
typename AVL<T>::nodo AVL<T>::end()const {
	 
	  typename AVL<T>::nodo nuevo(0);
	  return nuevo;
}












