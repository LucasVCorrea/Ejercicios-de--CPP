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
	
	//cout<<miPassword->getContrasenia()<<endl;;
	//cout<<"Resultado mayuscula (si tiene da 1, sino da 0): "<<miPassword->checkMayusc()<<endl;
	//cout<<"Resultado numero (si tiene da 1, sino da 0): "<<miPassword->checkNumero()<<endl;
	
	delete miPassword;
	return 0;
}
