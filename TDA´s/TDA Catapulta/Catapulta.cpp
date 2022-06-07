#include "Catapulta.h"

Catapulta::Catapulta(double contrapeso){
	
	if(pesoMaximo < 0){
		throw "El peso maximo debe ser mayor o igual a 1";
	}
	
	this->contrapeso = contrapeso;
	this->pesoMaximo = this->contrapeso * 10;
	this->pesoDisponible = this->pesoMaximo;
	this->proyectilesLanzados = 0;
	this->proyectilesCargados = 0;
	this->distanciaMaxima = 0;
}


Catapulta::~Catapulta(){
	
}


bool Catapulta::proyectilValido(double pesoProyectil){
	return (( pesoProyectil > 0) && (pesoProyectil <= this->getPesoMaximo()));
}


bool Catapulta::soportaMasPeso(){
	return ((this->getPesoDisponible() >= 0 )&& (this->getPesoDisponible() <= this->getPesoMaximo()));
}


void Catapulta::cargar(double pesoProyectil){
	if(!proyectilValido(pesoProyectil)){
		throw "El peso ingresado no es valido";
	}
	
	this->pesoDisponible -= pesoProyectil;
	this->proyectilesCargados++;
	
	if(!soportaMasPeso()){
		throw "se supero la carga maxima";
	}
}


void Catapulta::descargar(){
	
	if(this->getProyectilesCargados() == 0){
		throw "la catapulta esta descargada";
	}

	this->proyectilesCargados = 0;
	this-> pesoDisponible = this->getPesoMaximo();
}


unsigned int Catapulta::disparar(){
	unsigned int ultimaDistancia = pow(( 10 * this->getContrapeso() - (this->getPesoMaximo() - this->getPesoDisponible()) ),2);
	actualizarMaximo(ultimaDistancia);
	this->proyectilesLanzados += this->getProyectilesCargados();
	descargar();
	return ultimaDistancia;	
}


void Catapulta::actualizarMaximo(unsigned int distancia){
	if(distancia > this->distanciaMaxima){
		this->distanciaMaxima = distancia;
	}
}


unsigned int Catapulta::getDistanciaMaxima(){

	return this->distanciaMaxima;
}


double Catapulta::getContrapeso(){
	return this->contrapeso;
}


double Catapulta::getPesoDisponible(){
	return this->pesoDisponible;
}


double Catapulta::getPesoMaximo(){
	return this->pesoMaximo;
}


unsigned int Catapulta::getProyectilesCargados(){
	return this->proyectilesCargados;
}


unsigned int Catapulta::getProyectilesLanzados(){
	return this->proyectilesLanzados;
}
