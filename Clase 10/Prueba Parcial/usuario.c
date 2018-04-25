#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"

int user_crear(Usuario * arrayDeUsuarios, int sizeArray)
{
    int i = 0;
    for(i = 0; i < sizeArray; i++)
    {
        arrayDeUsuarios[i].isEmpty = 1;
    }
}

int user_buscarLibre(Usuario * arrayDeUsuarios, int sizeArray)
{
    int i;
    for(i = 0; i < sizeArray; i++)
    {
        if(arrayDeUsuarios[i].isEmpty == 1)
        {
            printf("La posicion %d esta libre para usarse.\n", i);
        }
    }

}

int user_alta(Usuario * arrayDeUsuarios, int sizeArray)
{
    int i;
    int j;
    for(i = 0; i < sizeArray; i++)
    {
        if(arrayDeUsuarios[i].isEmpty == 1)
        {
            printf("Ingrese el nombre del empleado.\n");
            fflush(stdin);
            gets(arrayDeUsuarios[i].nombre);
            printf("Ingrese el apellido del empleado.\n");
            fflush(stdin);
            gets(arrayDeUsuarios[i].apellido);
            arrayDeUsuarios[i].usuarioId = i;
            arrayDeUsuarios[i].isEmpty = 0;
            break;
        }
        else{
            while(arrayDeUsuarios[i].isEmpty == 0)
            {
                break;
            }
        }
    }
}

int user_mostrar(Usuario * arrayDeUsuarios,int sizeArray)
{
    int i;
    for(i = 0; i < sizeArray; i++)
    {
        if(arrayDeUsuarios[i].isEmpty == 0)
        {
             printf("El empleado se llama %s %s, con ID %d\n", arrayDeUsuarios[i].nombre, arrayDeUsuarios[i].apellido, arrayDeUsuarios[i].usuarioId);
        }
    }
}


int user_baja(Usuario * arrayDeUsuarios, int sizeArray, int * usuarioId)
{
    int aux;
    aux = *usuarioId;

    printf("A quien desea dar de baja?\n");
    scanf("%d", &aux);
    if(aux > sizeArray)
        {
            printf("Ese numero supera la dimmension de la lista. Intente de nuevo.\n");
            printf("A quien desea dar de baja?\n");
            scanf("%d", &aux);
        }
    while(arrayDeUsuarios[aux].isEmpty == 1)
        {
            printf("Ese usuario ya esta vacio. Intente de nuevo.\n");
            printf("A quien desea dar de baja?\n");
            scanf("%d", &aux);
        }
    if(aux < sizeArray && arrayDeUsuarios[aux].isEmpty == 0)
    {
        arrayDeUsuarios[aux].isEmpty = 1;
        printf("Se dio de baja a %s %s, con el ID %d.\n", arrayDeUsuarios[aux].nombre, arrayDeUsuarios[aux].apellido, arrayDeUsuarios[aux].usuarioId);
    }


}

