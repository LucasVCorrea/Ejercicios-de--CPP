#include <iostream>
using namespace std;

int main()
{
    int listaLargo,contador,salarioMayor=0,salarioMenor=0,posicionMayor,posicionMenor;
    cout<<"Ingrese de cuanto es la lista de empleados: ";cin>>listaLargo;
    
    int salarioEmpleado[listaLargo];
    string nombreEmpleado[listaLargo];
    
    for (int i=0;i<listaLargo;i++)
    {
        cout<<"Ingrese el apellido del empleado "<<i+1<<": ";cin>>nombreEmpleado[i];
        cout<<"Ingrese el salario de "<<nombreEmpleado[i]<<": ";cin>>salarioEmpleado[i];
        
    }
    salarioMayor=salarioEmpleado[0];
    salarioMenor=salarioEmpleado[0];
    cout<<endl;
    for (int i=0;i<listaLargo;i++)
    {
        cout<<nombreEmpleado[i]<<" - $"<< salarioEmpleado[i]<<endl;
        if (salarioEmpleado[i]<salarioMenor)
        {
            salarioMenor = salarioEmpleado[i];
            posicionMenor = i;
        }
        else
            if (salarioEmpleado[i]>salarioMayor)
            {
                salarioMayor = salarioEmpleado[i];
                posicionMayor = i;
            }
    }
    cout<<endl<<"Mayor: "<<nombreEmpleado[posicionMayor]<<" - $"<<salarioMayor<<endl;
    cout<<"Menor: "<<nombreEmpleado[posicionMenor]<<" - $"<<salarioMenor<<endl;
    return 0;
}
