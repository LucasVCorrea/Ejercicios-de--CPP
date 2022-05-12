#include <iostream>
#include "IndicadorDePagina.h"

using namespace std;

int main(){
	
	IndicadorDePagina *miLibro = new IndicadorDePagina("MoonKnight",150);
	cout<<"Paginas totales de "<<miLibro->getNombreLibro()<<" : "<<miLibro->getPaginasTotales()<<endl<<endl;


	miLibro->pasarDePagina();
	miLibro->pasarDePagina();
	miLibro->pasarDePagina();
	miLibro->volverUnaPagina();
	miLibro->pasarDePagina();
	miLibro->pasarDePagina();
	
	
	cout<<"El libro esta en la pagina "<<miLibro->getPaginaActual()<<endl<<endl;
	cout<<"Quedan "<<miLibro->getPaginasPorLeerRestantes()<<" paginas por leer"<<endl;
	delete miLibro;
	return 0;
}
