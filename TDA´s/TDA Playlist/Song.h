#ifndef SONG_H
#define SONG_H
#include <string>

class Song
{
	private:
		std::string nombreDeLaCancion;
		unsigned int cantidadDeReproducciones;
		
	public:
		
		/*
			pre: el nombre de la cancion no puede estar vacio
			post: crea una cancion
		*/
		Song(std::string NombreDeLaCancion);
		
		/*
			pre: - 
			pos: destruye la cancion
		*/
		virtual ~Song();
		
		/*
			pre: -
			pos: devuelve el nombre de la cancion
		*/
		std::string getNombre();
		
		/*
			pre: 
			pos: devuelve la cantidad de veces que fue reproducida la cancion
		*/
		unsigned int getCantidadDeReproducciones();
		
		/*
			pre: -
			pos: suma una reproduccion a la cancion
		*/
		void sumarReproduccion();
};

#endif
