#ifndef AHORCADO_H
#define AHORCADO_H
#include <cstdlib>
#include <iostream>

using namespace std;

class Ahorcado
{
	private:
		std::string* listaPalabras;
		char letra;
		int contador ;
		int suma ;
		int intentos;
		int valor ;
		std::string palabra ; 
		std::string palabraAux ;
		void parteUno();
		void ciclar();
		void final();
		
	public:
		Ahorcado();

		void Jugar();
		
			
};

#endif
