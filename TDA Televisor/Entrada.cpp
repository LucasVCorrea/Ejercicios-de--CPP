#include "Entrada.h"

Entrada::Entrada(int numero){
	if (numero <=0){
		throw "Al menos debe haber una entrada HDMI";
	}
	this->numero = numero;
	this->estado = Desactivada;
	this->cantidadDeUsos = 0;
}

Entrada::~Entrada(){
	
}

void Entrada::activar(){
	if(this->getEstado()==Activada){
		throw "la entrada ya esta activa";
	}
	this->estado = Activada;
}

void Entrada::desactivar(){
	this->estado = Desactivada;
}

void Entrada::seleccionar(){
	this->estado = Seleccionada;
	this->cantidadDeUsos++;
}

estadoDeEntrada Entrada::getEstado(){
	return this->estado;
}

unsigned int Entrada::getNumero(){
	return this->numero;
}


unsigned int Entrada::getCantidadDeUsos(){
	return this->cantidadDeUsos;
}

