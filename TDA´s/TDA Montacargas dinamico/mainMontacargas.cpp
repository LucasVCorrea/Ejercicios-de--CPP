#include <iostream>
#include "Montacargas.h"

using namespace std;

int main(){
	Montacargas *clark = new Montacargas(50);
	clark->cargar(20);
	clark->cargar(20);
	clark->cargar(10);	
	clark->descargar();

	cout<<" Cargando "<<clark->obtenerPesoActual()<<" kg"<<endl;
	cout<<" Soporta "<<clark->obtenerPesoResante()<<" kg mas"<<endl;
	cout<<" ahora tiene "<<clark->obtenerCargasAcumuladas()<<" cargas encima"<<endl;
	cout<<" se realizaron "<<clark->obtenerCargasRealizadas()<<" cargas totales"<<endl;

	delete clark;
	return 0;
}
