#include "clark.h"
#include <iostream>

using namespace std;

int main(){
	
		Clark *miClark = new Clark(5000);
		miClark->cargar(80);
		
		miClark->cargar(800);
	
		cout<<"El Clark esta cargado con: "<<miClark->obtenerPesoActual()<<" kg"<<endl; 
		if (miClark->obtenerPesoRestanteLibre()<(miClark->obtenerPesoMaximo()/2)){
			cout<<"El Clark esta a la mitad de su capacidad"<<endl;
		}
		else{
			cout<<"El Clark esta casi vacio"<<endl;
		}
		miClark->descargar();
		cout<<"El Clark fue descargado"<<endl;
		miClark->cargar(910);
		miClark->cargar(miClark->obtenerPesoRestanteLibre());
		miClark->descargar();
		cout<<"La carga promedio es: "<<miClark->obtenerCargaPromedio()<<" kg"<<endl;
		
    delete miClark;
	
		
	
	return 0;
}

