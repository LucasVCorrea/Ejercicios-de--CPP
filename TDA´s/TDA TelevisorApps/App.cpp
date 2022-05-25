#include "App.h"

App::App(int numero,std::string nombreDeApp){
	if (numero < 0){
		throw "Debe haber almenos una aplicacion";
	}
	this->numero = numero;
	this->estado = Cerrada;
	this->nombreDeApp = nombreDeApp;
	this->cantidadDeUsos = 0;
}

App::~App(){
	
}

estadoDeApp App::getEstado(){
	return this->estado;
}

std::string App::getNombreDeApp(){
	return this->nombreDeApp;
}

int App::getNumeroDeApp(){
	return this->numero;
}

void App::abrir(){
	this->estado = Abierta;
	this->cantidadDeUsos++;
}

void App::cerrar(){
	this->estado = Cerrada;
}

int App::getCantidadDeUsos(){
	return this->cantidadDeUsos;
}
