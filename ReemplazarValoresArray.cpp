#include <iostream>

using namespace std;

bool mostrar(int * p,int n) ///imprime el vector pasado por puntero.
{
    int contador=0;
    bool unos = true;
    for (int i=0;i<n;i++)
        {cout<<*(p+i)<<' ';
        if (*(p+i) == 1)
            {contador++;}
        
        if (contador==n)
            {unos=false;}
        }
    cout<<endl<<"Cantidad de unos: "<<contador<<endl<<"Bool: "<<unos<<endl;
    return unos;
}


void cargar(int * p ,int n)  //arma el vector pasado por puntero.

{
    for (int i=0;i<n;i++)
        {
            cout<<"Ingrese el valor del vector: ";cin>>*(p+i);
            
        }
}   


void cambiar(int * p ,int n) //reemplaza por un valor donde diga el usuario
{
    int posicion;
    cout<<endl<<"Ingrese la posicion que quiere cambiar: " ;cin>>posicion;
    cout<<"Ingrese el nuevo valor: ";cin>>*(p+posicion);
    
}


int main()
{
    int tamanio;
    cout<<"Ingrese el tamaño del vector: ";cin>>tamanio;
    cout<<endl;
    int vec[tamanio];
    int * p=vec;

    cargar(vec,tamanio);

    while (mostrar(vec,tamanio)!=0)
        {
            cambiar(vec,tamanio);
        }
    cout<<endl<<"Fin del programa.";
    return 0;
}
