#ifndef MARCADOR_H
#define MARCADOR_H
#include <string>

class Marcador
{
	private:
		
		std::string equipoLocal;
		std::string equipoVisitante;
		std::string equipoGanador;
		int golesLocal;
		int golesVisitante;
		
	public:
		
		/*
			Pre: Se ingresan 2 equipos distintos
			Post: Se registran los equipos
		*/
		Marcador(std::string equipoLocal, std::string equipoVisitante);
		~Marcador();
		
		std::string getEquipoLocal();
		std::string getEquipoVisitante();
		
		
		/*
			Pre: -
			Post: Se le anota un gol al equipo local
		*/
		void golEquipoLocal();
		
		
		/*
			Pre: -
			Post: Se le anota un gol al equipo visitante
		*/
		void golEquipoVisitante();
		
		
		/*
			Pre: - 
			Post: Se termina el partido y gana el visitante
		*/
		void abandonaEquipoLocal();
		
		
		/*
			Pre: - 
			Post: Se termina el partido y gana el local
		*/
		void abandonaEquipoVisitante();
		
		int getGolesLocal();
		int getGolesVisita();
		std::string getEquipoGanador();
};

#endif
