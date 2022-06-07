#include "Piso.h"

Piso::Piso(unsigned int numero){
	if(numero < 0){
		throw "El piso registrado es invalido";
	}
	
	this->numero = numero;
	this->cantidadVisitas = 0;
}

Piso::~Piso(){
	
}

unsigned int Piso::getCantidadVisitas(){
	return this->cantidadVisitas;
}

unsigned int Piso::getNumero(){
	return this->numero;
}

void Piso::registrarVisita(){
	this->cantidadVisitas++;
}
