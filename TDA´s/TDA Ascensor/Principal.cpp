#include <iostream>
#include "Ascensor.h"

using namespace std;

int main(){
	Ascensor *ascensor = new Ascensor(12);
	ascensor->llamarAscensor(4);
	delete ascensor;
	return 0;
}
