#include <iostream>
#include "Ascensor.h"

using namespace std;

int main(){
	try{
	
	Ascensor *elevador = new Ascensor(10);
	
	elevador->llamarDesde(6);
	
	elevador->llamarDesde(7);
	
	elevador->llamarDesde(8);

	elevador->llamarDesde(9);
	elevador->llamarDesde(2);
	elevador->llamarDesde(8);
	elevador->llamarDesde(0);
	elevador->llamarDesde(2);
	
	

	cout<<"El ascensor esta en el piso "<<elevador->getPisoActual()<<" (se desplazo "<<elevador->getDesplazamiento()<<" pisos respecto del anterior)"<<endl;

	cout<<"Cantidad de veces que fue al piso "<<elevador->getPiso(8)<<": "<<elevador->getCantidadDeVecesQueFueAlPiso(8)<<endl;
	cout<<"Cantidad de veces que fue al piso "<<elevador->getPiso(4)<<": "<<elevador->getCantidadDeVecesQueFueAlPiso(4)<<endl<<endl;
	
	cout<<"Subio en total "<<elevador->getTotalDePisosSubidos()<<" pisos"<<endl;
	cout<<"Bajo en total "<<elevador->getTotalDePisosBajados()<<" pisos"<<endl;
	
	
	}catch(const char *x){
		cout<< x <<endl;
	}
	return 0;
}
