#include <iostream>

using namespace std;

int main(){
	string nombre,apellido,correoElectronico;
	cout<<"Nombre: ";cin>>nombre;
	cout<<"Apellido: ";cin>>apellido;
	
	char letra = nombre[0];
	letra = tolower (letra);
	apellido[0]=tolower(apellido[0]);
	
	correoElectronico+=letra;
	correoElectronico+=apellido;
	correoElectronico+="@direccion_de_mail.com.xx";
	cout<<"Correo Electronico: "<<correoElectronico;
	return 0; 
}
