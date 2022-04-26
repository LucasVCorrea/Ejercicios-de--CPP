#include <iostream>

using namespace std;

class Montacargas {
	// Private section
	double pesoMaximo ;
	double pesoActual ;
	double TotalCargado;
	int cantidadDeCargas;
	
	public:
		// Public Declarations
		Montacargas(double);
		~Montacargas();
		double obtenerCarga(); //getCarga
		double cargar(double); //setCarga.
		double obtenerPesoRestanteLibre();
		double descargar();
		bool estaCargado();
		double obtenerCargaPromedio();
		double obtenerCantidadDeCargas();
		double obtenerPesoTotal();
		
};

Montacargas :: Montacargas(double _pesoMax){
	
	pesoMaximo = _pesoMax;
	pesoActual = 0;
	TotalCargado = 0;
	cantidadDeCargas = 0;
}

Montacargas :: ~Montacargas(){
}

double Montacargas :: obtenerCarga(){
		return pesoActual;}

double Montacargas :: cargar(double carga){
	pesoActual +=carga;	
	return carga;
	}
	
double Montacargas :: obtenerPesoRestanteLibre(){
	double pesoLibre = pesoMaximo - pesoActual;
	return pesoLibre;
}

bool Montacargas :: estaCargado(){
	return (this->obtenerCarga() > 0);
}

double Montacargas :: descargar(){
	 
	 if ((this->estaCargado()) && (obtenerCarga()<1000)){
		TotalCargado += pesoActual;
		cantidadDeCargas++;
		pesoActual=0;
			
	 }
	
}
double Montacargas :: obtenerCantidadDeCargas(){

	return cantidadDeCargas;
}

double Montacargas :: obtenerPesoTotal(){
	
	return TotalCargado;
}

double Montacargas :: obtenerCargaPromedio(){
	double cargaPromedio;
	cargaPromedio = TotalCargado / cantidadDeCargas;
	return cargaPromedio;

}
