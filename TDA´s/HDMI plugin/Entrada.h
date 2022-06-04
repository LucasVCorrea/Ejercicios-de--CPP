#ifndef ENTRADA_H
#define ENTRADA_H

enum estadoDeEntrada{
	Activada, Desactivada
};

class Entrada
{
	private:
		unsigned int numero;
		unsigned int cantidadDeUsos;
		estadoDeEntrada estado;
		
	public:
		/*
			pre: el numero debe ser mayor o igual 1 
			pos: instancia la entrada
		*/
		Entrada(unsigned int numero);
		
		/*
			pre: -
			pos: libera memoria
		*/
		virtual ~Entrada();
		
		/*
			pre: -
			pos: activa la entrada
		*/
		void activar();
		
		/*
			pre: -
			pos: desactiva la entrada
		*/
		void desactivar();
		
		/*
			pre: -
			pos: selecciona la entrada
		*/
		void seleccionar();
		
		/*
			pre: -
			pos: devuelve el numero de la entrada
		*/
		unsigned int getNumero();
		
		/*
			pre: -
			pos: devuelve la cantidad de usos de la entrada
		*/
		unsigned int getCantidadDeUsos();
				
		/*
			pre: -
			pos: devuelve el estado de la entrada
		*/
		estadoDeEntrada getEstado();
};

#endif
