#ifndef TELEVISOR3_H
#define TELEVISOR3_H
#include "App.h"
#include "Canal.h"
enum estadoDelTelevisor{
	Prendido, Apagado
};

class Televisor3
{
	private:
		int cantidadDeApps,cantidadDeCanales;
		estadoDelTelevisor estado;
		App** aplicaciones;
		Canal** canales;
		void validarEstadoTelevisor();
		void validarEstadoApp(int posicion);
		int validarNombre(std::string nombreDeLaApp);
		int validarExistencia(std::string nombreDeLaApp);
		int canalActual;
		std::string aplicacionActual;
		
	public:
		/*
			pre: la cantidad de canales debe ser mayor o igual a 1 y la cantidad de apps debe ser mayor o igual que 0
		*/
		Televisor3(int cantidadDeCanales,int cantidadDeApps);
		
		/*
			pre: -
			pos: destruye el televisor
		*/
		virtual~Televisor3();
		
		/*
			pre: la posicion debe estar dentro del rango de aplicaciones posibles
			pos: se agrega una app al televisor
		*/
		void agregarApp(int posicion,std::string nombreDeApp);
		
		/*
			pre: el canal debe estar dentro del rango de canales posibles
			pos: se agrega el canal al televisor
		*/
		void agregarCanal(int numero);
	
		/*
			pre: -
			pos: apaga el televisor
		*/
		void apagarTelevisor();

		/*
			pre: -
			pos: enciende el televisor
		*/
		void prenderTelevisor();
	
		/*
			pre: la aplicacion debe existir y estar cerrada
			pos: abre la aplicacion
		*/
		void abrirApp(std::string nombreDeLaApp);
	
		/*
			pre: -
			pos: cierra la aplicacion
		*/
		void cerrarApp(std::string nombreDeLaApp);
		
		
		/*
			pre: -
			pos: devuelve la cantidad total de apps
		*/
		int getCantidadDeAppsTotales();
		
		/*
			pre: -
			pos: devuelve la cantidad total de apps abiertas
		*/
		int getCantidadDeAppsAbiertas();
	
		/*
			pre: -
			pos: devuelve la cantidad total de canales
		*/
		int getCantidadDeCanalesTotales();
		
		/*
			pre: -
			pos: devuelve el canal actual
		*/
		int getCanalActual();
		
		/*
			pre: -
			pos: devuelve el canal mas visto
		*/
		int getCanalMasVisto();
		
		/*
			pre: -
			pos: devuelve la aplicacion actual
		*/
		std::string getAplicacionActual();
		
		/*	
			pre: -
			pos: muestra el nombre de la aplicacion 
		*/
		std::string mostrarAplicacion(int posicion);
		
		/*
			pre: -
			pos: devuelve la app mas usada
		*/
		std::string getAppMasUsada();
	
		/*
			pre: -
			pos se desplaza un canal arriba del actual
		*/
		void subirUnCanal();
	
		/*
			pre: -
			pos: se desplaza un canal abajo del actual
		*/
		void bajarUnCanal();
	
		/*
			pre: el canal debe estar agregado
			pos: cambia el canal actual
		*/
		void cambiarDeCanal(int canalActual);
};

#endif
