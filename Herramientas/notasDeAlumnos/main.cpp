#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
	
	int cantidadAlumnos;
	string fecha;
	ofstream archivo("NotasAlumnos.txt", std::fstream::app);
	cout<<"Ingrese fecha del examen (DD/MM/AA): ";cin>>fecha;
	archivo<<"|Fecha: "<<fecha<<" |"<<endl;
	cout<<"Ingrese la cantidad de alumnos: ";cin>>cantidadAlumnos;
	
	string* arrClave = new string[cantidadAlumnos];
	double* arrNotas = new double[cantidadAlumnos];
	
	for(int i = 0; i < cantidadAlumnos; i++){	
		
		if (i == cantidadAlumnos - 1){
			cout<<"ultimo alumno "<<endl;
		}
		
		cout<<"Ingrese el apellido del alumno "<< i + 1 <<": ";cin>>arrClave[i];
		cout<<"Ingrese la nota de "<<arrClave[i]<<": ";cin>>arrNotas[i];
		archivo<<arrClave[i]<<" - "<<arrNotas[i]<<endl;
	}
	archivo<<endl;
	
	archivo.close();
	delete arrClave;
	delete arrNotas;
	return 0;
}
