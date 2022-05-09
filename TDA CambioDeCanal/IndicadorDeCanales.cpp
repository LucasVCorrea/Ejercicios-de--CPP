#include "IndicadorDeCanales.h"

using namespace std;

IndicadorDeCanales::IndicadorDeCanales(){
	this->canalMaximo = 299;
	this->canalMinimo = 1;
}
IndicadorDeCanales::~IndicadorDeCanales(){
	
}

	
	void IndicadorDeCanales::cambiarCanal(int nuevoCanal){
		this->nuevoCanal = nuevoCanal;
		if ((this->nuevoCanal > this->canalMaximo) || (this->nuevoCanal<this->canalMinimo)){
			throw "El canal seleccionado esta fuera de rango";
		}
		
		this->canalActual = this->nuevoCanal;
			
	}
	
	
	int IndicadorDeCanales::getCanalActual(){
		
		return this->canalActual;
	}
	
	
	void IndicadorDeCanales::subirOBajarCanal(char instruccion){
		this->instruccion = instruccion;
		if (this->instruccion == '+'){
			this->canalActual++;
		}
				
		else
			if (this->instruccion == '-'){
				this->canalActual--;
			}
			else{
				throw "Se ingreso una instruccion invalida";
			}
		if ((this->getCanalActual() > this->canalMaximo) || (this->getCanalActual() < this->canalMinimo)){
			throw "Se fue de rango al cambiar los canales";
		}
	}
		

