#include "Ahorcado.h"

Ahorcado::Ahorcado(){
	this->reset();
}

void Ahorcado::parteUno(){
	limpiarPalabra();
}

void Ahorcado::ciclar(){
	int j = 0;
	while (this->vidas!=0 && this->palabra != palabraAux){ 
		
		if(this->vidas == 6){
			imprimeMonigote(6);
			
		}else if(this->vidas == 5){
			imprimeMonigote(5);
			
		}else if(this->vidas == 4){
			imprimeMonigote(4);
			
		}else if(this->vidas == 3){
			imprimeMonigote(3);
			
		}else if(this->vidas == 2){
			imprimeMonigote(2);
			
		}else if(this->vidas == 1){
			imprimeMonigote(1);
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
		imprimeMonigote(0);
	}
}

void Ahorcado::final(){
	if(this->vidas == 0) {
		cout<<endl<<"Mas suerte la proxima! (la palabra era '"<< this->palabra <<"')";
	}
	else if(this->palabra == this->palabraAux || this->palabraArriesgada == this->palabra){
		cout<<endl<<"Felicitaciones! has adivinado la palabra en "<<this->intentos<<" intentos"<<endl;
	}
	else{
		cout<<endl<<"Mas suerte la proxima! (la palabra era '"<< this->palabra <<"')";	
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
	
	cout<<"(tener en cuenta: las palabras se separan con un guion '-' )"<<endl<<endl;
	this->reset();
	this->elegirTema();
	this->parteUno();
	this->ciclar();
	this->final();
	
}

Ahorcado::~Ahorcado(){

}

int Ahorcado::generaRandomNumber(){
	srand(time(0)); // Initialize random number generator.

	for(int i = 0;i < 1;i ++){
		this->randomNumber = (rand() % 21);
	}

    return this->randomNumber;
}

void Ahorcado::reset(){
	this->listaMarvel = new std::string[20]  {"mighty-thor","iron-man","spider-man","capitan-america","she-hulk",
	"wolverine","daredevil","venom","ant-man","capitana-marvel","moonknight","luke-cage","black-panther","carnage","dr-strange",
	"black-widow","scarlet-witch","vision","reed-richards","kingping"};
	this->listaCantantes = new std::string[20] {"bad-bunny","dua-lipa","ed-sheeran","la-mona-gimenez","harry-styles",
	"justin-bieber","duki","travis-scott","ac/dc","miranda","maria-becerra","kanye-west","bruce-dickinson","j-balvin","quevedo","rosalia","playboi-carti","pablo-lescano","myke-towers","nicki-nicole"};
	this->listaPersonajes = new std::string[20] {"thresh","skarner","udyr","tristana","urgot","lucian","jinx","zyra","aurelion-sol",
	"blitzcrank","yummy","yasuo","kindred","ahri","morgana","ivern","heimerdinger","braum","yorick","sion"};
	
	this->vidas = 6;
	this->intentos = 0;
	this->letrasEncontradas = 0;
	this->randomNumber = this->generaRandomNumber();
}

void Ahorcado::elegirTema(){

	switch(this->temaElegido){
		case '1':
			this->palabra = this->listaMarvel[this->randomNumber];
			this->palabraAux = this->palabra;
			break;
		case '2':
			this->palabra = this->listaCantantes[this->randomNumber];
			this->palabraAux = this->palabra;
			break;
		case '3':
			this->palabra = this->listaPersonajes[this->randomNumber];
			this->palabraAux = this->palabra;
			break;
		default:
			cout<<"Se ingreso un numero invalido, se elige 'Personajes de marvel' por default"<<endl;
			this->palabra = this->listaMarvel[this->randomNumber];
			break;
	}
}

void Ahorcado::mostrarTemas(){
	string listaDeTemas[] = {"Personajes de marvel", "Cantantes/Bandas","Champs del lol"};
	int tamanio = (sizeof(listaDeTemas) / sizeof(string));
	cout<<"Lista de temas:"<<endl;
	for (int i = 0; i < tamanio; i++){
		cout<<" "<<i + 1<<" - "<<listaDeTemas[i]<<endl;
	}
}
