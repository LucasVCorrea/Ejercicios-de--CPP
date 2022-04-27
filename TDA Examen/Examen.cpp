#include <iostream>
#include "TDA Examen.h"

using namespace std;

int main(){
	Examen Alumno1("Correa");
	Alumno1.setNota(6);
	Alumno1.setRevision(8.75);
	
	Examen Alumno2("Perez");
	Alumno2.setNota(9);
	Alumno2.setRevision(6);
	
	cout<<Alumno1.getNombre()<<' '<<Alumno1.getNota()<<' '<<endl;
	cout<<Alumno2.getNombre()<<' '<<Alumno2.getNota()<<' '<<endl;
	return 0;
}
