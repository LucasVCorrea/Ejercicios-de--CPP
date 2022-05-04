#include <iostream>
#include "Exam.h"

using namespace std;

int main() {
	
	Exam *alumnoUno = new Exam("Correa");
	
	try{
		
		alumnoUno-> setNota(8.5);
		cout<<"Al alumno "<<alumnoUno->getApellido()<<" se le puso un "<<alumnoUno->getNota()<<endl;
		
	}catch(char const*x){
		
		cout<<"ERROR: "<<x<<endl;
	}
	
	try{
		
		alumnoUno-> setNotaModificada(2);
		cout<<"Luego de revisar el examen se le cambio la nota por un "<<alumnoUno->getNotaModificada()<<endl;
		cout<<"Entonces su nota final es: "<<alumnoUno->getNota();
		
	}catch(char const*y){
	
		cout<<"ERROR: "<<y<<endl;
	}
	
	delete alumnoUno;
	return 0;
	
}
