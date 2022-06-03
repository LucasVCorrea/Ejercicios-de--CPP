#include "Mesa.h"

Mesa::Mesa(unsigned int numero){
	
	validarNumeroMesa(numero);
	this->numero = numero;
	this->totalDeMesa = 0;
	this->estado = Libre;
}

Mesa::~Mesa(){
	
}
void Mesa::abrir(){
	this->estado = Abierta;	
}

void Mesa::liberar(){
	this->estado = Libre;
}
void Mesa::agregarMonto(int monto){
	this->totalDeMesa += monto;
}

estadoDeMesa Mesa::getEstado(){
	return this->estado;
}

unsigned int Mesa::getNumero(){
	return this->numero;
}

int Mesa::getTotal(){
	return this->totalDeMesa;
}
