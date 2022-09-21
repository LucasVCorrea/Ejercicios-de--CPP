#ifndef AHORCADO_H
#define AHORCADO_H
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

class Ahorcado{
	
	private:
		string* listaMarvel;
		string* listaCantantes;
		string* listaPersonajes;
	
		char letra;
		char opcion;
		char temaElegido;
		
		int vidas;
		int letrasEncontradas;
		int intentos;
		int randomNumber;
		
		string palabra; 
		string palabraAux;
		string palabraArriesgada;
		
		void parteUno();
		void ciclar();
		void final();
		void reset();	
		void limpiarPalabra(){
			for(int i = 0; i < this->palabra.size(); i++){
				this->palabraAux[i] = '_';	
				cout<<palabraAux[i]<<' ';
			}
		}
		
		int generaRandomNumber();
		void mostrarTemas();
		void elegirTema();
		
	public:
		Ahorcado();
		virtual ~Ahorcado();
		void Jugar();
		void imprimeMonigote(int vidas){
			switch(vidas){
				case 6:
					cout<<endl<<" ___"<<endl<<"|   |"<<endl<<"|"<<endl<<"|"<<endl<<"|"<<endl;
					break;
				case 5:
					cout<<endl<<" ___"<<endl<<"|   |"<<endl<<"|   O"<<endl<<"|"<<endl<<"|"<<endl;
					break;
				case 4:
					cout<<endl<<" ___"<<endl<<"|   |"<<endl<<"|   O"<<endl<<"|   |"<<endl<<"|"<<endl;
					break;
				case 3:
					cout<<endl<<" ___"<<endl<<"|   |"<<endl<<"|   O"<<endl<<"|  /| "<<endl<<"|"<<endl;
					break;
				case 2:
					cout<<endl<<" ___"<<endl<<"|   |"<<endl<<"|   O"<<endl<<"|  /|\\ "<<endl<<"|"<<endl;
					break;
				case 1:
					cout<<endl<<" ___"<<endl<<"|   |"<<endl<<"|   O"<<endl<<"|  /|\\ "<<endl<<"|  /"<<endl;
					break;
				case 0:
					cout<<endl<<" ___"<<endl<<"|   |"<<endl<<"|   O"<<endl<<"|  /|\\ "<<endl<<"|  / \\"<<endl;
			}
		};

};

#endif
