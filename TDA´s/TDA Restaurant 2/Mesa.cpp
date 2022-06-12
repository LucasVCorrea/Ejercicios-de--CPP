#include "Mesa.h"

Mesa::Mesa(unsigned int numeroDeMesa){
	if(numeroDeMesa < 1){
		throw "El numero de mesa debe ser mayor o igual a 1";
	}
	this->numeroDeMesa = numeroDeMesa;
	this->cantidadDeSillas = 0;
	this->recordDeSillas = 0;
	this->estado = Libre;
}

Mesa::~Mesa(){
	
}

EstadoDeMesa Mesa::getEstado(){
	return this->estado;
}

bool Mesa::estaOcupada(){
	return (this->getEstado() == Ocupada);
}

bool Mesa::estaInhabilitada(){
	return (this->getEstado() == Indisponible);
}

void Mesa::ocupar(){
	if(estaOcupada()){
		throw "la mesa ya esta ocupada";
	}
	if(estaInhabilitada()){
		throw "la mesa esta inhabilitada";
	}
	this->estado = Ocupada;
}

void Mesa::liberar(){
	if(!estaOcupada() && !estaInhabilitada()){
		throw "la mesa ya esta libre";
	}
	this->estado = Libre;
}

void Mesa::indisponibilizar(){
	if(estaOcupada()){
		throw "la mesa esta ocupada";
	}
	this->estado = Indisponible;
}

void Mesa::agregarSilla(){
	this->cantidadDeSillas++;
	this->recordDeSillas++;
}

void Mesa::eliminarSilla(){
	this->cantidadDeSillas--;
	if(this->cantidadDeSillas < 0){
		throw "la mesa no tiene sillas";
	}
}

int Mesa::getCantidadDeSillas(){
	return this->cantidadDeSillas;
}

int Mesa::getRecordDeSillas(){
	return this->recordDeSillas;
}
