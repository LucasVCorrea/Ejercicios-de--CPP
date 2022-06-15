#include <iostream>
#include "Supermercado.h"

using namespace std;

int main(){
	Supermercado *supermercado = new Supermercado(8);
	supermercado->incorporarUnaCaja();
	supermercado->ponerPersonaEnCaja(1);
	delete supermercado;
	return 0;
}
