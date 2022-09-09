#include "Ahorcado.h"

Ahorcado::Ahorcado(){
	this->contador = 6;
	this->intentos = 0;
	this->listaPalabras = new std::string[10] {"cars","avengers","harry-potter","shrek","she-hulk","thor","daredevil","venom","ant-man","wolverine"};
	this->suma = 0;
	this->valor = rand() %10 + 1;
	this->palabra = this->listaPalabras[this->valor];
	this->palabraAux = this->palabra;
}

void Ahorcado::parteUno(){
	
	for(int i = 0; i < this->palabra.size(); i++){
		this->palabraAux[i] = '_';	
		cout<<palabraAux[i]<<' ';
	}
}

void Ahorcado::ciclar(){
	int j = 0;
	while (this->contador!=0 && this->palabra != palabraAux){ 
		
		
		if(this->contador == 6){
			cout<<endl<<" ___"<<endl<<"|   |"<<endl<<"|"<<endl<<"|"<<endl<<"|"<<endl;
		}else if(this->contador == 5){
			cout<<endl<<" ___"<<endl<<"|   |"<<endl<<"|   O"<<endl<<"|"<<endl<<"|"<<endl;
		}else if(this->contador == 4){
			cout<<endl<<" ___"<<endl<<"|   |"<<endl<<"|   O"<<endl<<"|   |"<<endl<<"|"<<endl;
		}else if(this->contador == 3){
			cout<<endl<<" ___"<<endl<<"|   |"<<endl<<"|   O"<<endl<<"|  /| "<<endl<<"|"<<endl;
		}else if(this->contador == 2){
			cout<<endl<<" ___"<<endl<<"|   |"<<endl<<"|   O"<<endl<<"|  /|\\ "<<endl<<"|"<<endl;
		}else if(this->contador == 1){
			cout<<endl<<" ___"<<endl<<"|   |"<<endl<<"|   O"<<endl<<"|  /|\\ "<<endl<<"|  /"<<endl;
		}

		
		this->intentos++; 

		cout<<endl<<"Ingrese una letra: ";cin>>this->letra;cout<<endl;
		for(int i = 0; i < this->palabra.size(); i++){
			
			if (this->palabra[i] == this->letra){
				this->palabraAux[i] = this->letra;
				this->suma++;
			}
			cout<<this->palabraAux[i]<<' ';
		}
		
		cout<<endl;
		
		if(this->suma == 0){
			this->contador--;
		}
		



		cout<<endl<<"vidas: "<<this->contador<<endl<<endl;
		this->suma = 0;
		j++;
	}
	if(this->contador == 0){
			cout<<endl<<" ___"<<endl<<"|   |"<<endl<<"|   O"<<endl<<"|  /|\\ "<<endl<<"|  / \\"<<endl;
	}
}

void Ahorcado::final(){
		if(this->contador == 0){
		cout<<endl<<"Mas suerte la proxima!";
	}
	else{
		cout<<endl<<"Felicitaciones! has adivinado la palabra en "<<this->intentos<<" intentos";
	}
}

void Ahorcado::Jugar(){
	cout<<"(tener en cuenta: las peliculas con mas de una palabra se separan con un guion '-' )"<<endl<<endl;
	this->parteUno();
	this->ciclar();
	this->final();
}
