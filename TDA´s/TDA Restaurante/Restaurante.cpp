#include "Restaurante.h"
Restaurante::Restaurante(unsigned int cantidadDeMesas){
	if(cantidadDeMesas < 1){
		throw "debe haber al menos 1 mesa";
	}
	
	this->cantidadDeMesas = cantidadDeMesas;
	this->mesas = new Vector<Mesa *>(this->cantidadDeMesas, 0);
	
	for(int i = 1; i <= this->cantidadDeMesas; i++){
		this->mesas->agregar(i, new Mesa(i)) ;
	}
	
}

Restaurante::~Restaurante(){
	for(int i = 1; i <= this->cantidadDeMesas; i++){
		delete this->mesas->obtener(i);
	}
	delete []this->mesas;
}

void Restaurante::validarNumeroMesa(unsigned int numero){
	if((numero < 1) || (numero > this->getMesasTotales())){
		throw "la mesa debe ser mayor o igual a 1 y menor al maximo";
	}
}

unsigned int Restaurante::getMesasTotales(){
	return this->cantidadDeMesas;
}

void Restaurante::adicionarEnMesa(int monto,unsigned int numeroMesa){
	validarNumeroMesa(numeroMesa);
	this->mesas->obtener(numeroMesa)->agregarMonto(monto);
	this->mesas->obtener(numeroMesa)->abrir();
	
}

int Restaurante::cerrarMesa(unsigned int numeroMesa){
	validarNumeroMesa(numeroMesa);
	if(this->mesas->obtener(numeroMesa)->getEstado() == Libre){
		throw "la mesa ya esta libre";
	}
	this->mesas->obtener(numeroMesa)->liberar();
	return this->mesas->obtener(numeroMesa)->getTotal();
}

int Restaurante::getTotalRecaudado(){
	int total = 0;
	for(int i = 1; i <= this->getMesasTotales(); i++){
		total += ( this->mesas->obtener(i)->getTotal() );
	}
	return total;
}

unsigned int Restaurante::getMesasLibres(){
	unsigned int mesasLibres = 0;
	for(int i = 1; i <= this->getMesasTotales(); i++){
		if(this->mesas->obtener(i)->getEstado() == Libre){
			mesasLibres++;
		}
	}
	return mesasLibres;
}


