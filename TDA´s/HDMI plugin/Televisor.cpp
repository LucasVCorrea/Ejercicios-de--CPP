#include "Televisor.h"

Televisor::Televisor(unsigned int cantidadEntradas){
	if(cantidadEntradas < MinimoPermitido){
		throw "Debe haber al menos una entrada HDMI";
	}
	
	this->cantidadEntradas = cantidadEntradas;
	this->entradas = new Vector<Entrada *>(this->cantidadEntradas, 0);
	this->estadoTV = FueraDeCable;
	
	for(int i = 1; i <= this->cantidadEntradas; i++){
		this->entradas->agregar(i, new Entrada(i));
	}
}


void Televisor::validarEntrada(unsigned int numero){
	if (!((numero >= MinimoPermitido) && (numero <= this->getCantidadEntradas()))){
		throw "la entrada seleccionada no existe";
	}
}

bool Televisor::fueActivada(unsigned int numero){
	return(this->entradas->obtener(numero)->getEstado() == Activada);
}

bool Televisor::estaEnCable(){
	return (this->estadoTV == EnCable);
}

bool Televisor::canalEnRango(){
	return((this->canalActual >= 0) && (this->canalActual <= CanalTope));
}

void Televisor::validarCanal(unsigned int canal){
	if((canal < 0 ) || (canal > CanalTope)){
		throw "el canal ingresado no existe";
	}
}

void Televisor::activarCable(){
	this->estadoTV = EnCable;
}

void Televisor::validarCable(){
	if(!estaEnCable()){
		throw "no esta la entrada de cable";
	}
}


Televisor::~Televisor(){
	for(int i = 1; i <= this->cantidadEntradas; i++){
		delete this->entradas->obtener(i);
	}
	delete this->entradas;
}

void Televisor::seleccionarCanal(unsigned int canal){
	validarCable();
	validarCanal(canal);
	this->canalActual = canal;
}

void Televisor::avanzarCanal(){
	this->canalActual++;
	if(!canalEnRango()){
		throw "no hay mas canales que recorrer";
	}
}

void Televisor::retrocederCanal(){
	this->canalActual--;
	if(!canalEnRango()){
		throw "no hay mas canales que recorrer";
	}
}

unsigned int Televisor::getMasUsada(){
	Entrada* masUsada = this->entradas->obtener(1);
	for(int i = 1; i <= this->getCantidadEntradas(); i++){
		if(this->entradas->obtener(i)->getCantidadDeUsos() > masUsada->getCantidadDeUsos()){
			masUsada = this->entradas->obtener(i);
		}
	}
	return masUsada->getNumero();
}

unsigned int Televisor::getEntradaActual(){
	return this->entradaActual->getNumero();
}

unsigned int Televisor::getCantidadEntradas(){
	return this->cantidadEntradas;
}

void Televisor::activarEntrada(unsigned int numero){
	validarEntrada(numero);

	this->entradas->obtener(numero)->activar();
}

void Televisor::desactivadEntrada(unsigned int numero){
	this->entradas->obtener(numero)->desactivar();
}

void Televisor::seleccionarEntrada(unsigned int numero){
	validarEntrada(numero);

	if(!fueActivada(numero)){
		throw "primero debe activar la entrada";
	}
	
	this->entradaActual = this->entradas->obtener(numero);
	this->entradas->obtener(numero)->seleccionar();
}

unsigned int Televisor::getCanalActual(){
	return this->canalActual;
}




