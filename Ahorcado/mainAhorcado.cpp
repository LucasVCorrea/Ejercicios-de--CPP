#include <iostream>
#include "Ahorcado.h"

using namespace std;

int main() {
	Ahorcado *ahorcado = new Ahorcado();
	try{
		ahorcado->Jugar();
		delete ahorcado;
		
	}catch(const char *x){
			cout<<x;
	}
	
	return 0;
}
