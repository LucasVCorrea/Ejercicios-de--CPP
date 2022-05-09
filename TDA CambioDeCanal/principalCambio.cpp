#include <iostream>
#include "IndicadorDeCanales.h"
using namespace std;

int main(){
	
	IndicadorDeCanales *miCanal = new IndicadorDeCanales;	
	
	try{
		
		miCanal->cambiarCanal(296);
		cout<<"Se ingreso por primera vez el canal: "<<miCanal->getCanalActual()<<endl;
		
		miCanal->subirOBajarCanal('-');
		miCanal->subirOBajarCanal('+');
		miCanal->subirOBajarCanal('+');
		miCanal->subirOBajarCanal('+');
		miCanal->subirOBajarCanal('+');
		miCanal->subirOBajarCanal('-');
		miCanal->subirOBajarCanal('-');
		miCanal->cambiarCanal(15);
		miCanal->subirOBajarCanal('+');
		miCanal->subirOBajarCanal('+');
		miCanal->subirOBajarCanal('-');

		cout<<"Canal actual: "<<miCanal->getCanalActual();
		
	}catch(char const*x){
		
		cout<<"ERROR: "<<x<<endl;
		
	}
	
	delete miCanal;
	return 0;
}
