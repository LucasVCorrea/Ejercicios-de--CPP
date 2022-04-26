#include <iostream>

using namespace std;

int main()
{
    int numero;
    int contador=0;
    int sumatoria=0;
    cout<<"Ingrese numeros para sumar (para terminar ingrese 0): ";cin>>numero;
    sumatoria+=numero;
    
    while (numero !=0)
        {
            cout<<"Ingrese numeros para sumar (para terminar ingrese 0): ";cin>>numero;
            sumatoria+=numero;
            contador++;
        }
    cout<<"La suma de todos da: "<<sumatoria<<endl;
    cout<<"Cantidad de numeros totales ingresados: "<<contador<<endl;
    return 0;
}
