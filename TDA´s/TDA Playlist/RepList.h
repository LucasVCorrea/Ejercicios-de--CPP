#ifndef REPLIST_H
#define REPLfIST_H
#include "Song.h"
#include <string>

class RepList
{
	private:
		
		unsigned int cantidadDeCanciones;
		Song** songs;
		Song* cancionActual;
		Song* cancionMasEscuchada;
		
		void verQueHayaAlgo(unsigned int posicion);
	
		unsigned int establecerPosicion(); 
		void verQueNoHayaSidoAgregada(std::string nombre);
		
	public:
		
		/*
			pre: el tamaño de la playlist debe ser mayor o igual a 1
			pos: crea la playlist
		*/
		RepList(unsigned int cantidadDeCanciones);
		
		/*
			pre: la cancion no debe haber sido agregada a la playlist
			pos: agrega una cancion a la ultima posicion disponible
		*/
		void addSong(std::string nombreCancion);
		
		/*
			pre: debe haber una cancion en esa posicion
			pos: se reproduce la cancion en esa posicion
		*/
		void reproducirCancion(unsigned int posicion);
		
		/*
			pre: la posicion y la cancion deben estar en la playlist
			pos: reemplaza la cancion en esa posicion por otra
		*/
		void replaceSong(unsigned int posicion,std::string nombreCancion);
		
		/*
			pre: -
			pos: elimina las canciones y la playlist
		*/
		virtual ~RepList();
		
		/*
			pre: - 
			pos: devuelve el tamaño de la playlist
		*/
		unsigned int getCantidadDeCanciones();
		
		/*
			pre: debe haber una cancion en esa posicion
			pos: devuelve la cantidad de veces que se escucho la cancion que este en esa posicion
		*/
		unsigned int getCuantasVecesSeEscucho(unsigned int posicion);
		
		unsigned int reproduccionesDeLaMasEscuchada();
		std::string getCancion(unsigned int posicion);
		std::string getCancionActual();
		std::string getCancionMasEscuchada();

		
};

#endif
