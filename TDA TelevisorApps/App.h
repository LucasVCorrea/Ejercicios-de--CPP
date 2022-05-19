#ifndef APP_H
#define APP_H
#include <string>

enum estadoDeApp{
	Abierta, Cerrada
};

class App
{
	private:
		
		std::string nombreDeApp;
		
		int numero,cantidadDeUsos;
		
		estadoDeApp estado;
	
	public:
		/*
			pre: el numero debe ser mayor a 0
			pos: se crea una aplicacion, con su nombre
		*/
		App(int numero,std::string nombreDeApp);
		
		/*
			pre: -
			pos: destruye la app
		*/
		virtual ~App();
		
		/*
			devuelve el estado actual de la aplicacion
		*/
		estadoDeApp getEstado();
		
		/*
			devuelve el nombre de la app
		*/
		std::string getNombreDeApp();
		
		/*
			devuelve el numero de la app
		*/
		int getNumeroDeApp();
		
		/*
			devuelve la cantidad de veces que fue usada la app
		*/
		int getCantidadDeUsos();
		
		/*
			abre la app
		*/
		void abrir();
		
		/*
			cierra la app
		*/
		void cerrar();
			
};

#endif
