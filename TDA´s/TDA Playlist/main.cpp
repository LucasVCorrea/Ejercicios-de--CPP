#include <iostream>
#include "RepList.h"

using namespace std;

int main() {
	
	try{
		
	RepList *myPlaylist = new RepList(5);
	
	myPlaylist->addSong("Boyz n the hood");
	myPlaylist->addSong("Hypnotize");
	myPlaylist->addSong("Big Poppa");
	myPlaylist->addSong("Nowadays");

	
	myPlaylist->reproducirCancion(3);
	myPlaylist->reproducirCancion(3);
	myPlaylist->reproducirCancion(3);
	myPlaylist->reproducirCancion(2);
	
	
	cout<<"Actualmente sonando "<<myPlaylist->getCancionActual()<<endl;
	cout<<" La cancion mas escuchada es "<<myPlaylist->getCancionMasEscuchada();
	cout<<" ("<< myPlaylist->reproduccionesDeLaMasEscuchada()<<" veces)"<<endl;
	
	
	delete myPlaylist;
	}catch(const char* x){
		cout<< x <<endl;
	}
	
	return 0;
}
