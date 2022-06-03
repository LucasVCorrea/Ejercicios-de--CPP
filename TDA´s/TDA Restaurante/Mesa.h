#ifndef MESA_H
#define MESA_H

enum estadoDeMesa{
	Abierta, Libre
};

class Mesa
{
	private:
		
		unsigned int numero;
		int totalDeMesa;
		estadoDeMesa estado;
		void validarNumeroMesa(unsigned int numero){
			if(numero < 1){
				throw "la mesa debe ser mayor o igual a 1";
			}
		}
		
	public:
		
		/*
			pre: el numero de mesa debe ser mayor o igual a 1
			pos: se instancia la mesa con su numero
		*/
		Mesa(unsigned int numero);
		
		/*
			pre: - 
			pos: se destruye la mesa
		*/
		virtual ~Mesa();
		
		/*
			pre: - 
			pos: devuelve el numero de la mesa
		*/
		unsigned int getNumero();
		
		/*
			pre: - 
			pos: devuelve el monto total de la mesa
		*/
		int getTotal();
		
		/*
			pre: -
			pos: devuelve el estado de la mesa
		*/
		estadoDeMesa getEstado();
		
		/*
			pre: - 
			pos: le suma el monto indicado a la mesa
		*/
		void agregarMonto(int monto);
		
		/*
			pre: la mesa debe estar abierta
			pos: libera la mesa
		*/
		void liberar();
		
		/*
			pre: - 
			pos: abre la mesa
		*/
		void abrir();
};

#endif
