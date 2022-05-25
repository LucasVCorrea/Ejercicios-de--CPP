#ifndef TELEVISOR_H
#define TELEVISOR_H
#include "Entrada.h"

enum estadoDelTelevisor{
	Prendido, Apagado
};

const static unsigned int UltimoCanal = 140;

class Televisor
{
	private:
		unsigned int cantidadDeEntradas,canalActual;
		Entrada** entradas;
		void validarEntrada(unsigned int numeroDeEntrada);
		void validarEstado();
		void validarCanales(unsigned int canalActual);
		estadoDelTelevisor estado;
	
	public:
		
		/*
			pre: la cantidad de entradas debe ser mayor o igual a 1
			pos: crea el televisor con la cantidad de entradas HDMI
		*/
		Televisor(unsigned int cantidadDeEntradas);
		
		/*
			pre: -
			pos: destruye el televisor
		*/
		virtual ~Televisor();
		
		/*
			pre: - 
			pos: enciende el televisor
		*/
		void prenderTelevisor();
		
		/*
			pre: -
			pos: apaga el televisor
		*/
		void apagarTelevisor();
		
		/*	
			pre: la entrada debe estar activada
			pos: selecciona la entrada
		*/
		void seleccionarEntrada();
		
		/*
			pre -
			pos: devuelve la cantidad de entradas
		*/
		unsigned int getCantidadDeEntradas();
		
		/*
			pre: la entrada debe ser mayor o igual a 1 y menor al maximo
			pos: activa la entrada
		*/
		void activarEntrada(unsigned int numeroDeEntrada);
		
		/*
			pre: la entrada debe estar activada
			pos: desactiva la entrada
		*/
		void desactivarEntrada(unsigned int numeroDeEntrada);
		
		/*
			pre: la entrada seleccionada debe estar activa
			pos: selecciona una entrada HDMI
		*/
		void seleccionarEntrada(unsigned int numeroDeEntrada);
		/*
			pre: -
			pos: devuelve el estado actual del televisor
		*/
		estadoDelTelevisor getEstado();
		
		/*
			pre: -
			pos: devuelve la entrada mas usada
		*/
		unsigned int getEntradaMasUsada();
		
		/*
			pre: el canal debe ser mayor o igual a 1 y menor al maximo
			pos: se cambia el canal actual
		*/
		void cambiarDeCanal(unsigned int canalActual);

		/*
			pre: - 
			pos: devuelve el canal actual
		*/
		unsigned int getCanalActual();
	
		/*
			pre: -
			pos: devuelve la cantidad de entradas seleccionadas
		*/
		unsigned int getEntradasSeleccionadas();
		
		/*
			pre:
			pos: avanza al canal siguiente
		*/
		void pasarAlSiguienteCanal();
		/*
			pre: -
			pos: retrocede al canal anterior
		*/
		void pasarAlAnteriorCanal();
};

#endif
