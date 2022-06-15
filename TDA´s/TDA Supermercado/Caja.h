#ifndef CAJA_H
#define CAJA_H

class Caja
{
	private:
		unsigned int numero;
		int personasEnFila;
	public:
		
		/*	
			pre: el numero de la caja debe ser mayor a 0
			pos: instancia la caja
		*/
		Caja(unsigned int numero);
				
		/*	
			pre: -
			pos: libera memoria
		*/
		virtual~Caja();
		unsigned int getNumero();
				
		/*	
			pre: -
			pos: devuelve la cantidad de personas que estan en la fila
		*/
		int getPersonasEnFila();
				
		/*	
			pre: -
			pos: agrega una persona a la fila
		*/
		void agregarPersona();
};

#endif
