#include "Ascensor.h"

Ascensor::Ascensor(unsigned int cantidadPisos){
	if(cantidadPisos <= 0){
		throw "la cantidad de pisos debe ser mayor o igual a 1";
	}
	
	this->cantidadPisos = cantidadPisos;
	this->pisoActual = 0;
	this->bajadas = 0;
	this->subidas = 0;
	this->pisos = new Vector<Piso *>(this->cantidadPisos, 0);
	
	for(int i = 0; i < this->cantidadPisos; i++){
		this->pisos->agregar(i, new Piso(i));
	}
}

Ascensor::~Ascensor(){
	for(int i = 0; i < this->getCantidadPisos(); i++){
		delete this->pisos->obtener(i);
	}
	
	delete []this->pisos;
}

unsigned int Ascensor::getCantidadPisos(){
	return this->cantidadPisos;
}

unsigned int Ascensor::getPisoActual(){
	return this->pisoActual;
}

bool Ascensor::esValido(unsigned int piso){
	return ((piso >= 0) && (piso <= this->getCantidadPisos()));
}

void Ascensor::validarPiso(unsigned int piso){
	if(!esValido(piso)){
		throw "el piso ingresado no es valido";
	}
	if(piso == this->pisoActual){
		throw "El ascensor ya esta en ese piso";
	}
}

unsigned int Ascensor::recorrido(unsigned int piso){
	unsigned int pisosMovidos;
	if(piso > this->pisoActual){
		pisosMovidos = (piso - this->pisoActual);
		this->subidas++;
	}
	else{
		pisosMovidos = (this->pisoActual - piso);
		this->bajadas++;
	}
	return pisosMovidos;
}

unsigned int Ascensor::llamarAscensor(unsigned int piso){
	validarPiso(piso);
	
	unsigned int recorridoRealizado = recorrido(piso);
	this-> pisoActual = piso;
	this->pisos->obtener(piso)->registrarVisita();
	
	return recorridoRealizado;
}

unsigned int Ascensor::verHistorico(unsigned int piso){
	validarPiso(piso);
	return this->pisos->obtener(piso)->getCantidadVisitas();
}

unsigned int Ascensor::pisosBajados(){
	return this->bajadas;
}

unsigned int Ascensor::pisosSubidos(){
	return this->subidas;
}
