#include "Ahorcado.h"

Ahorcado::Ahorcado(){
	this->reset();
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

		cout<<endl<<"Ingrese una letra o '$' para arreisgar una palabra: ";cin>>this->letra;cout<<endl;
		if (this->letra == '$'){
			cout<<"Ingrese la palabra: ";cin>>this->palabraArriesgada;
			if(this->palabraArriesgada == this->palabra){
				break;
			}
			else{
				break;
			}
		}
		
		for(int i = 0; i < this->palabra.size(); i++){
			
			if (this->palabra[i] == this->letra){
				this->palabraAux[i] = this->letra;
				this->letrasEncontradas++;
			}
				
			cout<<this->palabraAux[i]<<' ';
		}
		
		if(this->letrasEncontradas == 0){
			this->vidas--;
		}
		
		cout<<endl<<endl<<"vidas: "<<this->vidas<<endl<<endl;
		this->letrasEncontradas = 0;
		j++;
	}
	
	if(this->vidas == 0){
			cout<<endl<<" ___"<<endl<<"|   |"<<endl<<"|   O"<<endl<<"|  /|\\ "<<endl<<"|  / \\"<<endl;
	}
}

void Ahorcado::final(){
	if((this->vidas == 0) && this->palabraArriesgada!=this->palabra){
		cout<<endl<<"Mas suerte la proxima! (la palabra era '"<< this->palabra <<"')";
	}
	else{
		cout<<endl<<"Felicitaciones! has adivinado la palabra en "<<this->intentos<<" intentos"<<endl;
	}
	cout<<endl<<"Quieres jugar otra vez? (s/n): ";cin>>this->opcion;cout<<endl;
	
	if(this->opcion == 's'){ /// Back to game
		this->Jugar();
	}
	else{
		cout<<endl<<"Gracias por jugar!"<<endl;
	}
	
}

void Ahorcado::Jugar(){
	this->mostrarTemas();
	cout<<endl<<"Elija el tema: ";cin>>this->temaElegido;
	this->elegirTema();
	cout<<"(tener en cuenta: las palabras se separan con un guion '-' )"<<endl<<endl;
	this->reset();
	this->parteUno();
	this->ciclar();
	this->final();
	
}

Ahorcado::~Ahorcado(){
	delete[] this->listaCantantes;
	delete[] this->listaPalabras;
}

int Ahorcado::generaRandomNumber(){
	srand(time(0)); // Initialize random number generator.

	for(int i = 0;i < 1;i ++){
		this->randomNumber = (rand() % 10);
	}

    return this->randomNumber;
}

void Ahorcado::reset(){
	
	this->vidas = 6;
	this->intentos = 0;
	this->listaPalabras = new std::string[12] {"morbius","iron-man","spider-man","capitan-america","she-hulk","thor","daredevil","venom","ant-man","x-men","moonknight","luke-cage"};
	this->listaCantantes = new std::string[12] {"bad-bunny","dua-lipa","ed-sheeran","la-mona-gimenez","harry-styles","justin-bieber","duki","travis-scott","ac/dc","miranda","maria-becerra","kanye-west"};
	this->letrasEncontradas = 0;
	this->randomNumber = this->generaRandomNumber() ;
	this->palabraAux = this->palabra;
}

void Ahorcado::elegirTema(){

	switch(this->temaElegido){
		case '1':
			this->palabra = this->listaPalabras[this->randomNumber];
			break;
		case '2':
			this->palabra = this->listaCantantes[this->randomNumber];
			break;
		default:
			cout<<"Se ingreso un numero invalido, se elige 'Peliculas/Series de marvel' por default"<<endl;
			this->palabra = this->listaPalabras[this->randomNumber];
			break;
			
	}
}

void Ahorcado::mostrarTemas(){
	string listaDeTemas[] = {"Peliculas/Series de marvel", "Cantantes/Bandas"};
	int tamanio = (sizeof(listaDeTemas) / sizeof(string));
	cout<<"Lista de temas:"<<endl;
	for (int i = 0; i < tamanio; i++){
		cout<<" "<<i + 1<<" - "<<listaDeTemas[i]<<endl;
	}
}
