#include "Televisor.h"
#include <iostream>
	Televisor::Televisor(unsigned int cantidadDeEntradas){
		if (cantidadDeEntradas <= 0){
			throw "El televisor debe tener al menos 1 entrada";
		}
		
		this->cantidadDeEntradas = cantidadDeEntradas;
		this->estado = Apagado;
		this->entradas = new Entrada*[this->cantidadDeEntradas];
		this->canalActual = 1;
		
		for (int i=1; i<=this->cantidadDeEntradas;i++){
			this->entradas[i] = new Entrada(i);
		}
		
	}
	
	Televisor::~Televisor(){
		for (int i=1; i<=this->cantidadDeEntradas;i++){
			delete this->entradas[i];
		}
		delete this->entradas;
	}

unsigned int Televisor::getCantidadDeEntradas(){
	return this->cantidadDeEntradas;
}

estadoDelTelevisor Televisor::getEstado(){
	return this->estado;
}

void Televisor::prenderTelevisor(){
	this->estado = Prendido;
}

void Televisor::apagarTelevisor(){
	this->estado = Apagado;
}

unsigned int Televisor::getCanalActual(){
	return this->canalActual;
}

void Televisor::pasarAlSiguienteCanal(){
	validarEstado();
	if (this->getEntradasSeleccionadas() == 0){
		throw "debe haber almenos una entrada seleccionada";
	}
	this->canalActual++;
	validarCanales(this->getCanalActual());	
}

void Televisor::pasarAlAnteriorCanal(){
	validarEstado();
	if (this->getEntradasSeleccionadas() == 0){
		throw "debe haber almenos una entrada seleccionada";
	}
	this->canalActual--;
	validarCanales(this->getCanalActual());
}

void Televisor:: validarEntrada(unsigned int numeroDeEntrada){
	if (numeroDeEntrada <= 0){
		throw "Debe haber almenos una entrada";
	}
	if (numeroDeEntrada > this->getCantidadDeEntradas()){
		throw "La entrada no existe";
	}
}

void Televisor::validarEstado(){
	if (this->getEstado() == Apagado){
		throw "El televisor esta apagado";
	}
}


void Televisor::activarEntrada(unsigned int numeroDeEntrada){
	validarEstado();
	validarEntrada(numeroDeEntrada);
	this->entradas[numeroDeEntrada]->activar();
}

void Televisor::desactivarEntrada(unsigned int numeroDeEntrada){
	validarEstado();
	validarEntrada(numeroDeEntrada);
	if (this->entradas[numeroDeEntrada]->getEstado() == Desactivada){
		throw "La entrada ya esta desactivada";
	}
	validarEntrada(numeroDeEntrada);
	this->entradas[numeroDeEntrada]->desactivar();
}

void Televisor::seleccionarEntrada(unsigned int numeroDeEntrada){
	validarEstado();
	validarEntrada(numeroDeEntrada);
	if (this->entradas[numeroDeEntrada]->getEstado()==Desactivada){
		throw "Primero debe activar la entrada";
	}
	this->entradas[numeroDeEntrada]->seleccionar();
	
}

unsigned int Televisor::getEntradaMasUsada(){
	Entrada * mayor = this->entradas[1];
	for(int i=2;i<=this->getCantidadDeEntradas();i++){
		
		if(this->entradas[i]->getCantidadDeUsos() > mayor->getCantidadDeUsos()){
			mayor = this->entradas[i];
		}	
	}
	return mayor->getNumero();	
}

void Televisor::cambiarDeCanal(unsigned int canalActual){
	validarEstado();
	if (this->getEntradasSeleccionadas() == 0){
		throw "debe haber almenos una entrada seleccionada";
	}

	validarCanales(canalActual);
	this->canalActual = canalActual;
	
}

void Televisor::validarCanales(unsigned int canalActual){
	if (canalActual <=0){
		throw "Los canales comienzan en el 1";
	}
	if(canalActual>UltimoCanal){
		throw "El televisor tiene hasta 140 canales";
	}

}

unsigned int Televisor::getEntradasSeleccionadas(){
	unsigned int cantidadSeleccionadas = 0;
	for (int i =1; i<= this->getCantidadDeEntradas();i++){
		if (this->entradas[i]->getEstado()==Seleccionada){
			cantidadSeleccionadas++;
		}
	}
	return cantidadSeleccionadas;
}




