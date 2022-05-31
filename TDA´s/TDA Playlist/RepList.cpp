#include "RepList.h"

RepList::RepList(unsigned int cantidadDeCanciones){
	if (cantidadDeCanciones <= 0){
		throw "La playlist debe tener minimo 1 cancion";
	}
	this->cantidadDeCanciones = cantidadDeCanciones;
	this->songs = new Song*[this->cantidadDeCanciones];
	
	for(int i =1; i<= this->cantidadDeCanciones; i++){
		this->songs[i] = NULL;
	}
}

RepList::~RepList(){
	for(int i =1; i<= this->cantidadDeCanciones; i++){
		delete this->songs[i];
	}
	delete []this->songs;
}


unsigned int RepList::getCantidadDeCanciones(){
	return this->cantidadDeCanciones;
}

unsigned int RepList::establecerPosicion(){
	unsigned int posicionesNulas = this->getCantidadDeCanciones();
	for(int i =1; i<= this->cantidadDeCanciones; i++){
		if(this->songs[i] != NULL){
			posicionesNulas--;
		}
	}
	return posicionesNulas;
}

void RepList::addSong(std::string nombreCancion){
	
	if(this->establecerPosicion() == 0){
		throw "La playlist esta llena";
	}
	verQueNoHayaSidoAgregada(nombreCancion);
		
	
	this->songs[this->establecerPosicion()] = new Song(nombreCancion);
	
}


void RepList::verQueHayaAlgo(unsigned int posicion){
	if((this->songs[posicion] == NULL) || (posicion > this->getCantidadDeCanciones())){
		throw "No hay ninguna cancion en esa posicion";
	}
}

std::string RepList::getCancion(unsigned int posicion){
	verQueHayaAlgo(posicion);
	return this->songs[posicion]->getNombre();
}


void RepList::reproducirCancion(unsigned int posicion){
	verQueHayaAlgo(posicion);
	this->songs[posicion]->sumarReproduccion();
	this->cancionActual = songs[posicion];
}

std::string RepList::getCancionActual(){
	return this->cancionActual->getNombre();
}

std::string RepList::getCancionMasEscuchada(){
	this->cancionMasEscuchada = this->songs[this->getCantidadDeCanciones()];
	for(int i =1; i<= this->cantidadDeCanciones; i++){
		if((this->songs[i]!=NULL) && (this->songs[i]->getCantidadDeReproducciones() > this->cancionMasEscuchada->getCantidadDeReproducciones())){
			this->cancionMasEscuchada = this->songs[i];
			
		}	
	}
	return this->cancionMasEscuchada->getNombre();
}

unsigned int RepList::getCuantasVecesSeEscucho(unsigned int posicion){
	return this->songs[posicion]->getCantidadDeReproducciones();
}

unsigned int RepList::reproduccionesDeLaMasEscuchada(){
	return this->cancionMasEscuchada->getCantidadDeReproducciones();
}

void RepList::replaceSong(unsigned int posicion,std::string nombreCancion){
	if(this->songs[posicion]!=NULL){
		this->songs[posicion] = new Song(nombreCancion);
	}
	else{
		throw "no hay una cancion para reemplazar";
	}
}

void RepList::verQueNoHayaSidoAgregada(std::string nombre){
	
	for(int i=1; i<=this->getCantidadDeCanciones();i++)	{
		if((this->songs[i]!=NULL) && (this->songs[i]->getNombre() == nombre)){
			throw "La cancion ya fue agregada";
		}
	}
	
}


















