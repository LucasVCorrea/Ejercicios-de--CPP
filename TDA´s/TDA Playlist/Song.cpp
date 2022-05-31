#include "Song.h"

Song::Song(std::string nombreDeLaCancion){
	if (nombreDeLaCancion == " "){
		throw "nombre invalido";
	}
	this->nombreDeLaCancion = nombreDeLaCancion;
	this->cantidadDeReproducciones = 0;
}

Song::~Song(){
	
}

unsigned int Song::getCantidadDeReproducciones(){
	return this->cantidadDeReproducciones;
}

std::string Song::getNombre(){
	return this->nombreDeLaCancion;
}

void Song::sumarReproduccion(){
	this->cantidadDeReproducciones++;
}
