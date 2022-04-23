#include <iostream>

using namespace std; 

class Persona {
	// Private section - atributes
	int edad;
	string nombre;
	string nacionalidad;
	public: // Public Declarations - methods
		Persona (int, string, string); // Constructor
		void leer();
		void correr();
		void identificarse();

};
Persona :: Persona(int _edad,string _nombre,string _nacionalidad){
	 edad = _edad;
	 nombre = _nombre;
	 nacionalidad = _nacionalidad;
}

void Persona :: leer(){
	cout<<"Soy "<<nombre<<" y estoy leyendo un libro"<<endl;
}
void Persona :: correr(){
	cout<<"Soy "<<nombre<<" y estoy corriendo una maraton"<<endl;
}
void Persona :: identificarse(){
	cout<<"Mi nombre es  "<<nombre<<" tengo "<<edad<<" años "<<"y soy de "<<nacionalidad<<endl;
}
