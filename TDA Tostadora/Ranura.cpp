#include "Ranura.h"
Ranura::Ranura(int numero){
	if (numero < 1){
		throw "Debe haber almenos una ranura";
	}
	this->numero = numero;
	this->estado = Libre;
	this->cantidadDeUsos = 0;
}

Ranura::~Ranura(){
	
}

void Ranura::liberar(){
	this->estado = Libre;
}

void Ranura::ocupar(){
	if (this->estado == Ocupada){
		throw "la ranura esta ocupada";
	}
	
	this->estado = Ocupada;
	this->cantidadDeUsos++;
}

estadoDeRanura Ranura::getEstado(){
	return this->estado;
}

unsigned int Ranura::getCantidadDeUsos(){
	return this->cantidadDeUsos;
}

unsigned int Ranura::getNumero(){
	return this->numero;
}
