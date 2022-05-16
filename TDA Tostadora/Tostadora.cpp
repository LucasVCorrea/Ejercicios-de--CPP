#include "Tostadora.h"
#include <iostream>
Tostadora::Tostadora(int cantidadDeRanuras){
	
	if (cantidadDeRanuras < 1){
		throw "La tostadora debe tener almenos una ranura";
	}
	this->cantidadDeRanuras = cantidadDeRanuras;
	this->estadoTostadora = Apagada;
	this->nivelDeCalor = 1;	
	
	this->ranuras = new Ranura*[this->cantidadDeRanuras];
	
	for (int i=1;i<=this->cantidadDeRanuras;i++){
		this->ranuras[i] = new Ranura(i);
	}

}	


Tostadora::~Tostadora(){
	for (int i=1;i<=this->cantidadDeRanuras;i++){
		delete this->ranuras[i];
	}
	delete this->ranuras;
}


unsigned int Tostadora::getCantidadDeRanuras(){
	return this->cantidadDeRanuras;
}

void Tostadora::encender(){
	this->estadoTostadora = Encendida;
}

void Tostadora::apagar(){
	this->estadoTostadora = Apagada;
}


estadoDeTostadora Tostadora::getEstado(){
	return this->estadoTostadora;
}


void Tostadora::iniciarTostado(int numeroDeRanura){
	if (this->getEstado() == Apagada){
		throw "La tostadora esta apagada";
	}
	validarNumeroDeRanura(numeroDeRanura);
	this->ranuras[numeroDeRanura]->ocupar();
}



void Tostadora::finalizarTostado(int numeroDeRanura){
	if (this->getEstado() == Apagada){
		throw "la tostadora esta apagada";
	}
	validarNumeroDeRanura(numeroDeRanura);
	this->ranuras[numeroDeRanura]->liberar();
}


void Tostadora::validarNumeroDeRanura(int numeroDeRanura){
	if (numeroDeRanura <= 0){
		throw "El numero de ranura debe ser mayor o igual a 1";
	}
	if (numeroDeRanura > this->cantidadDeRanuras ){
		throw "El numero de ranura no existe";
	}
}

unsigned int Tostadora::getRanurasLibres(){
	unsigned int cantidad = 0;
	for (int i = 1; i <= this->getCantidadDeRanuras();i++){
		if (this->ranuras[i]->getEstado()==Libre){
			cantidad++;
		}
	}
	return cantidad;
}

void Tostadora::setNivelDeCalor(unsigned int nivelDeCalor){
	if ((nivelDeCalor < 1) || (nivelDeCalor > NivelDeCalorMaximo)){
		throw "El nivel de calor debe ser mayor a 1 y menor a 10";
	}
	this->nivelDeCalor = nivelDeCalor;
}

unsigned int Tostadora::getRanuraMasUsada(){
	Ranura * mayor = this->ranuras[1];
	for (int i = 2; i<=this->getCantidadDeRanuras();i++){
		if (this->ranuras[i]->getCantidadDeUsos() > mayor->getCantidadDeUsos() ){
			mayor = this->ranuras[i];
		}
	}
	return mayor->getNumero() ;
}

