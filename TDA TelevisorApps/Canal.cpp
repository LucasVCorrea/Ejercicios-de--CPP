#include "Canal.h"

Canal::Canal(unsigned int numero){
	if(numero < 0){
		throw "El canal debe ser mayor o igual a 1";
	}
	this->numero = numero;
	this->canalActual = numero;
	this->cantidadDeVistas = 0;
	
}

Canal::~Canal(){
	
}
unsigned int Canal::getNumero(){
	return this->numero;
}

void Canal::agregarUnaVista(){
	this->cantidadDeVistas++;
}

int Canal::getCantidadDeVistas(){
	return this->cantidadDeVistas;
}
