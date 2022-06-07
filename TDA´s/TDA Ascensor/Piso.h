#ifndef PISO_H
#define PISO_H

class Piso
{
	private:
		unsigned int numero;
		unsigned int cantidadVisitas;
		
	public:
		
		/*
			pre: el piso debe ser mayor a 0
			pos: se instancia el piso
		*/
		Piso(unsigned int numero);
		
		/*
			pre: -
			pos: se libera memoria
		*/
		virtual ~Piso();
		
		/*
			pre: -
			pos: devuelve el numero del piso
		*/
		unsigned int getNumero();
		
		/*	
			pre: - 
			pos: devuelve la cantidad de veces que se fue al piso
		*/
		unsigned int getCantidadVisitas();
		
		/*
			pre: -
			pos: se suma una visita al piso
		*/
		void registrarVisita();
		
	
};

#endif
