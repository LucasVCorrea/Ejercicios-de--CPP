#ifndef SUPERMERCADO_H
#define SUPERMERCADO_H
#include "Vector.h"
#include "Caja.h"

class Supermercado
{
	private:
		
		unsigned int cajasTotales;
		
		Vector<Caja *> * cajas;
		
	public:
		
		/*
		*	pre: el numero de cajas totales debe ser mayor o igal a 1
		*	pos: instancia el supermercado con el maximo de cajas posibles
		*/
		Supermercado(unsigned int cajasTotales);
		
		/*
		*	pre: - 
		*	pos: libera memoria
		*/
		virtual ~Supermercado();
		
		/*
		*	pre: debe haber espacio para agregar una caja
		*	pos: agrega la caja y se toma como ultima
		*/
		void incorporarUnaCaja();
		
		/*
		*	pre: la caja debe haber sido agregada 
		*	pos: elimina la caja y queda libre el espacio
		*/
		void eliminarUnaCaja(unsigned int numero);
		
		/*
		*	pre: la caja debe existir
		*	pos: agrega una persona a la fila de la caja indicada
		*/
		void ponerPersonaEnCaja(unsigned int numeroCaja);
		
		/*
		*	pre: - 
		*	pos: devuelve el total de cajas incorporadas
		*/
		int getCajasIncorporadas();
		
		/*
		*	pre: - 
		*	pos: devuelve el maximo permitido de cajas agregadas
		*/
		int getCajasTotales();
		
		/*
		*	pre: - 
		*	pos: devuelve la caja con mas personas en la fila
		*/
		unsigned int getCajaConMasPersonas();
		
	private:
		int posicionLibre();	
		bool quedaLugar();
		void validarNumeroCaja(unsigned int numero);
};

#endif
