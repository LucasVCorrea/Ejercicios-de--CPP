#include "Montacargas.h"

Montacargas::Montacargas(double pesoMaximo){
	if(pesoMaximo <= 0.0){
		throw "El peso maximo debe ser mayor o igual a 1";
	}
	this->pesoMaximo = pesoMaximo;
	this->pesoActual = 0.0;
	this->cargasRealizadas = 0.0;
	this->cargasAcumuladas = 0.0;
}


Montacargas::~Montacargas(){
	
}


double Montacargas::obtenerPesoActual(){
	return this->pesoActual;
}


double Montacargas::obtenerPesoMaximo(){
	return this->pesoMaximo;
}


double Montacargas::obtenerPesoResante(){
	return (this->obtenerPesoMaximo() - this->obtenerPesoActual());
}


double Montacargas::obtenerCargasAcumuladas(){
	return this->cargasAcumuladas;
}


double Montacargas::obtenerCargasRealizadas(){
	return this->cargasRealizadas;
}


void Montacargas::cargar(double peso){
	validarPeso(peso);
	this->pesoActual += peso;
	this->cargasAcumuladas++;
	if(!soportaMasPeso()){
		throw "Se supero la carga maxima";
	}
}


void Montacargas::validarPeso(double peso){
	if((peso < 0.0) || (peso > this->obtenerPesoMaximo())){
		throw "El peso ingresado es invalido";
	}
}


bool Montacargas::soportaMasPeso(){
	return (this->obtenerPesoActual() <= this->obtenerPesoMaximo());
}


bool Montacargas::estaCargado(){
	return (this->obtenerPesoActual() != 0.0);
}


void Montacargas::descargar(){
	if(!estaCargado()){
		throw "No hay nada para descargar";
	}
	
	this->cargasRealizadas ++; 
	this->pesoActual = 0.0;
	this->cargasAcumuladas = 0.0;
}
	
	
	
	
