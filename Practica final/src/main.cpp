#include <fstream>
#include <iostream>
#include <string>
#include <math.h>

#include "../include/quienesquien.h"

using namespace std;

int main(int argc, char * argv[]){

	bool jugar = false;
	bool limpiar = false;
	QuienEsQuien quienEsQuien;

	if(argc == 2){
	string parametroAleatorio = "aleatorio";
	if(argv[1]== parametroAleatorio){
		cout << "Creando un QuienEsQuien aleatorio"<< endl;
		int numero_de_personajes;
   	int numero_de_atributos;

   	do{
   		cout << "¿Número de personajes? ";
   		cin >>numero_de_personajes;
   	}while(numero_de_personajes<=0);

   	quienEsQuien.tablero_aleatorio(numero_de_personajes);

   	string nombreFicheroSalida = string("datos/tablero") +
   		"-num-per="+to_string(numero_de_personajes);

   	cout << "Guardando tablero aleatorio en "<<nombreFicheroSalida<<endl;
   	ofstream archivoDeSalida(nombreFicheroSalida);
   	archivoDeSalida << quienEsQuien;

   	cout << "Guardado"<<endl;
   	return 0;
		}else{
			cout << "Cargando fichero para jugar'"<< argv[1] <<"'"<< endl;
			ifstream f (argv[1]);
			if (!f){
				cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
				return 1;
			}
			f>> quienEsQuien;
			jugar = true;
		}
	} else if(argc == 3 ){
		string parametroLimpiar = "limpiar";
		if(parametroLimpiar== argv[2]){
			cout << "Cargando fichero para limpiar (sin jugar) '"<< argv[1] <<"'"<< endl;
			ifstream f (argv[1]);
			if (!f){
				cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
				return 1;
			}
			f>> quienEsQuien;
			jugar = false;
		} else{
			cout << "Modo '"<<argv[2]<<"' no reconocido"<<endl;
			return 1;
		}

	} else {
		cout << "No se reconocen los argumentos. Ejemplos de uso:" << endl;
		cout << "\tJugar:               ./bin/quienesquien RUTA_FICHERO"<< endl;
		cout << "\tLimpiar sin jugar:   ./bin/quienesquien RUTA_FICHERO limpiar"<< endl;
		cout << "\tGenerar aleatorio:   ./bin/quienesquien aleatorio"<< endl;
		return 1;
	}

	quienEsQuien.mostrar_estructuras_leidas();
	quienEsQuien.usar_arbol(quienEsQuien.crear_arbol());

	cout << "=========== Arbol en crudo ===========" << endl;
	quienEsQuien.escribir_arbol_completo();

	cout << "Profundidad promedio de las hojas del arbol: ";
	cout << quienEsQuien.profundidad_promedio_hojas() << endl;
	cout << "======================================" << endl << endl << endl;

	quienEsQuien.eliminar_nodos_redundantes();

	cout << "=========== Arbol ===================="<<endl;
	quienEsQuien.escribir_arbol_completo();
	cout << "Profundidad promedio de las hojas del arbol: ";
	cout << quienEsQuien.profundidad_promedio_hojas()<<endl;
	cout << "======================================" << endl << endl << endl;

	if( jugar ){
		quienEsQuien.iniciar_juego();
	}

	cout << "\n\n========= Arbol antes de eliminar ===================="<<endl;
	quienEsQuien.escribir_arbol_completo();
	cout << "Profundidad promedio de las hojas del arbol: ";
	cout << quienEsQuien.profundidad_promedio_hojas()<<endl;
	cout << "========================================================" << endl << endl;

	cout << "Eliminemos a Ana del arbol" << endl;
	quienEsQuien.elimina_personaje("Ana");

	cout << "\n========= Arbol después de eliminar a Ana ============="<<endl;
	quienEsQuien.escribir_arbol_completo();
	cout << "Profundidad promedio de las hojas del arbol: ";
	cout << quienEsQuien.profundidad_promedio_hojas()<<endl;
	cout << "========================================================" << endl << endl;

	cout << "Eliminemos a Pilar del arbol" << endl;
	quienEsQuien.elimina_personaje("Pilar");

	cout << "\n========== Arbol después de eliminar a Pilar =========="<<endl;
	quienEsQuien.escribir_arbol_completo();
	cout << "Profundidad promedio de las hojas del arbol: ";
	cout << quienEsQuien.profundidad_promedio_hojas()<<endl;
	cout << "========================================================" << endl << endl << endl;

	quienEsQuien.mostrar_estructuras_leidas();

	cout << "Añadamos a Pilar al arbol" << endl;
	bool atributos_de_pilar[7] = {1,0,1,0,1,0,0};
	vector<bool> v_atr;
	for (int i=0; i<7; i++) v_atr.push_back(atributos_de_pilar[i]);
	quienEsQuien.aniade_personaje("Pilar", v_atr);

	cout << "\n========== Arbol después de añadir a Pilar ============"<<endl;
	quienEsQuien.escribir_arbol_completo();
	cout << "Profundidad promedio de las hojas del arbol: ";
	cout << quienEsQuien.profundidad_promedio_hojas()<<endl;
	cout << "========================================================" << endl << endl << endl;

	cout << "Añadamos a Pablo al arbol" << endl;
	bool atributos_de_pablo[7] = {0,1,1,0,1,0,0};
	v_atr.clear();
	for (int i=0; i<7; i++) v_atr.push_back(atributos_de_pablo[i]);
	quienEsQuien.aniade_personaje("Pablo", v_atr);

	cout << "\n========== Arbol después de añadir a Pablo ============"<<endl;
	quienEsQuien.escribir_arbol_completo();
	cout << "Profundidad promedio de las hojas del arbol: ";
	cout << quienEsQuien.profundidad_promedio_hojas()<<endl;
	cout << "========================================================" << endl << endl << endl;

	quienEsQuien.mostrar_estructuras_leidas();

	cout << "\n\nCreemos el árbol de nuevo utilizando entropía.\n\n" << endl;/*
	quienEsQuien.elimina_personaje("Pablo");
	quienEsQuien.elimina_personaje("Pilar");
	quienEsQuien.elimina_personaje("Ernesto");
	quienEsQuien.escribir_arbol_completo();*/

	quienEsQuien.usar_arbol(quienEsQuien.crear_arbol_con_entropia());

	cout << "\n============== Arbol creado con entropía ==============="<<endl;
	quienEsQuien.escribir_arbol_completo();
	cout << "Profundidad promedio de las hojas del arbol: ";
	cout << quienEsQuien.profundidad_promedio_hojas()<<endl;
	cout << "========================================================" << endl << endl << endl;

	return 0;
}
