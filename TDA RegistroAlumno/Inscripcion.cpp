#include <iostream>
#include "alumnoFacultad.h"

using namespace std;

int main(){

	alumnoFacultad *alumno1=new alumnoFacultad("Correa");	
	
	
	alumno1->setNombre("Lucas");
	alumno1->setNacionalidad("Argentina");
	alumno1->setFechaNacimiento(6112000);
	alumno1->setNumeroDocumento(42999578);
	alumno1->setPadron(108664);
	
	cout<<alumno1->obtenerApellido()<<' '<<alumno1->obtenerNombre()<<endl<<endl;
	cout<<"Nacionalidad: "<<alumno1->obtenerNacionalidad()<<endl;
	cout<<"Fecha de nacimiento: "<<alumno1->obtenerFechaNacimiento()<<endl;
	cout<<"DNI: "<<alumno1->obtenerNumeroDocumento()<<endl;
	cout<<"Padron: "<<alumno1->obtenerPadron()<<endl;
	
	delete alumno1;
	return 0;

		
}	
