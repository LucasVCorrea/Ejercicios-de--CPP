#ifndef TOSTADORA_H
#define TOSTADORA_H
#include "Vector.h"
#include "Ranura.h"

const static unsigned int NivelDeCalorMaximo = 10;

enum estadoDeTostadora{
	Apagada,Encendida
};

class Tostadora
{
	private:
		
		estadoDeTostadora estadoTostadora;
		unsigned int cantidadDeRanuras,nivelDeCalor;
		Ranura** ranuras;
		void validarNumeroDeRanura(int numeroDeRanura);
		
	public:
		
		/*
			pre: la cantidad de ranuras debe ser mayor o igual a 1 
			pos: se crea la tostadora con la cantidad de ranuras indicada
		*/
		Tostadora(int cantidadDeRanuras);
		
		/*
			pre: -
			pos: elimina la tostadora
		*/
		virtual ~Tostadora();
		
		estadoDeTostadora getEstado();
		
		
		/*
			pre: la ranura donde se inicia el tostado debe existir. mayor o igual a 1 y menor a la cantidad de ranuras que tiene la tostadora
			pos: se inicia el tostado en esa ranura
		*/
		void iniciarTostado(int numeroDeRanura);
		
		
		/*
			pre: - 
			pos: finaliza el tostado en la ranura indicada
		*/
		void finalizarTostado(int numeroDeRanura);
		
		
		/*
			pre: el nivel de calor tiene que estar entre 1 y 10
			pos: se cambia el nivel de calor
		*/
		void setNivelDeCalor(unsigned int nivelDeCalor);
		
		/*
			pre:-
			pos: enciende la tostadora
		*/
		void encender();
		
		/*
			pre:-
			post: apaga la tostadora
		*/		
		void apagar();
		
		/*
			pre: - 
			pos: devuelve cuantas ranuras hay disponibles para usar
		*/
		unsigned int getRanurasLibres();
		
		/*
			pre: - 
			pos: devuelve la cantidad de ranuras totales en la tostadora
		*/
		unsigned int getCantidadDeRanuras();
		
		/*
			pre: - 
			pos: devuelve cual fue la ranura mas utilizada
		*/
		unsigned int getRanuraMasUsada();
		
};

#endif

