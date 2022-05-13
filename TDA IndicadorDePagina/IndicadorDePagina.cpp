#include "IndicadorDePagina.h"
#include <iostream>
#include <string>

IndicadorDePagina::IndicadorDePagina(std::string nombreDelLibro,int paginasTotales){
	
	this->paginaActual = 1;
	this->nombreDelLibro = nombreDelLibro;
	this->paginasTotales = paginasTotales;
}

IndicadorDePagina::~IndicadorDePagina(){

}

int IndicadorDePagina::getPaginasTotales(){
	return this->paginasTotales;
}

std::string IndicadorDePagina::getNombreLibro(){
	return this->nombreDelLibro;
}

void IndicadorDePagina::pasarDePagina(){
	if ((this->getPaginaActual()) >= (this->getPaginasTotales())){
		throw "no quedan mas paginas por recorrer.";
	}
	this->paginaActual++;
}

void IndicadorDePagina::volverUnaPagina(){
	if (this->getPaginaActual() <= 1){
		throw "no se puede volver mas paginas.";
	}
	this->paginaActual--;
}

int IndicadorDePagina::getPaginaActual(){
	return this->paginaActual;
}

int IndicadorDePagina::getPaginasPorLeerRestantes(){
	return (this->getPaginasTotales() - this->getPaginaActual());
}
