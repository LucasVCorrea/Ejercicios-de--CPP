#include <iostream>
#include "IndicadorDePagina.h"

using namespace std;

int main(){
	
	IndicadorDePagina *miLibro = new IndicadorDePagina("MoonKnight",15);
	cout<<"Paginas totales de "<<miLibro->getNombreLibro()<<": "<<miLibro->getPaginasTotales()<<endl<<endl;
	try{
	
	miLibro->pasarDePagina();

	cout<<"El libro esta en la pagina "<<miLibro->getPaginaActual()<<endl<<endl;
	cout<<"Quedan "<<miLibro->getPaginasPorLeerRestantes()<<" paginas hacia el final"<<endl;
	
	}catch(const char*a){
		cout<<a<<endl;
	}

	delete miLibro;
	return 0;
}
