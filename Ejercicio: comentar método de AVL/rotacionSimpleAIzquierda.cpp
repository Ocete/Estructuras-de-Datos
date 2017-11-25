template <class Tbase>
void AVL<Tbase>::rotacionSimpleAIzquierda(Nodo &n){
  assert(n!=nodonulo);
  enum hijo {izquierdo, derecho};
  hijo que_hijo;
  Nodo padre = arbolb.padre(n);

  cout << "RSI " << arbolb.etiqueta(n) << endl;

  ArbolBinario<Tbase> a;
  //Podamos el subárbol derecho del nodo
  //en el que se ha producido el desequilibrio
  arbolb.podar_derecha(n, a);

  ArbolBinario<Tbase> aux;

  if(padre!=nodonulo){
    //Podamos el nodo en el que se ha producido el desequilibrio
    //y anotamos qué hijo era, si el derecho o el izquierdo
    if(arbolb.izquierda(padre)==n){
      arbolb.podar_izquierda(padre, aux);
      que_hijo = izquierdo;
    }
    else{
      arbolb.podar_derecha(padre, aux);
      que_hijo = derecho;
    }

    ArbolBinario<Tbase> b;
    //Podamos el hijo izquierdo del hijo derecho,
    //que habíamos podado antes y habíamos guardado en a
    a.podar_izquierda(a.raiz(), b);
    //Insertamos la rama podada como hijo derecho
    //del nodo n, el que estaba desequilibrado
    aux.insertar_derecha(aux.raiz(), b);
    //Insertamos el nodo n como hijo izquierdo
    //del que era el hijo derecho
    a.insertar_izquierda(a.raiz(), aux);

    //Reubicamos la rama rotada como hija del padre de n
    if(que_hijo == izquierdo){
      arbolb.insertar_izquierda(padre, a);
      n = arbolb.izquierda(padre);
    }
    else{
      arbolb.insertar_derecha(padre, a);
      n = arbolb.derecha(padre);
    }
  }
  else{
    //En el caso en el que n es la raíz del árbol,
    //la rotación se simplifica, ya que no tenemos
    //que reenganchar la rama rotada como hija del padre.
    //Directamente, esa rama es el árbol
    aux = arbolb;

    ArbolBinario<Tbase> b;
    a.podar_izquierda(a.raiz(), b);
    aux.insertar_derecha(aux.raiz(), b);
    a.insertar_izquierda(a.raiz(), aux);
    arbolb = a;
    n = arbolb.raiz();
  }
}
