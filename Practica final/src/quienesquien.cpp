#include "../include/quienesquien.h"
#include <sstream>
#include <iostream>
#include <iterator>
#include <math.h>
#include <algorithm>

#include <list> // Para eliminar_nodos_redundantes
#include <vector>
#include <stack>

QuienEsQuien::QuienEsQuien(){
	jugada_actual = arbol.root();
}

QuienEsQuien::QuienEsQuien(const QuienEsQuien &quienEsQuien){
	personajes = quienEsQuien.personajes;
	atributos = quienEsQuien.atributos;
	tablero = quienEsQuien.tablero;
	arbol = quienEsQuien.arbol;
	// jugada_actual = quienEsQuien.jugada_actual; Esto hay que hacerlo bien
}

QuienEsQuien& QuienEsQuien::operator= (const QuienEsQuien &quienEsQuien){
	if (&quienEsQuien != this) {
		this->limpiar();
		personajes = quienEsQuien.personajes;
		atributos = quienEsQuien.atributos;
		tablero = quienEsQuien.tablero;
		arbol = quienEsQuien.arbol;
		// jugada_actual = quienEsQuien.jugada_actual; Esto hay que hacerlo bien
	}
	return *this;
}

QuienEsQuien::~QuienEsQuien(){
	this->limpiar();
}

void QuienEsQuien::limpiar(){
	personajes.clear();
	atributos.clear();
	tablero.clear();
	arbol.clear();
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
  if ( !v.empty() ) {
    out << '[';
    std::copy (v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
    out << "\b\b]";
  }
  return out;
}

void QuienEsQuien::mostrar_estructuras_leidas(){
	cout << "personajes: "<< (this->personajes) << endl;
	cout << "atributos:  "<< (this->atributos)  << endl;
	cout << "tablero:    "<< endl;

	// Escribe la cabecera del tablero
	for(vector<string>::iterator it_atributos = this->atributos.begin();
		it_atributos != this->atributos.end();
		it_atributos++){
		cout << *it_atributos << "\t";
	}
	cout <<endl;

	int indice_personaje = 0;
	for(vector<vector<bool>>::iterator it_tablero_atributos = tablero.begin();
		it_tablero_atributos!= tablero.end();
		it_tablero_atributos++){

		string personaje = this->personajes[indice_personaje];
		int indice_atributo = 0;
		for(vector<bool>::iterator it_atributos_personaje = (*it_tablero_atributos).begin();
			it_atributos_personaje != (*it_tablero_atributos).end();
			it_atributos_personaje++){

			cout << *it_atributos_personaje<<"\t";

			indice_atributo++;
		}

		cout << personaje << endl;

		indice_personaje++;
	}
}

/**
  * @brief Devuelve una copia de la cadena original sin las subcadenas no deseadas.
  *
  * @param cadena_original Cadena de la que se eliminan las subcadenas no deseadas.
  * @param cadena_a_eliminar Subcadena que se busca y se elimina.
  *
  * @return Copia de la cadena original sin las subcadenas no deseadas.
  */
string limpiar_string(string cadena_original,string cadena_a_eliminar){
	string linea(cadena_original);

	while(linea.find_first_of(cadena_a_eliminar) != std::string::npos){
		linea.erase(linea.find_first_of(cadena_a_eliminar),cadena_a_eliminar.length());
	}

	return linea;
}

istream& operator >> (istream& is, QuienEsQuien &quienEsQuien) {
	quienEsQuien.limpiar();

  	if(is.good()){
  		string linea;
    	getline(is, linea, '\n');

    	linea = limpiar_string(linea,"\r");

    	while(linea.find('\t') != string::npos ){
    		string atributo = linea.substr(0,linea.find('\t'));
			quienEsQuien.atributos.push_back(atributo);
    		linea = linea.erase(0,linea.find('\t')+1);
    	}

		assert(linea ==  "Nombre personaje");
	}

    while( is.good() ) {
    	string linea;
    	getline(is, linea, '\n');
    	linea = limpiar_string(linea,"\r");

    	//Si la linea contiene algo extrae el personaje. Si no lo es, la ignora.
    	if(linea != ""){;
	    	vector<bool> atributos_personaje;

	    	int indice_atributo=0;
	    	while(linea.find('\t') != string::npos){
	    		string valor = linea.substr(0,linea.find('\t'));

	    		assert(valor == "0" || valor == "1");

	    		bool valor_atributo = valor == "1";

	    		atributos_personaje.push_back(valor_atributo);

	    		linea = linea.erase(0,linea.find('\t')+1);
	    		indice_atributo++;
			}

			string nombre_personaje = linea;

	    	quienEsQuien.personajes.push_back(nombre_personaje);
	    	quienEsQuien.tablero.push_back(atributos_personaje);
	    }
  	}

	return is;
}

ostream& operator << (ostream& os, const QuienEsQuien &quienEsQuien){

	//Escribimos la cabecera, que contiene los atributos y al final una columna para el nombre
	for(vector<string>::const_iterator it_atributos = quienEsQuien.atributos.begin();
		it_atributos != quienEsQuien.atributos.end();
		it_atributos++){

		os  << *it_atributos << "\t";
	}
	os << "Nombre personaje" << endl;

	//Rellenamos con ceros y unos cada l�nea y al final ponemos el nombre del personaje.
	for(int indice_personaje=0;indice_personaje<quienEsQuien.personajes.size();indice_personaje++){
		for(int indice_atributo=0;indice_atributo<quienEsQuien.personajes.size();indice_atributo++){

			os  << quienEsQuien.tablero[indice_personaje][indice_atributo] << "\t";
		}
		os  << quienEsQuien.personajes[indice_personaje] << endl;
	}

	return os;
}

/**
  * @brief Convierte un n�mero a un vector de bool que corresponde
  *        con su representaci�n en binario con un numero de digitos
  *        fijo.
  *
  * @param n N�mero a convertir en binario.
  * @param digitos N�mero de d�gitos de la representaci�n binaria.
  *
  * @return Vector de booleanos con la representaci�n en binario de @e n
  *      con el n�mero de elementos especificado por @e digitos.

  */
vector<bool> convertir_a_vector_bool(int n, int digitos) {
  vector<bool> ret;
  while(n) {
    if (n&1){
      ret.push_back(true);
    } else{
      ret.push_back(false);
    }
    n>>=1;
  }

  while(ret.size()<digitos){
  	ret.push_back(false);
  }

  reverse(ret.begin(),ret.end());
  return ret;
}

void QuienEsQuien::crear_arbol_recursivo(bintree<Pregunta> & arbol, int num_pregunta,
			const vector<bool> & personajes_levantados) {
	if (num_pregunta > atributos.size()) {
		cerr << "Error al crear el arbol." << endl;
		cerr << "Insuficientes atributos para el número de personajes dado." << endl;
	}
	vector<bool> personajes_si, personajes_no;
	int num_pjs_levantados = 0, pos_pj_levantado = -1;
	bool existe_pj_si = false, existe_pj_no = false;

	for (int i=0; i<personajes.size(); i++) {
		bool b1 = false, b2 = false;
		if ( personajes_levantados[i] ) {
			num_pjs_levantados++;
			if ( tablero[i][num_pregunta] ) {
				b1 = true;
				existe_pj_si = true;
			} else {
				b2 = true;
				existe_pj_no = true;
			}
			if (pos_pj_levantado == -1) {
				pos_pj_levantado = i;
			}
		}
		personajes_si.push_back(b1);
		personajes_no.push_back(b2);
	}

	if (num_pjs_levantados > 1) {
		Pregunta pregunta (atributos[num_pregunta], num_pjs_levantados);
		bintree<Pregunta> arbol_aux(pregunta), arbol_izq, arbol_der;
		arbol = arbol_aux;
		if (existe_pj_si) {
			crear_arbol_recursivo(arbol_izq, num_pregunta+1, personajes_si);
			arbol.insert_left(arbol.root(), arbol_izq);
		}
		if (existe_pj_no) {
			crear_arbol_recursivo(arbol_der, num_pregunta+1, personajes_no);
			arbol.insert_right(arbol.root(), arbol_der);
		}
	} else {
		Pregunta pregunta (personajes[pos_pj_levantado], 1);
		bintree<Pregunta> arbol_aux(pregunta);
		arbol = arbol_aux;
	}
}

bintree<Pregunta> QuienEsQuien::crear_arbol() {
	vector<bool> personajes_levantados;
	for (int i=0; i<personajes.size(); i++) {
		bool b = true;
		personajes_levantados.push_back(b);
	}
	bintree<Pregunta> arbol;
	crear_arbol_recursivo(arbol, 0, personajes_levantados);
	return arbol;
}

void QuienEsQuien::usar_arbol(bintree<Pregunta> arbol_nuevo){
	arbol = arbol_nuevo;
}

void QuienEsQuien::iniciar_juego(){
	jugada_actual = arbol.root();
	char c;
	string str;
	while ( (*jugada_actual).es_pregunta() ) {
		do {
			cout << "\t¿Es " << (*jugada_actual).obtener_pregunta() << "? (s/n/p)" << endl << "\t";
			cin >> c;
		} while (c != 's' && c != 'n' && c != 'p');
		if (c == 's') {
			str = "si";
			jugada_actual = jugada_actual.left();
		} else if (c == 'n') {
			str = "no";
			jugada_actual = jugada_actual.right();
		} else {
			str = "mostrar preguntas formuladas";
			preguntas_formuladas(jugada_actual);
		}
		cout << "\tHa contestado: " << str << endl;
	}
	cout << "\n\tTu personaje es " << (*jugada_actual).obtener_personaje() << endl;
	cout << "\n\tFIN DEL JUEGO" << endl;
}

set<string> QuienEsQuien::informacion_jugada(bintree<Pregunta>::node jugada_actual){
	set<string> personajes_levantados, aux;
	if ( (*jugada_actual).es_personaje() ) {
		personajes_levantados.insert( (*jugada_actual).obtener_personaje() );
	} else {
		aux = informacion_jugada(jugada_actual.left());
		personajes_levantados.insert(aux.begin(), aux.end());
		aux = informacion_jugada(jugada_actual.right());
		personajes_levantados.insert(aux.begin(), aux.end());
	}
	return personajes_levantados;
}

void escribir_esquema_arbol(ostream& ss,
					  const bintree<Pregunta>& a,
		    		  bintree<Pregunta>::node n,
					  string& pre){
	if (n.null()){
	    ss << pre << "-- x" << endl;
	} else {
	    ss << pre << "-- " << (*n) << endl;
	    if ( !n.right().null() || !n.left().null()) {// Si no es una hoja
			pre += "   |";
	    	escribir_esquema_arbol(ss,a, n.right(), pre);
	     	pre.replace(pre.size()-4, 4, "    ");
	      	escribir_esquema_arbol (ss,a, n.left(), pre);
	      	pre.erase(pre.size()-4, 4);
	    }
  	}
}

void QuienEsQuien::escribir_arbol_completo() const{
	string pre = "";
	escribir_esquema_arbol(cout,this->arbol,this->arbol.root(),pre);
}

/*
	COMENTAR ESTO
*/

void QuienEsQuien::eliminar_nodos_redundantes(){
	bintree<Pregunta> rama;
	bintree<Pregunta>::node nodo_en_estudio;
	bintree<Pregunta>::preorder_iterator it;
	bool izquierda_coja;

	// Elminamos los nodos redundantes que cuelgan directamente de la raiz
	izquierda_coja = arbol.root().left().null();
	while (izquierda_coja || arbol.root().right().null()) {
		if (izquierda_coja) {
			arbol.prune_right(arbol.root(), arbol);
		} else {
			arbol.prune_left(arbol.root(), arbol);
		}
	}

	vector<bintree<Pregunta>::node> hijos;
	list<bintree<Pregunta>::node> lista;
	lista.push_back(arbol.root());

	while (!lista.empty()) {
		nodo_en_estudio = lista.front();
		lista.pop_front();
		hijos.clear();
		hijos.push_back(nodo_en_estudio.left());
		hijos.push_back(nodo_en_estudio.right());
		for (int i=0; i<2; i++) {
			izquierda_coja = hijos[i].left().null();
			while ( (*hijos[i]).obtener_num_personajes() > 1 &&
					(izquierda_coja || hijos[i].right().null() ) ) {
				if (izquierda_coja) {
					arbol.prune_right(hijos[i], rama);
				} else {
					arbol.prune_left(hijos[i], rama);
				}
				if (i == 0) {
					arbol.insert_left(nodo_en_estudio, rama);
					hijos[0] = nodo_en_estudio.left();
				} else {
					arbol.insert_right(nodo_en_estudio, rama);
					hijos[1] = nodo_en_estudio.right();
				}
				izquierda_coja = hijos[i].left().null();
			}
		}
		if ( ( *(nodo_en_estudio.left()) ).obtener_num_personajes() > 1)
			lista.push_back(nodo_en_estudio.left());
		if ( ( *(nodo_en_estudio.right()) ).obtener_num_personajes() > 1)
			lista.push_back(nodo_en_estudio.right());
	}
}

/**
 * @brief Añade a suma_profundidades la suma de la profundidades de las hojas y
	a hojas el número de hojas encontrado a partir de nodo.
		profundidad es la profundidad de la hoja.

		REPASAR ESTO
**/

void profundidad_promedio_recursivo(const bintree<Pregunta>::node & nodo,
			int profundidad, int & num_hojas, int & suma_profundidades) {
	if ( nodo.left().null() && nodo.right().null() ) {
		suma_profundidades += profundidad;
		num_hojas++;
	} else {
		profundidad++;
		if ( !nodo.left().null() )
			profundidad_promedio_recursivo(nodo.left(), profundidad, num_hojas, suma_profundidades);
		if ( !nodo.right().null() )
			profundidad_promedio_recursivo(nodo.right(), profundidad, num_hojas, suma_profundidades);
	}
}

float QuienEsQuien::profundidad_promedio_hojas(){
	int num_hojas = 0, suma_profundidades = 0;
	profundidad_promedio_recursivo(arbol.root(), 0, num_hojas, suma_profundidades);
	return 1.0 * suma_profundidades / num_hojas;
}

/**
 * @brief Genera numero enteros positivos aleatorios en el rango [min,max).
**/

int generaEntero(int min, int max){
    int tam= max -min;
    return ((rand()%tam)+min);
}

void QuienEsQuien::tablero_aleatorio(int numero_de_personajes){
	srand(0);

	this->limpiar();

	float log_2_numero_de_personajes = log(numero_de_personajes)/log(2);

	int numero_de_atributos = ceil(log_2_numero_de_personajes);

	cout << "Petici�n para generar "<< numero_de_personajes<<" personajes ";
	cout << "con "<<numero_de_atributos<< " atributos"<<endl;
	cout << "Paso 1: generar "<< pow(2,numero_de_atributos) << " personajes"<<endl;

	//Fase 1: completar el tablero con todos los personajes posibles
	//Completo el tablero y los nombres de personajes a la vez
	for(int indice_personaje=0;indice_personaje< pow(2,numero_de_atributos);indice_personaje++){
		vector<bool> atributos_personaje = convertir_a_vector_bool(indice_personaje,numero_de_atributos);
		string nombre_personaje = "Personaje_"+to_string(indice_personaje);

		this->personajes.push_back(nombre_personaje);
		this->tablero.push_back(atributos_personaje);
	}

	// Completo los nombres de los atributos.
	for(int indice_atributo=0;indice_atributo<numero_de_atributos;indice_atributo++){
		string nombre_atributo = "Atributo_"+to_string(indice_atributo);
		this->atributos.push_back(nombre_atributo);
	}

	cout << "Paso 2: eliminar "<< (pow(2,numero_de_atributos)-numero_de_personajes) << " personajes"<<endl;
	//Fase 2. Borrar personajes aleatoriamente hasta que quedan solo los que hemos pedido.
	while(personajes.size()>numero_de_personajes){
		int personaje_a_eliminar = generaEntero(0,personajes.size());

		personajes.erase(personajes.begin()+personaje_a_eliminar);
		tablero.erase(tablero.begin()+personaje_a_eliminar);
	}
}

//////////////////////////////////
//				METODOS EXTRA         //
//////////////////////////////////

// Prec jugada != null

void QuienEsQuien::preguntas_formuladas (bintree<Pregunta>::node jugada) {
	bintree<Pregunta>::node aux = jugada;
	string str;
	stack<string> pila;

	cout << "\nEl personaje oculto tiene las siguientes características:" << endl;
	while (!aux.parent().null()) {
		str = ( *aux.parent() ).obtener_pregunta() + " - " ;
		str += aux == aux.parent().left() ? "Si" : "No";
		pila.push(str);
		aux = aux.parent();
	}
	while (!pila.empty()) {
		str = pila.top();
		pila.pop();
		cout << str << endl;
	}
	if ( (*jugada).es_personaje() ) {
		cout << "El personaje es " << (*jugada).obtener_personaje() << endl;
	} else {
		cout << "Aún no sé cuál es el personaje\n" << endl;
	}
}

//Prec.: Al menos dos personajes en el arbol
void QuienEsQuien::aniade_personaje (string nombre, vector<bool> caracteristicas) {
	int i_pregunta = 0;
	bintree<Pregunta>::node jugada = arbol.root(), jugada_padre;

	personajes.push_back(nombre);
	tablero.push_back(caracteristicas);

	// Buscamos la jugada en la que el arbol se expande
	// FALTA AQUI COMPROBAR QUE HALLA SUFICIENTES ATRIBUTOS PARA EL NUMERO DE PJS
	while ( (*jugada).es_pregunta() &&
				(*jugada).obtener_pregunta() == atributos[i_pregunta]) {
		jugada = caracteristicas[i_pregunta] ? jugada.left() : jugada.right();
		i_pregunta++;
	}

	// Actualizamos el nodo de la jugada y su subarbol.
	if (jugada == arbol.root()) {
		Pregunta pregunta (atributos[0], personajes.size()), pregunta_pj(nombre, 1);
		bintree<Pregunta> nuevo_arbol_raiz(pregunta), rama_pj(pregunta_pj), antigua_raiz;
		antigua_raiz = arbol;
		arbol = nuevo_arbol_raiz;
		if (caracteristicas[0]) {
			arbol.insert_right(arbol.root(), antigua_raiz);
			arbol.insert_left(arbol.root(), rama_pj);
		} else {
			arbol.insert_right(arbol.root(), rama_pj);
			arbol.insert_left(arbol.root(), antigua_raiz);
		}
	} else { //AQUI DA CORE
		jugada_padre = jugada.parent();
		Pregunta pregunta ( atributos[i_pregunta],
			(*jugada).obtener_num_personajes()+1 ), pregunta_pj(nombre, 1);
		bintree<Pregunta> nuevo_arbol_jugada(pregunta), rama_pj(pregunta_pj), rama_podada;
		if (jugada_padre.left() == jugada) {
			arbol.prune_left(jugada_padre, rama_podada);
			jugada = jugada_padre.left();
		} else {
			arbol.prune_right(jugada_padre, rama_podada);
			jugada = jugada_padre.right();
		}
		if (caracteristicas[i_pregunta]) {
			arbol.insert_right(jugada, rama_podada);
			arbol.insert_left(jugada, rama_pj);
		} else {
			arbol.insert_right(jugada, rama_pj);
			arbol.insert_left(jugada, rama_podada);
		}
	}

	// Actualizamos las conexiones del nuevo nodo
	if (true);

}

//Prec.: Al menos dos personajes en el arbol
void QuienEsQuien::elimina_personaje (string nombre) {
	int i_pj = 0, i_pregunta = 0;
	bintree<Pregunta>::node jugada = arbol.root(), jugada_padre;
	bintree<Pregunta> rama;

	while (personajes[i_pj] != nombre && i_pj < personajes.size()) {
		i_pj++;
	}

	if (i_pj == personajes.size()) {
		cerr << "No hay ningún personaje con dicho nombre" << endl;
	} else {
		while ( (*jugada).es_pregunta() ) {
			while (atributos[i_pregunta] != (*jugada).obtener_pregunta()) {
				i_pregunta++;
			}
			jugada = tablero[i_pj][i_pregunta] ? jugada.left() : jugada.right();
		}
	}

	// Eliminamos el personaje
	jugada_padre = jugada.parent();
	if (jugada_padre.left() == jugada) {
		arbol.prune_left(jugada_padre, rama);
		arbol.prune_right(jugada_padre, rama);
	} else {
		arbol.prune_right(jugada_padre, rama);
		arbol.prune_left(jugada_padre, rama);
	}

	// Reestructuramos el árbol
	if (jugada_padre == arbol.root()) {
		arbol = rama;
	} else {
		jugada = jugada_padre;
		jugada_padre = jugada_padre.parent();
		if (jugada_padre.left() == jugada) {
			arbol.insert_left(jugada_padre, rama);
		} else {
			arbol.insert_right(jugada_padre, rama);
		}
	}

	// Eliminamos al personaje del tablero y de los personajes
	vector<string>::iterator it1 = personajes.begin();
	vector<vector<bool> >::iterator it2 = tablero.begin();
	advance(it1, i_pj);
	advance(it2, i_pj);
	personajes.erase(it1);
	tablero.erase(it2);
}
