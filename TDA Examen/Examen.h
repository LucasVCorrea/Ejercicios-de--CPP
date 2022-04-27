#include <iostream>

using namespace std;

class Examen {
	// Private section
	string alumno;
	double nota;
	double notaCambiada;
	public:
		// Public Declarations
		
		/*crea el examen recibiendo como parametro el nombre del alumno*/
		Examen(string);
		
		/* pre: Se coloca una nota entre 1 y 10
		   post: 
		*/
		void setNota(double);
		double getNota();
		
		/* pre: Se coloca una nota entre 1 y 10
		   post: Se realiza el cambio de nota si la nueva es mayor a la anterior
		*/
		
		void setRevision(double);
		double getRevision();
		string getNombre();
		
};

Examen :: Examen(string _alumno){
	alumno = _alumno;

}

string Examen::getNombre(){
	return alumno;
}
void Examen::setNota(double _nota){
	if ((_nota < 1) || (_nota>10)){
		nota = 0;
	}
	else{
		nota = _nota;
	}
	
	
	
}
double Examen::getNota(){
	return nota;
}
void Examen :: setRevision(double _notaCambiada){
	notaCambiada = _notaCambiada;
	if ((notaCambiada < nota)||(notaCambiada>10)){
		nota = nota;
	}
	else
		nota = notaCambiada;
}
double Examen :: getRevision(){
	return nota;
}
