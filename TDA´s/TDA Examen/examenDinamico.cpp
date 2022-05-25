#include "exam.h"

using namespace std;

Exam::Exam(string apellidoAlumno){
	this->apellidoAlumno = apellidoAlumno;
}

Exam::~Exam(){
	
}
	void Exam::setNota(double nota){
		
		if ((1>nota) || (nota > 10)){
			throw "La nota ingresada no es valida.";
			this->nota = 0;
		}
		this->nota = nota;
	}
	
	void Exam::setNotaModificada(double notaCambiada){
		this->notaCambiada = notaCambiada;
		if (this->notaCambiada < this->getNota()){
			throw "La nota no se puede cambiar por una mas chica.";
			this ->nota = 0;
		}
		this->nota = this->notaCambiada;
	}
	
	
	double Exam::getNota(){
		return this->nota;
	}
	
	string Exam::getApellido(){
		return this->apellidoAlumno;
	}
	
	double Exam::getNotaModificada(){
		return this->notaCambiada;
	}
