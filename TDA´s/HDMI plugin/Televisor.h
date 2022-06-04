#ifndef TELEVISOR_H
#define TELEVISOR_H
#include "Vector.h"
#include "Entrada.h"

const static int MinimoPermitido = 1;
const static int CanalTope = 140;

enum EstadoTelevisor{
	EnCable, FueraDeCable
};

class Televisor
{
	private:
		
		unsigned int cantidadEntradas;
		unsigned int canalActual;
		Entrada* entradaActual;
		EstadoTelevisor estadoTV;
		Vector<Entrada *> * entradas;
		
		
	public:
		
		/*
			pre: la cantidad de entradas debe ser mayor o igual a 1
			pos: instancia el televisor con la cantidad de entradas
		*/
		Televisor(unsigned int cantidadEntradas);
		
		/*
			pre: -
			pos: libera memoria
		*/
		virtual ~Televisor();
		
		/*
			pre: -
			pos: deja el cable activado
		*/
		void activarCable();
		
		/*
			pre: el cable debe estar activado
			pos: desactiva el cable
		*/
		void desactivarCable();
		
		/*
			pre: el numero de entrada debe estar en el televisor y debe haber sido activada previamente
			pos: selecciona la entrada en cuestion
		*/
		void seleccionarEntrada(unsigned int numero);
		
		/*
			pre: el numero de entrada debe estar en el televisor
			pos: activa la entrada
		*/
		void activarEntrada(unsigned int numero);
		
		/*
			pre: el numero de entrada debe estar en el televisor
			pos: desactiva la entrada
		*/
		void desactivadEntrada(unsigned int numero);
		
		/*
			pre: -
			pos: devuelve la cantidad de entradas que tiene el televisor
		*/
		unsigned int getCantidadEntradas();
		
		/*
			pre: -
			pos: devuelve la entrada mas utilizada
		*/
		unsigned int getMasUsada();
		
		/*
			pre: -
			pos: devuelve la entrada usada actualmente
		*/
		unsigned int getEntradaActual();
		
		/*
			pre: -
			pos: devuelve el canal actual
		*/
		unsigned int getCanalActual();
		
		/*
			pre: el canal debe ser mayor o igual a 1 y menor a 140
			pos: se cambia el canal al seleccionado
		*/
		void seleccionarCanal(unsigned int canal);
		
		/*
			pre: -
			pos: avanza un canal
		*/
		void avanzarCanal();
		
		/*
			pre: -
			pos: retrocede un canal
		*/
		void retrocederCanal();
		
		
	private:
		void validarEntrada(unsigned int numero);
		void validarCable();
		void validarCanal(unsigned int canal);
		bool fueActivada(unsigned int numero);
		bool estaEnCable();
		bool canalEnRango();
};

#endif
