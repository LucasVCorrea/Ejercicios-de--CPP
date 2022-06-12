#include "Restaurant.h"
Restaurant::Restaurant(unsigned int maximoDeMesas){
	if(maximoDeMesas < 1){
		throw "El maximo de mesas debe ser mayor o igual a 1";
	}
	
	this->maximoDeMesas = maximoDeMesas;
	this->estado = Cerrado;
	this->recordDeMesas = 0;
	this->mesas = new Vector<Mesa *>(this->maximoDeMesas,0);
	for(int i = 0; i < this->maximoDeMesas; i++){
		this->mesas->agregar(i + 1, 0);
	}
}

Restaurant::~Restaurant(){
	for(int i = 0; i < this->maximoDeMesas; i++){
		delete this->mesas->obtener(i);
	}
	delete []this->mesas;
}



bool Restaurant::estaAbierto(){
	return (this->getEstado() == Abierto);
}


void Restaurant::abrirRestaurant(){
	if(estaAbierto()){
		throw "El restaurant ya esta abierto";
	}
	this->estado = Abierto;
}

void Restaurant::cerrarRestaurant(){
	if(!estaAbierto()){
		throw "El restaurant ya esta cerrado";
	}
	this->estado = Cerrado;
}

EstadoDeRestaurant Restaurant::getEstado(){
	return this->estado;
}

unsigned int Restaurant::getMaximoDeMesas(){
	return this->maximoDeMesas;
}

void Restaurant::verSiEstaCerrado(){
	if(!estaAbierto()){
		throw "El restaurant esta cerrado";
	}	
}

int Restaurant::ultimaPosicion(){
	int ultimaPos = this->getMaximoDeMesas();
	for(int i = this->getMaximoDeMesas(); i > 0; i--){
		if(this->mesas->obtener(i) == 0){
			ultimaPos--;
		}		
	}
	return ultimaPos;
}

void Restaurant::agregarUnaMesa(){
	verSiEstaCerrado();
	if(this->ultimaPosicion() == this->getMaximoDeMesas()){
		throw "Se alcanzo el maximo de mesas";
	}
	this->mesas->agregar(ultimaPosicion() + 1, new Mesa(ultimaPosicion() + 1));
	this->recordDeMesas =  ultimaPosicion();
}

void Restaurant::eliminarUnaMesa(){
	verSiEstaCerrado();
	if(this->ultimaPosicion() == 0){
		throw "No hay ninguna mesa incorporada";
	}
	this->mesas->obtener(ultimaPosicion()) = 0;
}

void Restaurant::agregarUnaSilla(unsigned int numeroMesa){
	verSiEstaCerrado();
	validarNumero(numeroMesa);
	this->mesas->obtener(numeroMesa)->agregarSilla();
}

void Restaurant::eliminarUnaSilla(unsigned int numeroMesa){
	verSiEstaCerrado();
	validarNumero(numeroMesa);
	this->mesas->obtener(numeroMesa)->eliminarSilla();
}

void Restaurant::ocuparMesa(unsigned int numeroMesa){
	verSiEstaCerrado();
	validarNumero(numeroMesa);
	this->mesas->obtener(numeroMesa)->ocupar();
}

void Restaurant::liberarMesa(unsigned int numeroMesa){
	verSiEstaCerrado();
	validarNumero(numeroMesa);
	this->mesas->obtener(numeroMesa)->liberar();
}

void Restaurant::inhabilitarMesa(unsigned int numeroMesa){
	verSiEstaCerrado();
	validarNumero(numeroMesa);	
	this->mesas->obtener(numeroMesa)->indisponibilizar();	
}

void Restaurant::validarNumero(unsigned int numeroMesa){
	if(!((numeroMesa > 0) && (numeroMesa <= this->getMaximoDeMesas()))){
		throw "El numero de mesa no existe";
	}
	
	if(this->mesas->obtener(numeroMesa) == 0){
		throw "La mesa no fue incorporada";
	}
}

int Restaurant::verSillasEnMesa(unsigned int numeroMesa){
	verSiEstaCerrado();
	validarNumero(numeroMesa);
	return this->mesas->obtener(numeroMesa)->getCantidadDeSillas();
}

unsigned int Restaurant::getRecordDeMesas(){
	actualizarRecord();
	return this->recordDeMesas;
}

void Restaurant::actualizarRecord(){
	if(this->ultimaPosicion() > this->recordDeMesas){
		this->recordDeMesas = this->ultimaPosicion();
	}
}

int Restaurant::verRecordDeSillasEnMesa(unsigned int numeroMesa){
	verSiEstaCerrado();
	validarNumero(numeroMesa);
	return this->mesas->obtener(numeroMesa)->getRecordDeSillas();
}

int Restaurant::getMesasActuales(){
	return this->ultimaPosicion();
}
