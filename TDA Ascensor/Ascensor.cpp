#include "Ascensor.h"

Ascensor::Ascensor(int cantidadDePisos){
	if(cantidadDePisos < 0){
		throw "Los pisos son mayores o iguales a 0";
	}
	this->cantidadDePisos = cantidadDePisos;
	this->totalDeBajadas = 0;
	this->totalDeSubidas = 0;
	this->pisoActual = 0;
	this->desplazamiento = 0;
	this->pisos = new Piso*[this->cantidadDePisos];
	
	for(int i = 0;i<=this->cantidadDePisos;i++){
		this->pisos[i] = new Piso(i);
	}
}

Ascensor::~Ascensor(){
	for(int i = 0;i<=this->cantidadDePisos;i++){
		delete this->pisos[i];
	}
	delete this->pisos;
}

void Ascensor::validarDireccionamiento(int piso){
	
	if(piso > this->getPisoActual()){
		this->totalDeSubidas += this->getDesplazamiento();
	}
	
	if(piso < this->getPisoActual()){
		this->totalDeBajadas -= this->getDesplazamiento();
	}
}

int Ascensor::getCantidadDePisos(){
	return this->cantidadDePisos;
}

int Ascensor::getPisoActual(){
	return this->pisoActual;
}
int Ascensor::getTotalDePisosSubidos(){
	return this->totalDeSubidas;
}

int Ascensor::getTotalDePisosBajados(){
	return this->totalDeBajadas;
}

int Ascensor::getDesplazamiento(){
	return this->desplazamiento;
}


void Ascensor::llamarDesde(int piso){
	if((piso < 0) || (piso > this->getCantidadDePisos())){
		throw "El piso no existe";
	}
	
	if(piso == this->getPisoActual()){
		throw "El ascensor ya esta en ese piso";
	}
	this->desplazamiento = (piso - this->pisoActual);
	validarDireccionamiento(piso);
	this->pisoActual = piso;
	this->pisos[piso]->contarAparicion();

}

int Ascensor::getCantidadDeVecesQueFueAlPiso(int piso){
	if((piso < 0) || (piso > this->getCantidadDePisos())){
		throw "El piso no existe";
	}
	
	return this->pisos[piso]->getCantidadDeApariciones();
}

int Ascensor::getPiso(int pisoDeMuestra){
	return pisoDeMuestra;
}




