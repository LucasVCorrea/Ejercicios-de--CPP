#include <iostream>
#include "validarContrasenia.h"

using namespace std;

int main() {
	
	ValidarContrasenia *miPassword = new ValidarContrasenia;
	
	miPassword->setContrasenia("algoritmos");
	
	try{
		miPassword->verSiEsValida();
		
	}catch(char const* x){
		cout<<"ERROR: "<< x <<endl;
		
	}
	
	delete miPassword;
	return 0;
}
