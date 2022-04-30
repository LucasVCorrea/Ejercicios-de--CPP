#include "alumnoFacultad.h"
#include <cstring>

using namespace std;

	alumnoFacultad::alumnoFacultad(string apellido){
			this ->apellido = apellido;
			
			if ((this->obtenerApellido().size() > 250) || (this->obtenerApellido().size() < 1)){
				apellido = "-";
				throw "El apellido debe tener entre 1 y 250 caracteres";
				
			}
					
	}
	
	void alumnoFacultad::setNombre(string nombre){
			this->nombre = nombre;
			
			if ((obtenerNombre().size() < 1) || (obtenerNombre().size() > 250)){
				nombre = "-";
				throw "El apellido debe tener entre 1 y 250 caracteres";
			
			}
					
	}
	
	void alumnoFacultad::setNacionalidad(string nacionalidad){
			this ->nacionalidad = nacionalidad;
			
			if ((obtenerNacionalidad().size() < 1) || (obtenerNacionalidad().size() > 50)){
				nacionalidad = "-";
				throw "La nacionalidad debe tener entre 1 y 50 caracteres";
			
			}
					
	}
	void alumnoFacultad::setFechaNacimiento(unsigned int fechaNacimiento){
			this->fechaNacimiento = fechaNacimiento;
			
			if(this->obtenerFechaNacimiento() == 0){
				fechaNacimiento = 0;
				throw "La fecha de nacimiento no puede quedar vacia";
			
			}
									
	}
	
	void alumnoFacultad::setNumeroDocumento(unsigned int numeroDocumento){
			this->numeroDocumento = numeroDocumento;
			if (this->obtenerNumeroDocumento() < 1){
				numeroDocumento = 0;
				throw "El numero de documento debe ser mayor o igual a 1";
			
			}
						
	}
	
	void alumnoFacultad::setPadron(unsigned int padron){
			this->padron = padron;
			if ((this->obtenerPadron() < 1) || (this->obtenerPadron() > 9999999)){
				padron = 0;
				throw "El padron debe ser mayor a 0 y menor al actual";
				
			}
			
	}
	
	
	string alumnoFacultad::obtenerApellido(){
			return this->apellido;
	}
	
	string alumnoFacultad::obtenerNombre(){
			return this->nombre;
	}
	
	string alumnoFacultad::obtenerNacionalidad(){
			return this->nacionalidad;
	}
	
	unsigned int alumnoFacultad::obtenerFechaNacimiento(){
			return this->fechaNacimiento;
	}
	
	unsigned int alumnoFacultad::obtenerPadron(){
			return this->padron;
	}
	
	unsigned int alumnoFacultad::obtenerNumeroDocumento(){
			return this->numeroDocumento;
	}
	
