#include <iostream>
#include "Restaurant.h"

using namespace std;

int main(){
	Restaurant *resto = new Restaurant(5);
	resto->abrirRestaurant();
	resto->agregarUnaMesa();

	cout<<" Mesas agregadas: "<< resto->getMesasActuales()<<endl;
	cout<<" Maximo historico de mesas agregadas: "<<resto->getRecordDeMesas()<<endl;
	delete resto;
	return 0;
}
