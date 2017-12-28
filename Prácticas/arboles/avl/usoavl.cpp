#include "avl.h"
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
using namespace std;

void ListarAVL(AVL<int> &ab_bus){
  AVL<int>::nodo n;
 cout<<endl<<" Elementos ordenados con sus alturas: ";
 
 for (n=ab_bus.begin();n!=ab_bus.end();++n){
	   cout<<*n<<" ("<<n.altura()<< ") ";
 }
}
int main(){
 vector<int>v;
 int a;
 while (cin>>a){
	   v.push_back(a);
 }
cin.clear(); 
 AVL<int>ab_bus;
 
 for (int i=0;i<v.size();i++){

	   ab_bus.Insertar(v[i]);
	   cout<<endl<<"Insetando "<<v[i];
	   ListarAVL(ab_bus);

 }
 
 //ListarAVL(ab_bus);
    
int x;
bool salir=false;
cout<<endl<<"Dime un elemento a borrar: ";
while (!salir && cin>>x){
	 if (ab_bus.Buscar(x)){
	  //cout<<endl<<x<<" esta"<<endl;
	  ab_bus.Borrar(x);
	  
	  }
	  else{ 
	    cout<<"El elemento "<<x<<" no esta"<<endl;
	  }
	  
	  if (!ab_bus.empty()){
	   ListarAVL(ab_bus);	    
	   cout<<endl<<"Dime un elemento a borrar: ";
	  } 
	  else salir=true;
}

 
}