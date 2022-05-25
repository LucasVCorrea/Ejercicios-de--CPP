#ifndef RANURA_H
#define RANURA_H

enum estadoDeRanura{
	Libre, Ocupada
};

class Ranura
{
	private:
		unsigned int numero,cantidadDeUsos;
		estadoDeRanura estado;
	public:
		/*
			pre: el numero de ranura debe ser mayor o igual a 1 y menor a la cantidad de ranuras
			pos: crea la ranura
		*/
		Ranura(int numero);
		
		/*
			pre: - 
			pos: destruye la ranura
		*/
		virtual ~Ranura();
		
		/*
			pre: -
			pos: deja la ranura libre
		*/
		void liberar();
		
		/*
			pre: la ranura debe estar libre
			pos: deja la ranura ocupada
		*/
		void ocupar();
		
		/*
			pre: -
			post: devuelve la cantidad de usos de una ranura
		*/
		unsigned int getCantidadDeUsos();
		
		/*
			pre: 
			pos: devuelve el numero de ranura
		*/
		unsigned int getNumero();
		
		/*
			pre: -
			pos: devuelve el estado actual de la ranura
		*/
		estadoDeRanura getEstado();
};		

#endif

