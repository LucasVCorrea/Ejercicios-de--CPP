#include "clark.h"

Clark :: Clark(double pesoMaximoDeCarga){
		if (pesoMaximoDeCarga<0){
			pesoMaximoDeCarga = 0;
			
		}
		this->pesoMaximoDeCarga = pesoMaximoDeCarga;
		this->pesoActualDeCarga = 0;
		this->totalHistoricoCargado = 0;
		this->cantidadDeDescargasRealizadas = 0;
		
	}
	double Clark :: obtenerPesoMaximo(){
		return this-> pesoMaximoDeCarga;
	}
	
	Clark :: ~Clark(){
		//cout<<endl<<endl<<endl<<" El objeto se destruyo correctamente."<<endl;
	}
	double Clark::obtenerPesoActual(){
		return this -> pesoActualDeCarga;
	}
	double Clark :: obtenerCarga(){
		return this->pesoActualDeCarga;
	}
	
	double Clark :: cargar(double pesoDeCarga){
		if (pesoDeCarga < 0){
			throw "El peso de la carga es menor a 0.";
		}
		if ((this->obtenerCarga()+pesoDeCarga)>this->obtenerPesoMaximo()){
			throw "El peso acumulado a superado el maximo permitido";
		}
		
		this->pesoActualDeCarga += pesoDeCarga;	
		return this->obtenerPesoRestanteLibre();
	}
		
	double Clark :: obtenerPesoRestanteLibre(){
		//double pesoLibre = pesoMaximo - pesoActual;
		return (this->obtenerPesoMaximo() - this->obtenerPesoActual());
	}
	
	bool Clark :: estaVacio(){
		return (obtenerCarga() == 0);
	}
	
	double Clark :: descargar(){
		 
		if (!this->estaVacio()){
			this->totalHistoricoCargado += this->pesoActualDeCarga;
			this->cantidadDeDescargasRealizadas++;
			this->pesoActualDeCarga=0;
		}
		
	}
	double Clark :: obtenerCantidadDeCargas(){
	
		return cantidadDeDescargasRealizadas;
	}
	
	double Clark :: obtenerPesoTotal(){
		
		return totalHistoricoCargado;
	}
	
	double Clark :: obtenerCargaPromedio(){
		if (this->obtenerCantidadDeCargas()==0){
			return 0;
		}
		return this->totalHistoricoCargado / this->cantidadDeDescargasRealizadas;
	
	}
