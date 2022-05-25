#ifndef PISO_H
#define PISO_H

class Piso
{
	private:
		int piso,cantidadDeApariciones;
	
	public:
		Piso(int piso);
		
		virtual ~Piso();
		
		int getNumero();
		
		int getCantidadDeApariciones();
		
		void contarAparicion();
	
};

#endif
