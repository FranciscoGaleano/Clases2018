#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int per_crear(Persona * arrayDePersonas, int sizeArray)
{
    int retorno = -1;
    int i = 0;
    for(i = 0; i < sizeArray; i++)
    {
        arrayDePersonas[i].estado = 1;
        retorno = 0;
    }
    return retorno;
}

int per_buscarLibre(Persona * arrayDePersonas, int sizeArray)
{
    int retorno = -1;
    int i;
    for(i = 0; i < sizeArray; i++)
    {
        if(arrayDePersonas[i].estado == 1)
        {
            printf("La posicion %d esta libre para usarse.\n", i);
            retorno = 0;
        }
    }
    return retorno;
}

int per_alta(Persona * arrayDePersonas, int sizeArray)
{
    int retorno = -1;
    int i;
    for(i = 0; i < sizeArray; i++)
    {
        if(arrayDePersonas[i].estado == 1)
        {
            printf("Ingrese el nombre de la persona.\n");
            fflush(stdin);
            gets(arrayDePersonas[i].nombre);
            printf("Ingrese la edad de la persona.\n");
            fflush(stdin);
            scanf("%d", &arrayDePersonas[i].edad);
            printf("Ingrese el DNI de la persona.\n");
            fflush(stdin);
            scanf("%d", &arrayDePersonas[i].dni);
            arrayDePersonas[i].estado = 0;
            retorno = 0;
            break;
        }
        else{
            while(arrayDePersonas[i].estado == 0)
            {
                break;
            }
        }
    }
    return retorno;
}

int per_mostrar(Persona * arrayDePersonas,int sizeArray)
{
    int retorno = -1;
    int i;
    for(i = 0; i < sizeArray; i++)
    {
        if(arrayDePersonas[i].estado == 0)
        {
             printf("Nombre: %s Edad: %d DNI: %d Ubicacion: %d\n", arrayDePersonas[i].nombre, arrayDePersonas[i].edad, arrayDePersonas[i].dni, i);
             retorno = 0;
        }
    }
    return retorno;
}

int per_baja(Persona * arrayDePersonas, int sizeArray, int * personaIndice)
{
    int retorno = -1;
    int aux;
    aux = *personaIndice;

    printf("A quien desea dar de baja?\n");
    scanf("%d", &aux);
    while(arrayDePersonas[aux].estado == 1)
        {
            printf("Ese usuario ya esta vacio. Intente de nuevo.\n");
            printf("A quien desea dar de baja?\n");
            scanf("%d", &aux);
        }
    if(arrayDePersonas[aux].estado == 0)
    {
        arrayDePersonas[aux].estado = 1;
        printf("Nombre: %s Edad: %d DNI: %d HA SIDO DADO DE BAJA--\n", arrayDePersonas[aux].nombre, arrayDePersonas[aux].edad, arrayDePersonas[aux].dni);
        retorno = 0;
    }

    return retorno;
}

int per_graficar(Persona * arrayDePersonas, int sizeArray)
{
    int retorno = -1;
    int i;
    int mayoresContador;
    int mediosContador;
    int menoresContador;

    for(i = 0; i < sizeArray-1; i++)
    {
        if(arrayDePersonas[i].edad < 19)
        {
            menoresContador++;
        }
        else if(arrayDePersonas[i].edad > 18 && arrayDePersonas[i].edad < 36)
        {
            mediosContador++;
        }
        else
        {
            mayoresContador++;
        }
    }

    printf("%d %d %d\n", menoresContador, mediosContador, mayoresContador);


    /*for(i = 0; i < sizeArray; i++)
    {
        if(arrayDePersonas[i].edad < 19 && !(arrayDePersonas[i+1].edad > 18 && arrayDePersonas[i].edad < 36) && !(arrayDePersonas[i+2].edad > 35))
        {
            printf(" *\n");
        }
        else if(arrayDePersonas[i].edad < 19 && (arrayDePersonas[i+1].edad > 18 && arrayDePersonas[i].edad < 36) && !(arrayDePersonas[i+2].edad > 35))
        {
            printf(" *     *\n");
        }
        else if(arrayDePersonas[i].edad < 19 && (arrayDePersonas[i+1].edad > 18 && arrayDePersonas[i].edad < 36) && arrayDePersonas[i+2].edad > 35)
        {
            printf(" *     *      *\n");
        }
        else if((!arrayDePersonas[i].edad < 19) && (arrayDePersonas[i+1].edad > 18 && arrayDePersonas[i].edad < 36) && !(arrayDePersonas[i+2].edad > 35))
        {
           printf("       *\n");
        }
        else if(!(arrayDePersonas[i].edad < 19) && (arrayDePersonas[i+1].edad > 18 && arrayDePersonas[i].edad < 36) && arrayDePersonas[i+2].edad > 35)
        {
            printf("       *      *\n");
        }
        else if(!(arrayDePersonas[i].edad < 19) && !(arrayDePersonas[i+1].edad > 18 && arrayDePersonas[i].edad < 36) && arrayDePersonas[i+2].edad > 35)
        {
           printf("              *\n");
        }




        else if(arrayDePersonas[i].edad > 18 && arrayDePersonas[i].edad < 36)
        {
            printf("       *\n");

        }
        else if(arrayDePersonas[i].edad > 35)
        {
            printf("             *\n");
        }

        retorno = 0;
    }*/
    printf("<18  19-35  >35\n");













    return retorno;


}
