#ifndef ASCENSOR_H
#define ASCENSOR_H
#include "Vector.h"
#include "Piso.h"

class Ascensor
{
	private:
		unsigned int cantidadPisos;
		unsigned int pisoActual;
		unsigned int subidas;
		unsigned int bajadas;
		
		Vector<Piso *> *pisos;
		
	public:
		
		/*
			pre: la cantidad de pisos debe ser mayor o igual a 1
			pos: se instancia el ascensor con la cantidad de pisos indicada
		*/
		Ascensor(unsigned int cantidadPisos);
		
		/*
			pre:
			pos: se libera memoria
		*/
		virtual ~Ascensor();
		
		/*
			pre: - 
			pos: devuelve la cantidad de pisos que recorre el ascensor
		*/
		unsigned int getCantidadPisos();
		
		/*
			pre: - 
			pos: devuelve el piso en el que se encuentra el ascensor
		*/
		unsigned int getPisoActual();
		
		/*
			pre: el piso debe estar en el recorrido
			pos: se mueve el ascensor hacia ese piso y devuelve la cantidad de pisos desplazados
		*/
		unsigned int llamarAscensor(unsigned int piso);
		
		/*
			pre: el piso debe estar en el recorrido
			pos: devuelve la cantidad de veces que se fue a ese piso
		*/
		unsigned int verHistorico(unsigned int piso);
		
		/*
			pre: -
			pos: devuelve la cantidad de veces que subio
		*/
		unsigned int pisosSubidos();
		
		/*
			pre: -
			pos: devuelve la cantidad de veces que bajo
		*/
		unsigned int pisosBajados();
	
	private:
		bool esValido(unsigned int piso);
		void validarPiso(unsigned int piso);
		unsigned int recorrido(unsigned int piso);
};

#endif
