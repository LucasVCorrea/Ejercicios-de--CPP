#ifndef MESA_H
#define MESA_H

enum EstadoDeMesa{
	Libre, Ocupada, Indisponible
};

class Mesa
{
	private:
		unsigned int numeroDeMesa;
		int cantidadDeSillas;
		int recordDeSillas;
		EstadoDeMesa estado;
	public:
				
		/*
			pre: el numero debe ser mayor o igual a 1
			pos: instancia la mesa
		*/
		Mesa(unsigned int numeroDeMesa);
		
		/*
			pre: - 
			pos: libera memoria
		*/
		virtual ~Mesa();
		
		/*
			pre: -
			pos: devuelve la cantidad de sillas que tiene la mesa
		*/
		int getCantidadDeSillas();
		
		/*
			pre: - 
			pos: devuelve el maximo de sillas que tuvo la mesa
		*/
		int getRecordDeSillas();
		
		/*
			pre: - 
			pos: devuelve el estado de la mesa
		*/
		EstadoDeMesa getEstado();
		
		/*
			pre: la mesa debe estar libre y habilitada
			pos: ocupa la mesa
		*/
		void ocupar();
				
		/*
			pre: la mesa debe estar ocupada 
			pos: 
		*/
		void liberar();
				
		/*
			pre: la mesa debe estar libre
			pos: inhabilita la mesa
		*/
		void indisponibilizar();
				
		/*
			pre: -
			pos: agrega una silla a la mesa
		*/
		void agregarSilla();
				
		/*
			pre: - 
			pos: le quita una silla a la mesa
		*/
		void eliminarSilla();
	private:
		/*
			devuelve si la mesa esta ocupada
		*/
		bool estaOcupada();
		
		/*
			devuelve si la mesa esta inhabilitada	
		*/
		bool estaInhabilitada();
};

#endif
