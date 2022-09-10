#include "Ahorcado.h"

Ahorcado::Ahorcado(){
	this->vidas = 6;
	this->intentos = 0;
	this->listaPalabras = new std::string[12] {"morbius","iron-man","spider-man","capitan-america","she-hulk","thor","daredevil","venom","ant-man","x-men","moonknight","luke-cage"};
	this->letrasEncontradas = 0;
	this->randomNumber = this->generaRandomNumber() ;
	this->palabra = this->listaPalabras[this->randomNumber];
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
	while (this->vidas!=0 && this->palabra != palabraAux){ 
		
		
		if(this->vidas == 6){
			cout<<endl<<" ___"<<endl<<"|   |"<<endl<<"|"<<endl<<"|"<<endl<<"|"<<endl;
		}else if(this->vidas == 5){
			cout<<endl<<" ___"<<endl<<"|   |"<<endl<<"|   O"<<endl<<"|"<<endl<<"|"<<endl;
		}else if(this->vidas == 4){
			cout<<endl<<" ___"<<endl<<"|   |"<<endl<<"|   O"<<endl<<"|   |"<<endl<<"|"<<endl;
		}else if(this->vidas == 3){
			cout<<endl<<" ___"<<endl<<"|   |"<<endl<<"|   O"<<endl<<"|  /| "<<endl<<"|"<<endl;
		}else if(this->vidas == 2){
			cout<<endl<<" ___"<<endl<<"|   |"<<endl<<"|   O"<<endl<<"|  /|\\ "<<endl<<"|"<<endl;
		}else if(this->vidas == 1){
			cout<<endl<<" ___"<<endl<<"|   |"<<endl<<"|   O"<<endl<<"|  /|\\ "<<endl<<"|  /"<<endl;
		}

		
		this->intentos++; 

		cout<<endl<<"Ingrese una letra: ";cin>>this->letra;cout<<endl;
		for(int i = 0; i < this->palabra.size(); i++){
			
			if (this->palabra[i] == this->letra){
				this->palabraAux[i] = this->letra;
				this->letrasEncontradas++;
			}
			cout<<this->palabraAux[i]<<' ';
		}
		
		cout<<endl;
		
		if(this->letrasEncontradas == 0){
			this->vidas--;
		}
		



		cout<<endl<<"vidas: "<<this->vidas<<endl<<endl;
		this->letrasEncontradas = 0;
		j++;
	}
	if(this->vidas == 0){
			cout<<endl<<" ___"<<endl<<"|   |"<<endl<<"|   O"<<endl<<"|  /|\\ "<<endl<<"|  / \\"<<endl;
	}
}

void Ahorcado::final(){
		if(this->vidas == 0){
		cout<<endl<<"Mas suerte la proxima!";
	}
	else{
		cout<<endl<<"Felicitaciones! has adivinado la palabra en "<<this->intentos<<" intentos";
	}
	cout<<endl<<"Quieres jugar otra vez? (s/n): ";cin>>this->opcion;
	if(this->opcion == 's'){
		this->Jugar();
	}
	
}

void Ahorcado::Jugar(){
	cout<<"(tener en cuenta: las peliculas con mas de una palabra se separan con un guion '-' )"<<endl<<endl;
	this->parteUno();
	this->ciclar();
	this->final();
}

Ahorcado::~Ahorcado(){
	
}

int Ahorcado::generaRandomNumber(){
	srand(time(0)); // Initialize random number generator.

	for(int i=0;i<1;i++){
		this->randomNumber = (rand() % 10);
	}

    return this->randomNumber;
}
