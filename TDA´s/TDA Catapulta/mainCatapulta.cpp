#include <iostream>
#include "Catapulta.h"

using namespace std;

int main(){

	Catapulta *catapulta = new Catapulta(50);
	catapulta->cargar(25);
	catapulta->disparar();

	delete catapulta;
	return 0;
}
