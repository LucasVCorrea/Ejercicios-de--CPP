#include "validarContrasenia.h"
#include <iostream>

using namespace std;

ValidarContrasenia::ValidarContrasenia(){
	
}

ValidarContrasenia::~ValidarContrasenia(){
	
}

	void ValidarContrasenia::setContrasenia(string cadena){
		this->cadena = cadena;
		
	}

	string ValidarContrasenia::getContrasenia(){
		return this->cadena;
	}


	bool ValidarContrasenia::checkMayusc(){
		int i = 0,contadorDeMayusculas=0;
		
		while (this->getContrasenia()[i]!='\0'){
			
			if ((this->getContrasenia()[i] >= 'A') && (this->getContrasenia()[i]) <= 'Z'){
				contadorDeMayusculas++;
					
			}
		i++;
		}
		
		if (contadorDeMayusculas>0){
			this->tieneMayuscula = true;
		}
		
		else{
			this->tieneMayuscula = false;
			throw "La contraseña no tiene mayusculas.";
		}		
		return this->tieneMayuscula;
	}

	
	
	bool ValidarContrasenia::checkNumero(){
		int i = 0, contadorDeNumeros = 0;
		
		while (this->getContrasenia()[i]!='\0'){
			
			if((this->getContrasenia()[i] >= '0') && (this->getContrasenia()[i] <= '9')){
				contadorDeNumeros++;
				
			}
		i++;	
		}
		
		if (contadorDeNumeros > 0){
			this->tieneNumero = true;
		}
		else{
			this->tieneNumero = false;
			throw "La contraseña no tiene ningun caracter numerico.";	
		}
		return this->tieneNumero;
		
	}
		
	bool ValidarContrasenia::checkLongitud(){
		
		if (this->getContrasenia().size()<8){
			this->cumpleLongitud = false;
			throw "La contraseña no cumple con la longitud de 8 caracteres minimo.";
			
		}
			
		else{
			this->cumpleLongitud = true;
			
		}
		return this->cumpleLongitud;
	}
	
	bool  ValidarContrasenia::verSiEsValida(){
		if ((this->checkLongitud()) && (this->checkNumero()) && (this->checkMayusc())){
			this->esValida = true;
			cout<<"Su contraseña es valida."<<endl;
		}
		
		else{

			throw "Su contraseña no es valida.";
		}
	
	return this->esValida;
	}
