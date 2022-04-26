#include <iostream>
#include "MontaCargas.h"
using namespace std;

int main(){
	
	Montacargas Maquina(1000); //peso maximo que soporta el montacargas
	
	Maquina.cargar(10);
	Maquina.descargar();
	Maquina.cargar(100);
	Maquina.descargar();

	if (Maquina.obtenerCarga()<=1000){

	cout<<" El montacargas esta cargado con "<<Maquina.obtenerCarga()<<" kg "
	<<"(Soporta "<<Maquina.obtenerPesoRestanteLibre()<<" kg mas)"<<endl;
	
	cout<<" El montacargas realizo "<<Maquina.obtenerCantidadDeCargas()<<" cargas hasta ahora"<<endl
	<<" Se cargaron "<<Maquina.obtenerPesoTotal()<<" kg totales"<<endl;
	cout<<" La carga promedio es de "<<Maquina.obtenerCargaPromedio()<<" kg"<<endl;
	}
	
	else{
		cout<<"El montacargas se rompio por exceso de peso.";
	}
	return 0;
}
