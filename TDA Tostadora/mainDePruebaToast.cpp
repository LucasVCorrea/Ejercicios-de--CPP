#include <iostream>
#include "Ranura.h"
#include "Tostadora.h"

using namespace std;

int main(){
	try{
	
	Tostadora *miTostadora = new Tostadora(4);
	
	miTostadora->encender();
	
	miTostadora->setNivelDeCalor(6);
	
	miTostadora->iniciarTostado(2);
	miTostadora->finalizarTostado(2);
	
	cout<<"Ranura mas usada: "<<miTostadora->getRanuraMasUsada()<<endl;
	cout<<"Ranuras disponibles: "<<miTostadora->getRanurasLibres()<<endl;
	
	miTostadora->apagar();
	
	delete miTostadora;
	}catch(const char*a){
		cout<<"PROBLEMA:"<< a <<endl;
	}
	
	return 0;
}
