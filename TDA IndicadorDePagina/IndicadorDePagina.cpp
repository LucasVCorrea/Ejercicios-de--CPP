#include "IndicadorDePagina.h"
#include <iostream>
#include <string>


IndicadorDePagina::IndicadorDePagina(std::string nombreDelLibro,int paginasTotales){
	
	this->paginaActual = 1;
	this->nombreDelLibro = nombreDelLibro;
	this->paginasTotales = paginasTotales;
}

IndicadorDePagina::~IndicadorDePagina(){
	std::cout<<" Se rompio el libro de "<<this->getNombreLibro()<<std::endl;
}

int IndicadorDePagina::getPaginasTotales(){
	return this->paginasTotales;
}

std::string IndicadorDePagina::getNombreLibro(){
	return this->nombreDelLibro;
}

void IndicadorDePagina::pasarDePagina(){
	this->paginaActual++;
}

void IndicadorDePagina::volverUnaPagina(){
	this->paginaActual--;
}

int IndicadorDePagina::getPaginaActual(){
	return this->paginaActual;
}

int IndicadorDePagina::getPaginasPorLeerRestantes(){
	return (this->getPaginasTotales() - this->getPaginaActual());
}
