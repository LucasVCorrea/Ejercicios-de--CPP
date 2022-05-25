#include <iostream>
#include "Televisor3.h"

using namespace std;

int main(){
	
	try{
		
	
	Televisor3 *televisorNoblex = new Televisor3(12,4);
	televisorNoblex->prenderTelevisor();
	
	televisorNoblex->agregarApp(1,"Youtube");
	televisorNoblex->agregarApp(2,"Facebook");
	televisorNoblex->agregarApp(3,"Instagram");
	televisorNoblex->agregarApp(4,"Twitter");
	

	televisorNoblex->abrirApp("Facebook");
	televisorNoblex->cerrarApp("Facebook");
	televisorNoblex->abrirApp("Facebook");
	televisorNoblex->cerrarApp("Facebook");
	televisorNoblex->abrirApp("Twitter");
	televisorNoblex->cerrarApp("Twitter");
	
	televisorNoblex->agregarCanal(1);
	televisorNoblex->agregarCanal(2);
	televisorNoblex->agregarCanal(3);
	
	televisorNoblex->cambiarDeCanal(2);
	televisorNoblex->subirUnCanal();
	televisorNoblex->bajarUnCanal();
	cout<<"Canal Actual: "<<televisorNoblex->getCanalActual()<<endl;

	cout<<"Aplicacion actual: "<<televisorNoblex->getAplicacionActual()<<endl<<endl;
	cout<<"La aplicacion mas usada es: "<<televisorNoblex->getAppMasUsada()<<endl;
	
	cout<<"El canal mas visto es el "<<televisorNoblex->getCanalMasVisto()<<endl;
	
	televisorNoblex->apagarTelevisor();
	
	delete televisorNoblex;
	
	}catch(const char* x){
		cout<< x <<endl;
	}
	return 0;
}
