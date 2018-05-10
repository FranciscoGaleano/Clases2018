#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"

int user_crear(Usuario * arrayDeUsuarios, int sizeArray)
{
    int retorno = -1;
    int i = 0;
    if(sizeArray > 0 && arrayDeUsuarios != NULL)
    {
        for(i = 0; i < sizeArray; i++)
        {
            arrayDeUsuarios[i].isEmpty = 1;
            retorno = 0;
        }
    }
    return retorno;
}

int user_buscarLibre(Usuario * arrayDeUsuarios, int sizeArray)
{
    int retorno = -1;
    int i;
    if(sizeArray > 0 && arrayDeUsuarios != NULL)
    {
        for(i = 0; i < sizeArray; i++)
        {
            if(arrayDeUsuarios[i].isEmpty == 1)
            {
                printf("La posicion %d esta libre para usarse.\n", i);
                retorno = 0;
            }
        }
    }
    return retorno;

}

int user_alta(Usuario * arrayDeUsuarios, int sizeArray)
{
    int retorno = -1;
    int i;
    if(sizeArray > 0 && arrayDeUsuarios != NULL)
    {
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
                retorno = 0;
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
    return retorno;
}

int user_mostrar(Usuario * arrayDeUsuarios,int sizeArray)
{
    int retorno = -1;
    int i;
    if(sizeArray > 0 && arrayDeUsuarios != NULL)
    {
        for(i = 0; i < sizeArray; i++)
        {
            if(arrayDeUsuarios[i].isEmpty == 0)
            {
                 printf("El empleado se llama %s %s, con ID %d\n", arrayDeUsuarios[i].nombre,
                        arrayDeUsuarios[i].apellido, arrayDeUsuarios[i].usuarioId);
                        retorno = 0;
            }
        }
    }
    return retorno;
}


int user_baja(Usuario * arrayDeUsuarios, int sizeArray, int * usuarioId)
{
    int retorno = -1;
    int aux;
    aux = *usuarioId;

    printf("A quien desea dar de baja?\n");
    scanf("%d", &aux);
    if(sizeArray > 0 && arrayDeUsuarios != NULL)
    {
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
                printf("Se dio de baja a %s %s, con el ID %d.\n", arrayDeUsuarios[aux].nombre,
                       arrayDeUsuarios[aux].apellido, arrayDeUsuarios[aux].usuarioId);
                       retorno = 0;
            }
    }
        return retorno;
}

int user_modificar(Usuario * arrayDeUsuarios, int sizeArray)
{
    int retorno = -1;
    int aux;
    char respuesta = 's';
    int menu;
    int mostrar;
    int i;
    if(sizeArray > 0 && arrayDeUsuarios != NULL)
    {
        for(i = 0; i < sizeArray-1; i++)
        {
            if(arrayDeUsuarios[i].isEmpty == 0)
            {
                mostrar = user_mostrar(arrayDeUsuarios, sizeArray);
            }
        }
        printf("Ingrese el ID del usuario a modificar.\n");
        scanf("%d", &aux);
        while(aux > sizeArray || arrayDeUsuarios[aux].isEmpty == 1)
        {
            printf("Ingrese un ID valido.\n");
            scanf("%d", &aux);
        }

        do
        {
            printf("Que desea modificar?\n");
            printf("Nombre      -> Ingrese 1\n");
            printf("Apellido    -> Ingrese 2\n");
            scanf("%d", &menu);
            switch(menu)
            {
                case 1:
                    printf("Ingrese el nuevo nombre.\n");
                    fflush(stdin);
                    gets(arrayDeUsuarios[aux].nombre);
                    printf("Desea continuar? S/N\n");
                    scanf("%c", &respuesta);
                    break;
                case 2:
                    printf("Ingrese el nuevo apellido.\n");
                    fflush(stdin);
                    gets(arrayDeUsuarios[aux].apellido);
                    printf("Desea continuar? S/N\n");
                    scanf("%c", &respuesta);
                    break;
                default:
                    printf("Ingrese una opcion valida.\n");
                    break;
            }
        }while(respuesta == 's');

    }

    return retorno;
}

