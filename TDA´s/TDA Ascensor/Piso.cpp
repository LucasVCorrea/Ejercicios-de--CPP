#include "Piso.h"

Piso::Piso(int piso){
	if(piso < 0){
		throw "Piso incorrecto";
	}
	
	this->piso = piso;
	this->cantidadDeApariciones = 0;
}

Piso::~Piso(){
	
}

int Piso::getCantidadDeApariciones(){
	return this->cantidadDeApariciones;
}

int Piso::getNumero(){
	return this->piso;
}

void Piso::contarAparicion(){
	this->cantidadDeApariciones++;
}

