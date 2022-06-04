#include "Entrada.h"

Entrada::Entrada(unsigned int numero){
	if(numero < 1){
		throw "el numero de entrada debe ser mayor o igual a 1";
	}
	
	this->numero = numero;
	this->cantidadDeUsos = 0;
	this->estado = Desactivada;
}

Entrada::~Entrada(){
	
}

void Entrada::activar(){
	this->estado = Activada;

}

void Entrada::desactivar(){
	this->estado = Desactivada;
}

void Entrada::seleccionar(){
	this->cantidadDeUsos++;
}

unsigned int Entrada::getCantidadDeUsos(){
	return this->cantidadDeUsos;
}

unsigned int Entrada::getNumero(){
	return this->numero;
}

estadoDeEntrada Entrada::getEstado(){
	return this->estado;
}
