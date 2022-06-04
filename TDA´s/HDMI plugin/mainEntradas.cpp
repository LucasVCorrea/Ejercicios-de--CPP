#include <iostream>
#include "Televisor.h"

using namespace std;

int main(){
	
	Televisor *televisor = new Televisor(14);
	televisor->activarCable();
	televisor->activarEntrada(13);
	televisor->seleccionarEntrada(13);
	televisor->seleccionarCanal(23);
	
	delete televisor;
	return 0;
}
