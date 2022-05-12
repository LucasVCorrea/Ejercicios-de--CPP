#ifndef INDICADORDEPAGINA_H
#define INDICADORDEPAGINA_H
#include <string>

class IndicadorDePagina
{
	private:
		
		int paginasTotales,paginaActual,paginaAnterior,paginaSiguiente;
		std::string nombreDelLibro;
		
	public:
		
		IndicadorDePagina(std::string nombreDelLibro,int paginasTotales);
		~IndicadorDePagina();
		void pasarDePagina();
		void volverUnaPagina();
		int getPaginaActual();	
		int getPaginasTotales();
		int getPaginasPorLeerRestantes();
		std::string getNombreLibro();
};

#endif
