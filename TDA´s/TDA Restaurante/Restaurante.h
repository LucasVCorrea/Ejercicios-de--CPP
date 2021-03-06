#ifndef RESTAURANTE_H
#define RESTAURANTE_H
#include "Mesa.h"
#include "Vector.h"

class Restaurante
{
	private:
		unsigned int cantidadDeMesas;
		
		void validarNumeroMesa(unsigned int numero);
		
		Vector<Mesa*> * mesas;

	public:
		
		/*
			pre: la cantidad de mesas debe ser mayor o igual a 1
			pos: se instancia el restaurante con la cantidad de mesas ingresadas
		*/
		Restaurante(unsigned int cantidadDeMesas);
		
		/*
			pre: - 
			pos: libera la memoria del restaurante y las mesas
		*/
		virtual ~Restaurante();
		
		/*
			pre: el numero de mesa debe ser mayor o igual a 1 y menor a la cantidad total
			pos: se adiciona el monto en la mesa indicada, dejandola abierta
		*/
		void adicionarEnMesa(int monto, unsigned int numeroMesa);
		
		/*
			pre: el numero de mesa debe ser mayor o igual a 1 y menor a la cantidad total
			pos: devuelve el total de la mesa indicada y la deja libre
		*/
		int cerrarMesa(unsigned int numeroMesa);
		
		/*
			pre: - 
			pos: devuelve la cantidad de mesas totales
		*/
		unsigned int getMesasTotales();
		
		/*
			pre: - 
			pos: devuelve la cantidad de mesas que se encuentran libres
		*/
		unsigned int getMesasLibres();
		
		/*
			pre: -
			pos: devuelve la suma del total de todas las mesas
		*/
		int getTotalRecaudado();
};

#endif

























