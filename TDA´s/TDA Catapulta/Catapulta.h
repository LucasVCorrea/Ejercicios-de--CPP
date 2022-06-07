#ifndef CATAPULTA_H
#define CATAPULTA_H
#include "math.h"
class Catapulta
{
	private:
		double pesoMaximo;
		double pesoDisponible;
		double contrapeso;
		unsigned int proyectilesLanzados;
		unsigned int proyectilesCargados;
		unsigned int distanciaMaxima;
		
	public:
		
		/*
			pre: el contrapeso debe ser mayor o igual a 1
			pos: instancia la catapulta con su contrapeso
		*/
		Catapulta(double contrapeso);
		
		/*
			pre: - 
			pos: libera memoria
		*/
		virtual ~Catapulta();
		
		/*
			pre: el peso debe ser mayor a 0 y menor o igual a 10 veces el contrapeso
			pos: carga un proyectil con su peso
		*/
		void cargar(double pesoProyectil);
		
		/*
			pre: la catapulta debe estar cargada
			pos: descarga la catapulta
		*/
		void descargar();
		
		/*
			pre: la catapulta debe estar cargada
			pos: lanza los proyectiles cargados, devuelve la distancia del disparo y deja la catapulta 
				descargada
		*/
		unsigned int disparar();
		
		/*
			pre: - 
			pos: devuelve el contrapeso de la catapulta
		*/
		double getContrapeso();
		
		/*
			pre: - 
			pos: devuelve el peso maximo soportado
		*/
		double getPesoMaximo();
		
		/*
			pre: - 
			pos: devuelve el peso disponible para cargar
		*/
		double getPesoDisponible();
		
		/*
			pre: - 
			pos: devuelve los proyectiles cargados en el momento
		*/
		unsigned int getProyectilesCargados();
		
		/*
			pre:  -
			pos: devuelve el historial de proyectiles que fueron lanzados
		*/
		unsigned int getProyectilesLanzados();
		
		/*
			pre: se tuvo que haber realizado un disparo
			pos: devuelve la distancia maxima alcanzada
		*/
		unsigned int getDistanciaMaxima();
		
	private:
		bool proyectilValido(double pesoProyectil);
		bool soportaMasPeso();
		void actualizarMaximo(unsigned int distancia);
};

#endif
