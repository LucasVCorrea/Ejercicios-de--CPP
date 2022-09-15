#ifndef AHORCADO_H
#define AHORCADO_H
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

class Ahorcado
{
	private:
		string* listaPalabras;
		string* listaCantantes;
		
		char letra;
		char opcion;
		char temaElegido;
		
		int vidas;
		int letrasEncontradas ;
		int intentos;
		int randomNumber;
		
		string palabra; 
		string palabraAux;
		string palabraArriesgada;
		
		void elegirTema();
		void parteUno();
		void ciclar();
		void final();
		void reset();
		
		
	public:
		Ahorcado();
		virtual ~Ahorcado();
		void Jugar();
		int generaRandomNumber();
		void mostrarTemas();
		
		
			
};

#endif
