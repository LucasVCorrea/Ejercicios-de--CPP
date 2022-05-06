#ifndef VALIDARCONTRASENIA_H
#define VALIDARCONTRASENIA_H
#include <string>

class ValidarContrasenia
{
	private:
		std::string cadena;
		bool esValida;
		bool tieneMayuscula;
		bool tieneNumero;
	
	public:
		ValidarContrasenia();
		~ValidarContrasenia();
		
		
		/*
			Pre: La contraseña debe tener almenos un numero y una mayuscula.
			Post: Se acepta la contraseña.
		*/
		void setContrasenia(std::string);

		std::string getContrasenia();
		
		/*
			devuelve true si la contraseña tiene almenos un caracter numerico.
		*/
		bool checkNumero();
		
		/*
			devuelve true si la contraseña tiene almenos una mayusucla.
		*/
		bool checkMayusc();
		
		/*
			devuelve true si la contraseña la longitud pedida (8 caracteres).
		*/
		bool checkLongitud();
		
		/*
			devuelve true si la contraseña tiene un numero y una mayuscula.
		*/
		bool verSiEsValida();
	
};

#endif
