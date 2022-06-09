#ifndef MONTACARGAS_H
#define MONTACARGAS_H

class Montacargas
{
	private:
		double pesoMaximo;
		double pesoActual;
		double cargasRealizadas;
		double cargasAcumuladas;
	public:
		/*
			pre: el peso debe ser mayor a 0
			pos: instancia el montacargas con el peso maximo a soportar
		*/
		Montacargas(double pesoMaximo);
		
		/*
			pre: -
			pos: libera memoria
		*/
		virtual ~Montacargas();
		
		/*
			pre: -
			pos: devuelve el peso actual que esta soportando el montacargas
		*/
		double obtenerPesoActual();
		
		/*
			pre: -
			pos: devuelve el peso maximo que soporta el montacargas
		*/
		double obtenerPesoMaximo();
		
		/*
			pre: -
			pos: devuelve el peso restante que se puede cargas
		*/
		double obtenerPesoResante();
		
		/*
			pre: -
			pos: devuelve la cantidad de veces que fue descargado el montacargas
		*/
		double obtenerCargasRealizadas();
		
		/*
			pre: -
			pos: devuelve la cantidad de cargas que tiene encima el montacargas
		*/
		double obtenerCargasAcumuladas();
		
		/*
			pre: el peso debe ser mayor a 0 y menor al maximo
			pos: instancia el montacargas con el peso maximo a soportar
		*/
		void cargar(double peso);
		
		/*
			pre: el montacargas debe estar cargado
			pos: libera el montacargas y registra una carga realizada
		*/
		void descargar();
		
	private:
		/*
			pos: devuelve si el montacargas soporta mas peso
		*/
		bool soportaMasPeso();
		
		/*
			pos: devuelve si el montacargas esta cargado
		*/
		bool estaCargado();
		
		/*
			pos: valida si el peso ingresado es valido
		*/
		void validarPeso(double peso);
};
	
#endif
