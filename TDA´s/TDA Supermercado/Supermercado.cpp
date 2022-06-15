#include "Supermercado.h"
Supermercado::Supermercado(unsigned int cajasTotales){
	if(cajasTotales <= 0){
		throw "El supermercado debe tener al menos una caja";
	}
	
	this->cajasTotales = cajasTotales;
	
	this->cajas = new Vector<Caja *>(this->cajasTotales + 1,  0);
	
	for(int i = 0; i < this->cajasTotales; i++){
		this->cajas->agregar(i + 1, 0);
	}
	
}


Supermercado::~Supermercado(){
	for(int i = 0; i < this->cajasTotales; i++){
		delete this->cajas->obtener(i);
	}
	delete []this->cajas;
}


void Supermercado::validarNumeroCaja(unsigned int numero){
	if(this->cajas->obtener(numero) == 0 ){
		throw "la caja no fue incorporada";
	}
	if(!((numero > 0) && (numero < this->getCajasTotales()))){
		throw "EL numero de caja no esta en rango";
	}
}


bool Supermercado::quedaLugar(){
	return (this->posicionLibre() != this->getCajasTotales());
}


int Supermercado::posicionLibre(){
	int posicionLibre = this->getCajasTotales();
	for(int i = this->getCajasTotales(); i > 0; i--){
		if(this->cajas->obtener(i) == 0){
			posicionLibre--;
		}
	}
	return posicionLibre;
}


void Supermercado::incorporarUnaCaja(){
	if(!quedaLugar()){
		throw "Se alcanzo el limite de cajas";
	}
	this->cajas->agregar(posicionLibre() + 1 , new Caja(posicionLibre() + 1));
}


void Supermercado::eliminarUnaCaja(unsigned int numeroCaja){
	validarNumeroCaja(numeroCaja);
	this->cajas->obtener(numeroCaja) = 0;
}


void Supermercado::ponerPersonaEnCaja(unsigned int numeroCaja){
	validarNumeroCaja(numeroCaja);
	this->cajas->obtener(numeroCaja)->agregarPersona();
}


unsigned int Supermercado::getCajaConMasPersonas(){
	Caja* masOcupada = this->cajas->obtener(1);
	for(int i = 0; i < this->cajasTotales; i++){
		if((this->cajas->obtener(i + 1) !=0 ) && (this->cajas->obtener(i + 1)->getPersonasEnFila() > masOcupada->getPersonasEnFila())){
			masOcupada = this->cajas->obtener(i + 1);
		}
	}	
	return masOcupada->getNumero();
}


int Supermercado::getCajasIncorporadas(){
	return this->posicionLibre();
}


int Supermercado::getCajasTotales(){
	return this->cajasTotales;
}
