#include <iostream>
#include "Conjunto.h"

using namespace std;

int main(){
	Conjunto<int> *arrayDinamico = new Conjunto<int>(9,69);
	
	
	arrayDinamico->agregar(28);
	arrayDinamico->agregar(14);
	arrayDinamico->agregar(88);
	arrayDinamico->agregar(58);
	arrayDinamico->agregar(99);


	for(int i=0; i<arrayDinamico->getSize(); i++){
		
		cout<<arrayDinamico->mostrarElementoEnPosicion(i)<<' ';		
	}
	
	cout<<endl<<endl<<"Quedan "<<arrayDinamico->getEspacioDisponible()<< " lugares disponibles";
	delete arrayDinamico;
	return 0;
}
