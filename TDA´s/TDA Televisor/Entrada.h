#ifndef ENTRADA_H
#define ENTRADA_H

enum estadoDeEntrada{
	Activada, Desactivada, Seleccionada
};

class Entrada
{

	private:
		estadoDeEntrada estado;
		unsigned int numero;
		unsigned int cantidadDeUsos;	
		char instruccion;
	
	public:
		/*
			pre: el numermo de entrada debe ser mayor o igual a 1
			pos: se crea la entrada HDMI
		*/
		Entrada(int numero);
		
		/*
			pre: -
			pos: se destruye la entrada HDMI
		*/
		virtual ~Entrada();
		
		/*
			pre: - 
			pos: devuelve el estado actual de la entrada
		*/
		estadoDeEntrada getEstado();
		
		/*
			pre: -
			pos: devuelve el numero de la entrada 
		*/
		unsigned int getNumero();
		
		/*
			pre: - 
			pos: devuelve la cantidad de usos de la entrada
		*/
		unsigned int getCantidadDeUsos();
		
		/*
			pre: - 
			pos: activa la entrada HDMI
		*/
		void activar();
		
		/*
			pre: - 
			pos: desactiva la entrada HDMI
		*/
		void desactivar();
		
		/*
			pre: - 
			pos: selecciona la entrada HDMI
		*/void seleccionar();
};

#endif
