#ifndef INDICADORDEPAGINA_H
#define INDICADORDEPAGINA_H
#include <string>

class IndicadorDePagina
{
	private:
		
		int paginasTotales,paginaActual,paginaAnterior,paginaSiguiente;
		std::string nombreDelLibro;
		
	public:
		
		/*
			pre: -
			pos: se crea el libro con su nombre y la cantidad de paginas totales
		*/
		
		IndicadorDePagina(std::string nombreDelLibro,int paginasTotales);
		virtual~IndicadorDePagina();
		
		/*
			pre: -
			pos: pasa una pagina
		*/
		void pasarDePagina();

		/*
			pre: -
			pos: vuelve una pagina			
		*/
		void volverUnaPagina();
		int getPaginaActual();	
		int getPaginasTotales();
		int getPaginasPorLeerRestantes();
		std::string getNombreLibro();
};

#endif
