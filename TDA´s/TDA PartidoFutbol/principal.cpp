#include <iostream>
#include "Marcador.h"

using namespace std;

int main(){
	
	try{
	
		Marcador *miPartido = new Marcador("Chelsea","PSG");
		cout<<miPartido->getEquipoLocal()<<" vs "<<miPartido->getEquipoVisitante()<<endl;
	
		miPartido->golEquipoLocal();
		miPartido->golEquipoLocal();
		miPartido->golEquipoVisitante();
		miPartido->golEquipoLocal();
		miPartido->golEquipoVisitante();
		
		cout<<" Marcador: "<<miPartido->getGolesLocal()<<" a "<<miPartido->getGolesVisita()<<endl;
		cout<<" Resultado: "<<miPartido->getEquipoGanador()<<endl;
		
		delete miPartido;
		
	}catch(char const*x){
		
		cout<<x<<endl;
		}
	

	return 0;
}
