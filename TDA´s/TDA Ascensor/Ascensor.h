#ifndef ASCENSOR_H
#define ASCENSOR_H
#include "Piso.h"
class Ascensor
{
	private:
		int cantidadDePisos,totalDeSubidas,totalDeBajadas,pisoActual;
		int desplazamiento;
		Piso** pisos;
		void validarDireccionamiento(int piso);
	public:
		Ascensor(int cantidadDePisos);
		
		virtual ~Ascensor();
		
		void llamarDesde(int pisoDeLlamada);
		
		int getCantidadDePisos();
		
		int getCantidadDeVecesQueFueAlPiso(int piso);
		
		int getPisoActual();
		
		int getTotalDePisosSubidos();
		
		int getTotalDePisosBajados();
		
		int getDesplazamiento();
		
		int getPiso(int pisoDeMuestra);
		
};

#endif
