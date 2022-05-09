#include "Marcador.h"
#include <iostream>
using namespace std;

Marcador::Marcador(string equipoLocal, string equipoVisitante){
	
	this->equipoLocal = equipoLocal;
	this->equipoVisitante = equipoVisitante;
	this->golesLocal = 0;
	this->golesVisitante = 0;
	if (this->equipoLocal == this->equipoVisitante){
		throw "Un equipo no puede jugar contra si mismo.";
	}
}

Marcador::~Marcador(){
	cout<<endl<<"Fin del partido!";
}

string Marcador::getEquipoLocal(){
	return this->equipoLocal;
}

string Marcador::getEquipoVisitante(){
	return this->equipoVisitante;
}

void Marcador::golEquipoLocal(){
	this->golesLocal++;
}

void Marcador::golEquipoVisitante(){
	this->golesVisitante++;
}

int Marcador::getGolesLocal(){
	return this->golesLocal;
}

int Marcador::getGolesVisita(){
	return this->golesVisitante;
}

void Marcador::abandonaEquipoLocal(){
	throw "Gano el equipo visitante 3 a 0 por abandono";
}

void Marcador::abandonaEquipoVisitante(){
	throw "Gano el equipo local 3 a 0 por abandono";
}

string Marcador::getEquipoGanador(){
	if (this->getGolesLocal() > this->getGolesVisita()){
		this->equipoGanador = this->equipoLocal;
	}
	else
		if (this->getGolesLocal() < this->getGolesVisita()){
			this->equipoGanador = this->equipoVisitante;
		}
		else{
			this->equipoGanador = "empate";
		}
	return this->equipoGanador;
}





