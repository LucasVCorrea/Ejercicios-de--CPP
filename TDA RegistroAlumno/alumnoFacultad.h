#ifndef ALUMNOFACULTAD_H
#define ALUMNOFACULTAD_H
#include <string>
class alumnoFacultad
{
	private:
		std::string nombre;
		std::string apellido;
		std::string nacionalidad;
		unsigned int padron;
		unsigned int fechaNacimiento;
		unsigned int numeroDocumento;
		
	public:
		// Pre: el texto debe tener entre 1 y 250 caracteres.
		// Post: recibe el apellido del alumno.
		alumnoFacultad(std::string);
		
		// Pre: el texto debe tener entre 1 y 250 caracteres.
		// Post: recibe el nombre del alumno.
		void setNombre(std::string);
		
		// Pre: el texto debe tener entre 1 y 50 caracteres
		// Post: recibe la nacionalidad del alumno.
		void setNacionalidad(std::string);
		
		// Pre: el padron debe ser mayor o igual a 1.
		// Post: recibe el padron del alumno.
		void setPadron(unsigned int);
		
		// Pre: la fecha no puede quedar vacia.
		// Post: recibe la fecha nacimiento del alumno.
		void setFechaNacimiento(unsigned int);
		
		// Pre: el numero de documento debe ser mayor o igual a 1.
		// Post: recibe el numero de documento
		void setNumeroDocumento(unsigned int);
		
		
		// Pre: ...
		// Post: devuelve el nombre del alumno
		std::string obtenerNombre();
		
		// Pre: ...
		// Post: devuelve el apellido del alumno
		std::string obtenerApellido();
		
		// Pre:
		// Post:
		std::string obtenerNacionalidad();
		
		// Pre:
		// Post:
		unsigned int obtenerPadron();
		
		// Pre:
		// Post:
		unsigned int obtenerFechaNacimiento();
		
		// Pre:
		// Post:
		unsigned int obtenerNumeroDocumento();
		
		
};

#endif
