#ifndef CLARK_H
#define CLARK_H



class Clark
{
	private:
		double pesoMaximoDeCarga ;
		double pesoActualDeCarga ;
		double totalHistoricoCargado;
		unsigned int cantidadDeDescargasRealizadas;
	
	public:
		//pre: el peso debe ser positivo
		//post: queda vacio el Clark. Si el peso fue negativo, queda 0.
		Clark(double);
		~Clark();
		double obtenerCarga( ); //getCarga
		
		//pre: indicar la carga en kg mayor a 0 y menor o igual al peso libre
		//post: acumulo la carga al monta cargas
		double cargar(double); //setCarga.
		//pre:
		//post:
		
		double obtenerPesoRestanteLibre();
		
		//pre: --
		//post: deja el Clark vacio.
		double descargar();
		//pre: 
		//post:
		bool estaVacio();
		//pre:
		//post:
		double obtenerCargaPromedio();
		//pre:
		//post:
		double obtenerCantidadDeCargas();
		//pre:
		//post:
		double obtenerPesoTotal();
		
		//pre:
		//post:
		double obtenerPesoMaximo();
		//
		//
		double obtenerPesoActual();
};


#endif
