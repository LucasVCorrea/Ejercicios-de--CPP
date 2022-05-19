#include "Televisor3.h"

Televisor3::Televisor3(int cantidadDeCanales,int cantidadDeApps){
	if ((cantidadDeApps < 0) || (cantidadDeCanales <= 0)){
		throw "Numero invalido";
	}
	
	this->cantidadDeApps = cantidadDeApps;
	this->cantidadDeCanales = cantidadDeCanales;
	this->estado = Apagado;
	this->canalActual=0;
	this->aplicaciones = new App*[cantidadDeApps];
	this->canales = new Canal*[cantidadDeCanales];
	
	for(int i = 1;i<=this->cantidadDeApps;i++){
		this->aplicaciones[i] = NULL;
	}
	
	for (int i = this->cantidadDeCanales;i>0;i--){
		this->canales[i]=NULL;
	}
}


Televisor3::~Televisor3(){
	for(int i = 1;i<=this->cantidadDeApps;i++){
		delete this->aplicaciones[i];
	}
	delete this->aplicaciones;
	
	for (int i = this->cantidadDeCanales;i>0;i--){
		delete this->canales[i];
	}
	delete this->canales;
}


void Televisor3::validarEstadoTelevisor(){
	if(this->estado == Apagado){
		throw "El televisor esta apagado";
	}
}

int Televisor3::getCantidadDeAppsTotales(){
	return this->cantidadDeApps;
}

void Televisor3::apagarTelevisor(){
	this->estado = Apagado;
}

void Televisor3::prenderTelevisor(){
	this->estado = Prendido;
}


int Televisor3::validarNombre(std::string nombreDeLaApp){
	int repeticionDeApp = 0;
	for (int i=1; i<=this->cantidadDeApps;i++){
		
		if((this->aplicaciones[i]!=NULL) && (this->aplicaciones[i]->getNombreDeApp() == nombreDeLaApp)){
			repeticionDeApp++;
		}
	}
	return repeticionDeApp;
}

void Televisor3::agregarApp(int posicion,std::string nombreDeApp){

	validarEstadoTelevisor();
	
	if (this->validarNombre(nombreDeApp) > 0){
		throw "Hay mas de una aplicacion con el mismo nombre";
	}
	
	if ((posicion <= 0) || (posicion>this->cantidadDeApps)){
		throw "la posicion no existe";
	}
	if (this->aplicaciones[posicion]!=NULL){
		throw "ya hay una aplicacion alli";
	}
	
	this->aplicaciones[posicion] = new App(posicion,nombreDeApp);
}

void Televisor3::agregarCanal(int numero){
	validarEstadoTelevisor();
	
	if(numero<=0 || numero>this->cantidadDeCanales){
		throw "Canal incorrecto";
	}
	if(this->canales[numero]!=NULL){
		throw "ya existe ese canal";
	}
	
	this->canales[numero] = new Canal(numero);
}

std::string Televisor3::mostrarAplicacion(int posicion){
	validarEstadoTelevisor();
	
	if ((posicion <= 0) || (posicion>this->cantidadDeApps)){
		throw "la posicion no existe";
	}
	if (this->aplicaciones[posicion]==NULL){
		throw "no hay ninguna aplicacion en esa posicion";
	}
	return this->aplicaciones[posicion]->getNombreDeApp();	
}

int Televisor3::validarExistencia(std::string nombreDeLaApp){
	int posicionDeLaAplicacion;
	for(int i=1;i<=this->cantidadDeApps;i++){
		if((this->aplicaciones[i]!=NULL) && (this->aplicaciones[i]->getNombreDeApp()==nombreDeLaApp)){
			posicionDeLaAplicacion = i;
		}
	}
	
	return posicionDeLaAplicacion;
}

int Televisor3::getCantidadDeAppsAbiertas(){
	int cantidadDeAbiertas = 0;
	for(int i=1;i<=this->getCantidadDeAppsTotales();i++){
		if(this->aplicaciones[i]->getEstado() == Abierta){
			cantidadDeAbiertas++;
		}
	}
	
	return cantidadDeAbiertas;
	
}


void Televisor3::abrirApp(std::string nombreDeLaApp){
	if(this->validarExistencia(nombreDeLaApp) == NULL){
		throw "La aplicacion no existe";
	}
	
	if(this->aplicaciones[this->validarExistencia(nombreDeLaApp)]->getEstado()==Abierta){
		throw "La aplicacion ya esta abierta";
	}

	this->aplicaciones[this->validarExistencia(nombreDeLaApp)]->abrir();
	
	if(this->getCantidadDeAppsAbiertas() > 1){
		throw "Debe cerrar una app para abrir otra";
	}
	
	this->aplicacionActual = this->aplicaciones[this->validarExistencia(nombreDeLaApp)]->getNombreDeApp();
}

void Televisor3::cerrarApp(std::string nombreDeLaApp){
	if(this->validarExistencia(nombreDeLaApp) == NULL){
		throw "La aplicacion no existe";
	}
	this->aplicaciones[this->validarExistencia(nombreDeLaApp)]->cerrar();
	this->aplicacionActual = "-";
}


std::string Televisor3::getAplicacionActual(){
	
	return this->aplicacionActual;
}

std::string Televisor3::getAppMasUsada(){
	App* aplicacionMasUsada = this->aplicaciones[1];
	for (int i=1; i<=this->getCantidadDeAppsTotales();i++){
		if(this->aplicaciones[i]->getCantidadDeUsos() > aplicacionMasUsada->getCantidadDeUsos()){
			aplicacionMasUsada = this->aplicaciones[i];
		}
	}
	return aplicacionMasUsada->getNombreDeApp();
}

int Televisor3::getCantidadDeCanalesTotales(){
	return this->cantidadDeCanales;
}

int Televisor3::getCanalActual(){
	return this->canalActual;
}


void Televisor3::cambiarDeCanal(int canalActual){
	if ((canalActual <=0) || (canalActual > this->getCantidadDeCanalesTotales())){
		throw "El canal no existe";
	}
	if(this->canales[canalActual] == NULL){
		throw "El canal no fue agregado";
	}
	if(this->getCantidadDeAppsAbiertas()>0){
		throw "No se puede cambiar de canal si hay una app abierta";
	}
	
	this->canalActual = canalActual;
	this->canales[canalActual]->agregarUnaVista();
}

int Televisor3::getCanalMasVisto(){
	Canal* mayor = this->canales[1];
	for (int i = 1 ;i <= this->getCantidadDeCanalesTotales();i++){
		if((this->canales[i]!=NULL) && (this->canales[i]->getCantidadDeVistas() > mayor->getCantidadDeVistas())){
			mayor = this->canales[i];
		}
	}
	return mayor->getNumero();
}

void Televisor3::subirUnCanal(){
	this->canalActual++;
	
	if ((canalActual <=0) || (canalActual > this->getCantidadDeCanalesTotales())){
		throw "El canal no existe";
	}
	
	if(this->canales[canalActual] == NULL){
		throw "El canal no fue agregado";
	}
	
	if(this->getCantidadDeAppsAbiertas()>0){
		throw "No se puede cambiar de canal si hay una app abierta";
	}
}

void Televisor3::bajarUnCanal(){
	this->canalActual--;
	
	if ((canalActual <=0) || (canalActual > this->getCantidadDeCanalesTotales())){
		throw "El canal no existe";
	}
	
	if(this->canales[canalActual] == NULL){
		throw "El canal no fue agregado";
	}
	
	if(this->getCantidadDeAppsAbiertas()>0){
		throw "No se puede cambiar de canal si hay una app abierta";
	}
}











