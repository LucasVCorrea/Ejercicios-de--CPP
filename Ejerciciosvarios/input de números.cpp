#include <iostream>

using namespace std;

int main()
{
    int numero;
    int contador = 0;
    int contador_mayor = 0;
    int contador_menor = 0;
    
    cout<<"Ingrese numeros o 0 para terminar: ";cin>>numero;
    int menor = numero;
    int mayor = numero;
    contador++;
    while (numero != 0)
        {
            cout<<"Ingrese numeros o 0 para terminar: ";cin>>numero;
            if (numero < menor)
               { 
                menor = numero;
                contador_menor = contador;
               }
            else
                if (numero > mayor)
                    {
                    mayor = numero;
                    contador_mayor = contador;
                    }
        contador++;
        }
        
    cout<<endl<<"Fin del programa, se ingresaron "<<contador<<" valores (contando el finalizador)."<<endl;
    cout<<"El menor es: "<<menor<<" y se encuentra en la posicion "<<contador_menor<<endl;
    cout<<"El mayor es: "<<mayor<<" y se encuentra en la posicion "<<contador_mayor<<endl;

    

    return 0;
}
