#ifndef CANAL_H
#define CANAL_H

class Canal
{
	private:
		unsigned int numero,canalActual;
		int cantidadDeVistas;
		
	public:
		
		/*
			pre: el numero debe ser mayor o igual a 1
			pos: crea el canal
		*/
		
		Canal(unsigned int numero);
		
		/*
			pre: - 
			pos: destruye el canal
		*/
		virtual~Canal();
		
		/*
			pre: -
			devuelve el numero del canal
		*/
		unsigned int getNumero();
		
		/*
			pre: -
			devuelve el canal acutal
		*/
		unsigned int getCanalActual();
		
		/*
			pre:
			pos: suma 1 a la cantidad de veces que fue visto el canal
		*/
		void agregarUnaVista();	
		
		/*
			pre: -
			pos: devuelve la cantidad de veces que fue visto el canal
		*/
		int getCantidadDeVistas();
		
};

#endif
