#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void Escribir(char tab[][10],int ronda){ //funcion que crea el archivo. Se llama mas abajo en el main
    
    ofstream archivo("TableroPorRondas.txt", std::fstream::app);
    archivo<<"Ronda: "<<ronda<<"\n";
    for (int i=0;i<10;i++){
        
        for (int j=0;j<10;j++ )
            {
            
            archivo<<tab[i][j]<<' '; //escribo lo que quiero al archivo
            }
        archivo<<"\n";

    }
    archivo<<"\n";
    archivo.close();
}

int Soldados1Restantes(char tab[][10],int dimension) //cuenta cuantos soldados le quedan al jugador 1.
{
    int ContadorDeUnos=0;
    for (int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++)
            {
                if (tab[i][j] == '1')
                    {
                    ContadorDeUnos++;    
                    }
            }
    }

    return ContadorDeUnos;
}
int Soldados2Restantes(char tab[][10],int dimension) //cuenta cuantos soldados le quedan al jugador 2.
{
    int ContadorDeDos=0;
    for (int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++)
            {
                if (tab[i][j] == '2')
                    {
                    ContadorDeDos++;    
                    }
            }
    }

    return ContadorDeDos;
}


void Reemplazo(char tab[][10],int dimension) // muestra el tablero, esta funcion es llamada dentro de otras para mostrar sus respectivos cambios
{
    cout<<endl;
	cout<<"   ";
    for (int p=0;p<10;p++)
        {cout<<"["<<p<<"]";}
    cout<<endl;
    for (int i=0;i<dimension;i++){
        cout<<"["<<i<<"] ";
        for(int j=0;j<dimension;j++)
            {
                
                cout<<tab[i][j]<<"  ";
                
            }
        cout<<"\n";
        }
    cout<<endl;

}

void Mover(char tab[][10],char jugador) //funcion que mueve a los soldados, solo se llama si un jugador quiere realizar un moviemiento.
{
    int filaElijoSoldado,columnaElijoSoldado,filaFinal,columnaFinal;
    int resultFila, resultColumna;

    cout<<"Ingrese la fila del soldado que va a mover: ";cin>>filaElijoSoldado;
    cout<<"Ingrese la columna del soldado que va a mover: ";cin>>columnaElijoSoldado;
    while (tab[filaElijoSoldado][columnaElijoSoldado]!=jugador)
        {cout<<"No tienes un soldado en esa posicion!"<<endl;
        cout<<"Ingrese la fila del soldado que va a mover: ";cin>>filaElijoSoldado;
        cout<<"Ingrese la columna del soldado que va a mover: ";cin>>columnaElijoSoldado;}
        
    tab[filaElijoSoldado][columnaElijoSoldado]=' '; //hacer que se cambie donde ya habia un jugador por un blanco
    cout<<endl<<"Ingrese la fila donde va a mover su soldado: ";cin>>filaFinal;
    cout<<"Ingrese la columna donde va a mover su soldado: ";cin>>columnaFinal;
    resultFila = filaFinal - filaElijoSoldado;           // realizo las cuentas para que se validen
    resultColumna = columnaFinal - columnaElijoSoldado; //  los movimientos horizontales, verticales y diagonales
    

    while((filaElijoSoldado != filaFinal && columnaElijoSoldado != columnaFinal) && (abs(resultFila) != abs(resultColumna)) ){ // si no es una casilla que esta horizontal, vertical o diagonal; pide que vuelva a ingresar.
        cout<<endl<<"Posicion Incorrecta"<<endl;
        cout<<"Ingrese la fila donde va a mover su soldado: ";cin>>filaFinal;
        cout<<"Ingrese la columna donde va a mover soldado: ";cin>>columnaFinal;
    }

    
    
        
    if (tab[filaFinal][columnaFinal]=='x') //se encuentra con una casilla inactiva
        {
            cout<<endl<<"Un soldado no puede Moverse a una casilla inactiva."<<endl;
            tab[filaElijoSoldado][columnaElijoSoldado]=jugador;

        }
        
    else
    
        if (tab[filaFinal][columnaFinal]==jugador) //se enceuntra con un aliado
            {
        
                cout<<endl<<"2 soldados aliados no pueden ocupar una casilla."<<endl;
                tab[filaElijoSoldado][columnaElijoSoldado]=jugador;

            }
        else
    
            if ((tab[filaFinal][columnaFinal]!=jugador)&&(tab[filaFinal][columnaFinal]!='*')&&(tab[filaFinal][columnaFinal]!='x')&&(tab[filaFinal][columnaFinal]!=' ')) //se encuentra con un enemigo
                {cout<<endl<<"Su soldado se encontró con un enemigo! AMBOS MUEREN POR CUERPO A CUERPO."<<endl;
                tab[filaFinal][columnaFinal]='x';}
            else
                if (tab[filaFinal][columnaFinal]==' ') // se encuentra con una casilla vacia
                    {cout<<endl<<"Un soldado no puede ocupar una casilla vacia."<<endl;
                    tab[filaElijoSoldado][columnaElijoSoldado]=jugador;
                    }
                else
                    {tab[filaFinal][columnaFinal]=jugador;}

}

void turnoJugador1(char tab[][10]) //turno del jugador 1
{
    int fila, columna;
    char jugador = '1';
    char respuesta;
    
    cout<<"Jugador 1 ingrese que fila va a atacar: ";cin>>fila;
    cout<<"Jugador 1 ingrese que columna va a atacar: ";cin>>columna;
    
    while (tab[fila][columna]=='1')
        {   
            cout<<endl<<"No! no atacamos aliados! vuelve a ingresar."<<endl;
            cout<<endl<<"Jugador 1 ingrese que fila va a atacar: ";cin>>fila;
            cout<<"Jugador 1 ingrese que columna va a atacar: ";cin>>columna;
        }
    
    if (tab[fila][columna]=='*')
        {
            tab[fila][columna]=' ';
                
            cout<<endl<<"Casilla vacia!"<<endl;
            }
        else{
            if (tab[fila][columna]=='x')
                cout<<endl<<"Casilla inactiva!"<<endl;
            else
                if (tab[fila][columna]==' ')
                    {cout<<endl<<"Esa casilla ya no se encuentra en el tablero!"<<endl;}
        }
    if (tab[fila][columna]=='2')
        {
            tab[fila][columna]='x';
                
            cout<<endl<<"Eliminaste a un soldado enemigo!"<<endl;
            cout<<"Quiere Mover un soldado? (s/n): ";cin>>respuesta;
        if (respuesta == 's')
            
                Mover(tab,jugador);
                
            }
	cout<<endl;
    Reemplazo(tab,10);

}
void turnoJugador2(char tab[][10]) //turno del jugador 2
    {
    char jugador = '2'; 
    int fila, columna;
    char respuesta;
    
    cout<<"Jugador 2 ingrese que fila va a atacar: ";cin>>fila;
    cout<<"Jugador 2 ingrese que columna va a atacar: ";cin>>columna;
    
    while (tab[fila][columna]=='2')
        {   
            cout<<endl<<"No! no atacamos aliados! vuelve a ingresar."<<endl;
            cout<<endl<<"Jugador 2 ingrese que fila va a atacar: ";cin>>fila;
            cout<<"Jugador 2 ingrese que columna va a atacar: ";cin>>columna;
        }
        
        if (tab[fila][columna]=='*')
            {
                tab[fila][columna]=' ';
               
                cout<<endl<<"Casilla vacia!"<<endl;
                }
        else{
            if (tab[fila][columna]=='x')
                cout<<endl<<"Casilla inactiva!"<<endl;
            else
                if (tab[fila][columna]==' ')
                    {cout<<endl<<"Esa casilla ya no se encuentra en el tablero!"<<endl;}
    }
    if (tab[fila][columna]=='1')
        {
            tab[fila][columna]='x';
                
            cout<<endl<<"Eliminaste a un soldado enemigo!"<<endl;
            cout<<"Quiere Mover un soldado? (s/n): ";cin>>respuesta;  //La opcion de mover un soldado se presenta solo si el jugador abatió a un rival
        if (respuesta == 's')
        
            Mover(tab,jugador); // mueve solamente si el jugador quiere hacerlo
                
        }
        
        

    cout<<endl;
    Reemplazo(tab,10); //muestro el tablero con las nuevas modificaciones
}




void soldadosInicialesJugadores1y2(char tab[][10])
{
    
    int fila, columna;
    string posicion;
    cout<<"Jugador 1 ingrese sus 3 solados iniciales."<<endl;
    for (int i=0;i<3;i++) ///ingresa los 3 soldados iniciales jugador_1
       
        {
            cout<<"Ingrese la fila donde va su soldado "<<i+1<<" : ";cin>>fila;
            cout<<"Ingrese la columna donde va su soldado "<<i+1<<": ";cin>>columna;
            while (tab[fila][columna]=='1')
            {
            cout<<endl<<"YA TIENES UN SOLDADO EN ESA POSICION! Vuelve a ingresar."<<endl;
            cout<<endl<<"Ingrese la fila donde va su soldado "<<i+1<<" : ";cin>>fila;
            cout<<"Ingrese la columna donde va su soldado "<<i+1<<": ";cin>>columna;
            }
            tab[fila][columna]='1';
            
        }
    
    cout<<endl<<"Jugador 2 ingrese sus 3 solados iniciales."<<endl;
    for (int i=0;i<3;i++) ///ingresa los 3 soldados iniciales jugador_2
       
        {
            cout<<"Ingrese la fila donde va su soldado "<<i+1<<" : ";cin>>fila;
            cout<<"Ingrese la fila donde va su soldado "<<i+1<<": ";cin>>columna;
            while (tab[fila][columna] == '2')
            {
            cout<<endl<<"YA TIENES UN SOLDADO EN ESA POSICION! Vuelve a ingresar."<<endl;
            cout<<endl<<"Ingrese la fila donde va su soldado "<<i+1<<" : ";cin>>fila;
            cout<<"Ingrese la columna donde va su soldado "<<i+1<<": ";cin>>columna;
            }
            if (tab[fila][columna]=='1')
                {
                    cout<<endl<<"Tu soldado se encontró con un enemigo! Ambos mueren para no otorgar ventajas!"<<endl;
                    tab[fila][columna]='x';

                }
            else    
                if (tab[fila][columna]=='*')
                    {tab[fila][columna]='2';}
            
        }
    
    Reemplazo(tab,10); //muestro el tablero con las nuevas modificaciones
   
}



int main()
{
    
    const int dimension = 10;
	int ronda = 1;
    char tablero[dimension][dimension]; 
    cout<<"                                      "<<"!COMIENZA EL JUEGO BATALLA CAMPAL!" <<endl<<endl;
    cout<<"   ";
    for (int p=0;p<10;p++)
        {cout<<"["<<p<<"]";}
    cout<<endl;
    for (int i=0;i<dimension;i++){     //muestra el tablero inicial vacio.
        cout<<"["<<i<<"] ";
        for(int j=0;j<dimension;j++)
            {
                tablero[i][j]='*';
                cout<<tablero[i][j]<<"  ";
     
            }

        cout<<"\n";  
            
    }
	cout<<endl;
    soldadosInicialesJugadores1y2(tablero); // se realizan los ingresos principales antes de que comienze el juego
    Escribir(tablero,ronda); // escribe en el archivo el tablero con los 3 ingresos principales

    

    
    while ((Soldados1Restantes(tablero,dimension)>0) && (Soldados2Restantes(tablero,dimension)>0)) // Condicion de Fin : El juego seguirá hasta que alguno se quede sin soldados
            {
                turnoJugador1(tablero);
                ronda++;
                Escribir(tablero,ronda);
                if (Soldados2Restantes(tablero,dimension) > 0)
                    {
                    turnoJugador2(tablero);
                    ronda++;
                    Escribir(tablero,ronda);
                    }
            }
    if (Soldados1Restantes(tablero,dimension) == 0 && Soldados2Restantes(tablero,dimension) == 0) //si ambos se quedan sin soldados, empatan
        cout<<"EMPATE!"<<endl;
    else
    
        if (Soldados1Restantes(tablero,dimension)==0)
            {cout<<"GANO EL JUGADOR 2!!"<<endl;}
        else{    
            if (Soldados2Restantes(tablero,dimension)==0)
               { cout<<"GANO EL JUGADOR 1!!"<<endl;}
    }
    



    return 0;
}
