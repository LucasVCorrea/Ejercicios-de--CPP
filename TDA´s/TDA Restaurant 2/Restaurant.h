#ifndef RESTAURANT_H
#define RESTAURANT_H
#include "Vector.h"
#include "Mesa.h"

enum EstadoDeRestaurant{
	Abierto, Cerrado
};

class Restaurant
{
	private:
		unsigned int maximoDeMesas;
		unsigned int recordDeMesas;
		EstadoDeRestaurant estado;
		Vector <Mesa *> * mesas;
		
	public:
				
		/*
			pre: el maximo debe ser mayor o igual a 1 
			pos: instancia el restaurant con el maximo de mesas posible
		*/
		Restaurant(unsigned int maximoDeMesas);
				
		/*
			pre: - 
			pos: libera memoria
		*/
		virtual ~Restaurant();
				
		/*
			pre: el restaurant debe estar cerrado
			pos: abre el restaurant
		*/
		void abrirRestaurant();
				
		/*
			pre: debe haber lugar en el restaurant
			pos: agrega una mesa al restaurant
		*/
		void agregarUnaMesa();
				
		/*
			pre: debe haber al menos una mesa agregada 
			pos: elimina una mesa del restaurant
		*/
		void eliminarUnaMesa();
				
		/*
			pre: el restaurant debe estar abierto 
			pos: cierra el restaurant
		*/
		void cerrarRestaurant();		
		
		/*
			pre: la mesa debe haber sido incorporada y no debe estar ocupada o inhabilitada 
			pos: ocupa la mesa indicada
		*/
		void ocuparMesa(unsigned int numeroMesa);
				
		/*
			pre: la mesa debe haber sido incorporada y no debe estar libre
			pos: libera la mesa indicada
		*/
		void liberarMesa(unsigned int numeroMesa);
						
		/*
			pre: la mesa debe haber sido incorporada y no debe estar ocupada
			pos: inhabilita la mesa indicada
		*/
		void inhabilitarMesa(unsigned int numeroMesa);
						
		/*
			pre: la mesa debe haber sido incorporada
			pos: agrega una silla a la mesa indicada
		*/
		void agregarUnaSilla(unsigned int numeroMesa);
						
		/*
			pre: la mesa debe haber sido incorporada y tener al menos una silla
			pos: le quita una silla a la mesa indicada
		*/
		void eliminarUnaSilla(unsigned int numeroMesa);
						
		/*
			pre: la mesa debe haber sido incorporada 
			pos: devuelve la cantidad de sillas que tiene la mesa indicada
		*/
		int verSillasEnMesa(unsigned int numeroMesa);
						
		/*
			pre: la mesa debe haber sido incorporada
			pos: devuelve el maximo de sillas que tuvo la mesa indicada
		*/
		int verRecordDeSillasEnMesa(unsigned int numeroMesa);
						
		/*
			pre: -
			pos: devuelve la cantidad de mesas que tiene el restaurant
		*/
		int getMesasActuales();
								
		/*
			pre: -
			pos: devuelve el estado del restaurant
		*/
		EstadoDeRestaurant getEstado();
										
		/*
			pre: -
			pos: devuelve el maximo permitido de mesas que tiene el restaurant
		*/
		unsigned int getMaximoDeMesas();
										
		/*
			pre: -
			pos: devuelve el record de mesas que tuvo el restaurant
		*/
		unsigned int getRecordDeMesas();
	
	private: 
									
		/*
			pre: -
			pos: devuelve si el restaurant esta abierto
		*/
		bool estaAbierto();
										
		/*
			pre: -
			pos: lanza una excepcion si el restaurant esta cerrado
		*/
		void verSiEstaCerrado();
										
		/*
			pre: -
			pos: lanza una excepcion si el numero de mesa no existe o si no fue incorporado
		*/
		void validarNumero(unsigned int numeroMesa);
										
		/*
			pre: -
			pos: actualiza el record de mesas que tiene el restaurant
		*/
		void actualizarRecord();
										
		/*
			pre: -
			pos: establece la ultima posicion disponible para agregar una mesa
		*/
		int ultimaPosicion();
		
};

#endif
