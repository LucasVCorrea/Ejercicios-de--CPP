#ifndef EXAM_H
#define EXAM_H
#include <string>
class Exam
{
	private:
		double nota;
		double notaCambiada;
		double notaFinal;
		std::string apellidoAlumno;
		
	public:
		Exam(std::string);
		~Exam();
		
		/* 
			Pre: ingresa una nota entre 1 y 10, sino queda anulada (0).
			Post: se coloca la nota
		*/
		void setNota(double);
		/* 
			Pre: la nota cambiada debe ser mayor a la nota original.
			Post: se cambia la nota
		*/
		void setNotaModificada(double);
	
		double getNota();
		double getNotaModificada();
		std::string getApellido();
};

#endif
