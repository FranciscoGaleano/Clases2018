#include "empleados.h"
#include <stdio.h>
#include <stdlib.h>

int emp_init(Empleado * arrayEmpleados,int sizeArray)
{
    int i = 0;
    for(i = 0; i < sizeArray; i++)
    {
        arrayEmpleados[i].isEmpty = 1;
    }

}

int buscarLibre(Empleado * arrayEmpleados,int sizeArray)
{
    int i;
    for(i = 0; i < sizeArray; i++)
    {
        if(arrayEmpleados[i].isEmpty == 1)
        {
            printf("La posicion %d esta libre y se puede usar.\n", i);
        }
    }
}

int emp_alta(Empleado * arrayEmpleados,int sizeArray,int id)
{

    int i;
    int j;
    for(i = 0; i < sizeArray; i++)
    {
        if(arrayEmpleados[i].isEmpty == 1)
        {
            printf("Ingrese el nombre del empleado.\n");
            fflush(stdin);
            gets(arrayEmpleados[i].nombre);
            printf("Ingrese el apellido del empleado.\n");
            fflush(stdin);
            gets(arrayEmpleados[i].apellido);
            arrayEmpleados[i].idEmpleado = i + 10;
            arrayEmpleados[i].isEmpty = 0;
            break;
        }
        else{
            arrayEmpleados[i] = arrayEmpleados[i+1];
            arrayEmpleados[i+1] = arrayEmpleados[j];
            printf("Ingrese el nombre del empleado.\n");
            fflush(stdin);
            gets(arrayEmpleados[j].nombre);
            printf("Ingrese el apellido del empleado.\n");
            fflush(stdin);
            gets(arrayEmpleados[j].apellido);
            arrayEmpleados[j].idEmpleado = j + 10;
            arrayEmpleados[j].isEmpty = 0;
            break;
        }
    }
}

int emp_mostrar(Empleado * arrayEmpleados,int sizeArray)
{
    int i;
    for(i = 0; i < sizeArray; i++)
    {
        if(arrayEmpleados[i].isEmpty == 0)
        {
             printf("El empleado se llama %s %s, con ID %d\n", arrayEmpleados[i].nombre, arrayEmpleados[i].apellido, arrayEmpleados[i].idEmpleado);
             continue;
        }
    }
}


int emp_baja(Empleado * arrayEmpleados,int sizeArray,int id)
{
    int i;
    char eliminar;
    for(i = 0; i < sizeArray; i++)
    {
        if(arrayEmpleados[i].isEmpty == 0)
        {
            printf("Desea dar de baja al empleado %d? S/N\n", arrayEmpleados[i].idEmpleado);
            fflush(stdin);
            scanf("%c", &eliminar);
            if(eliminar == 's')
            {
                arrayEmpleados[i].isEmpty = 1;
            }
            else{
                arrayEmpleados[i].isEmpty = 0;
            }
        }



        /*do
        {
            printf("Desea dar de baja al empleado %d? S/N\n", arrayEmpleados[i].idEmpleado);
            scanf("%c", &eliminar);

        }while(arrayEmpleados[i].isEmpty == 0 && eliminar == 's');
        arrayEmpleados[i].isEmpty = 1;*/
    }


}
