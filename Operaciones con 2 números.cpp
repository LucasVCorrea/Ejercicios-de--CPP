#include <iostream>

using namespace std;

void sumar(int num_1, int num_2)
{
    int resultado=num_1+num_2;
    cout<<" El resultado es: "<<resultado;
}


void restar(int num_1, int num_2)
{
    int resultado=num_1-num_2;
    cout<<" El resultado es: "<<resultado;
}


void multiplicar(int num_1, int num_2)
{
    int resultado=num_1*num_2;
    cout<<" El resultado es: "<<resultado;
}


void dividir(int num_1, int num_2)
{
    int resultado=num_1/num_2;
    cout<<" El resultado es: "<<resultado;
}



int main()
{
    int numero_1; 
    int numero_2;
    char operacion;
    cout<<"suma(+)  resta(-)  multiplicacion(*)  division(/)\n"<<endl;
    cout<<"Ingrese el primer valor: ";cin>>numero_1;
    cout<<"Ingrese el segundo valor: ";cin>>numero_2;
    cout<<"Ingrese la operacion a realizar: ";cin>>operacion;
    if (operacion == '+')
        sumar(numero_1,numero_2);
    else
        if (operacion == '-')
            restar(numero_1,numero_2);
        else
            if (operacion == '*')
                multiplicar(numero_1,numero_2);
            else
                if (operacion=='/')
                    dividir(numero_1,numero_2);
                else
                    cout<<"Operacion ingresada invalida. Fin del programa."<<endl;
    return 0;
}
