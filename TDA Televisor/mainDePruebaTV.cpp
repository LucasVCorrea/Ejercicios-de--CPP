#include <iostream>
#include "Televisor.h"

using namespace std;

int main(){
	
	try{
		Televisor *televisorLG = new Televisor(4);
		televisorLG->prenderTelevisor();
		televisorLG->activarEntrada(3);
		televisorLG->activarEntrada(2);
		televisorLG->activarEntrada(4);
		
		televisorLG->seleccionarEntrada(2);
		televisorLG->cambiarDeCanal(102);
		cout<<"Viendo el canal: "<< televisorLG->getCanalActual() <<endl;
		
		televisorLG->seleccionarEntrada(2);
		televisorLG->cambiarDeCanal(55);
		televisorLG->pasarAlSiguienteCanal();
		cout<<"Viendo el canal: "<< televisorLG->getCanalActual() <<endl;

		televisorLG->seleccionarEntrada(2);
		televisorLG->cambiarDeCanal(75);
		televisorLG->pasarAlAnteriorCanal();
		cout<<"Viendo el canal: "<< televisorLG->getCanalActual() <<endl;
		
		televisorLG->seleccionarEntrada(3);
		televisorLG->cambiarDeCanal(90);
		televisorLG->pasarAlSiguienteCanal();
		cout<<"Viendo el canal: "<< televisorLG->getCanalActual() <<endl;
		cout<<"Entrada mas usada: "<< televisorLG->getEntradaMasUsada() <<endl;
		
		televisorLG->apagarTelevisor();
		delete televisorLG;
		
	}catch(const char*a){
		cout<< a <<endl;
	}
	
	return 0;
}
