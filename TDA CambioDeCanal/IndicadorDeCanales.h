#ifndef INDICADORDECANALES_H
#define INDICADORDECANALES_H

class IndicadorDeCanales
{
	private:
		
		int canalMinimo;
		int canalMaximo;
		int canalActual;
		int nuevoCanal;
		char instruccion;
	
	public:
		
		IndicadorDeCanales();
		~IndicadorDeCanales();
		
		/*
			pre: Indica el canal al que quiere saltar, tiene que estar entre 1 y 299
			post: Se cambia al canal indicado
		*/
		void cambiarCanal(int nuevoCanal);
		
		/*
			Pre: ingresa + si quere subir 1 canal, - si quiere bajar un canal
			post: se realiza el cambio de canal
		*/
		void subirOBajarCanal(char);


		int getCanalActual();
		
};

#endif
