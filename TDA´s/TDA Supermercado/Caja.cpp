#include "Caja.h"
Caja::Caja(unsigned int numero){
	if(numero < 0){
		throw "El numero debe ser mayor o igual a 1";
	}
	this->numero = numero;
	this->personasEnFila = 0;
}


Caja::~Caja(){
	
}

void Caja::agregarPersona(){
	this->personasEnFila++;
}


unsigned int Caja::getNumero(){
	return this->numero;
}


int Caja::getPersonasEnFila(){
	return this->personasEnFila;
}
