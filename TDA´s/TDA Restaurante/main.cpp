#include <iostream>
#include "Restaurante.h"

using namespace std;

int main(){
	try{
		
	
	Restaurante *restaurante = new Restaurante(15);
	
	restaurante->adicionarEnMesa(450, 11);
	restaurante->adicionarEnMesa(250, 12);
	restaurante->adicionarEnMesa(250, 4);
	restaurante->cerrarMesa(11);
	restaurante->cerrarMesa(12);
	cout<<"Mesas Libres: "<< restaurante->getMesasLibres() <<" "<<endl;
	cout<<"Total recaudado: $"<< restaurante->getTotalRecaudado() <<" "<<endl;	
	
	delete restaurante;
	
	}catch(const char* x ){
		cout<< x <<endl;
	}
	
	return 0;
}
