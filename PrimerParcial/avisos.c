#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "avisos.h"
#include "clientes.h"


int avi_crear(Aviso * arrayDeAvisos, int sizeArray)
{
    int retorno = -1;
    int i = 0;
    if(sizeArray > 0 && arrayDeAvisos != NULL)
    {
        for(i = 0; i < sizeArray; i++)
        {
            arrayDeAvisos[i].isEmpty = 1;
            retorno = 0;
        }
    }
    return retorno;
}



int avi_mostrar(Aviso * arrayDeAvisos, int sizeArray)
{
    int retorno = -1;
    int i;
    if(sizeArray > 0 && arrayDeAvisos != NULL)
    {
        for(i = 0; i < sizeArray; i++)
        {
            if(arrayDeAvisos[i].isEmpty == 0)
            {
                 printf("TEXTO: %s - RUBRO: %d -  ID: %d\n", arrayDeAvisos[i].texto,
                        arrayDeAvisos[i].rubro, i);
                        retorno = 0;
            }
        }
    }
    return retorno;
}


int avi_baja(Aviso * arrayDeAvisos, int sizeArray, int * AvisoId)
{
    int retorno = -1;
    int aux;
    aux = *AvisoId;

    printf("Que aviso quiere dar de baja?\n");
    scanf("%d", &aux);
    if(sizeArray > 0 && arrayDeAvisos != NULL)
    {
        if(aux > sizeArray)
            {
                printf("Ese numero supera la dimmension de la lista. Intente de nuevo.\n");
                printf("Que aviso quiere dar de baja?\n");
                scanf("%d", &aux);
            }
        while(arrayDeAvisos[aux].isEmpty == 1)
            {
                printf("Ese aviso ya esta vacio. Intente de nuevo.\n");
                printf("Que aviso desea dar de baja?\n");
                scanf("%d", &aux);
            }
        if(aux < sizeArray && arrayDeAvisos[aux].isEmpty == 0)
            {
                arrayDeAvisos[aux].isEmpty = 1;
                printf("Se dio de baja el aviso con el ID %d, del rubro %d con el texto %s.\n", arrayDeAvisos[aux].idAviso,
                       arrayDeAvisos[aux].rubro, arrayDeAvisos[aux].texto);
                       retorno = 0;
            }
    }
        return retorno;
}

/*int avi_modificar(Aviso * arrayDeAvisos, int sizeArray)
{
    int retorno = -1;
    int aux;
    char respuesta = 's';
    int menu;
    int mostrar;
    if(sizeArray > 0 && arrayDeAvisos != NULL)
    {
        mostrar = avi_mostrar(arrayDeAvisos, sizeArray);
        printf("Ingrese el ID del aviso a modificar.\n");
        scanf("%d", &aux);
        while(aux > sizeArray || arrayDeAvisos[aux].isEmpty == 1)
        {
            printf("Ingrese un ID valido.\n");
            scanf("%d", &aux);
        }

        do
        {
            printf("Que desea modificar?\n");
            printf("Pausar un aviso      -> Ingrese 1\n");
            printf("Reanudar un aviso    -> Ingrese 2\n");
            scanf("%d", &menu);
            switch(menu)
            {
                case 1:
                    if(arrayDeAvisos[aux].estado == 1)
                    {
                        arrayDeAvisos[aux].estado = 0;
                    }
                    else{
                        printf("Ese aviso ya esta pausado.\n");
                    }
                    //printf("Desea continuar? S/N\n");
                    //scanf("%c", &respuesta);
                    break;
                case 2:
                    if(arrayDeAvisos[aux].estado == 0)
                    {
                        arrayDeAvisos[aux].estado = 1;
                    }
                    else{
                        printf("Ese aviso ya fue reanudado.\n");
                    }
                    //printf("Desea continuar? S/N\n");
                    //scanf("%c", &respuesta);
                    break;
                default:
                    printf("Ingrese una opcion valida.\n");
                    break;
            }

        }while(respuesta == 's');
    retorno = 0;
    }
    return retorno;
}*/

int avi_alta(Aviso * arrayDeAvisos, int sizeArray, Cliente * arrayDeClientes, int sizeCliente)
{
    int retorno = -1;
    int i;
    int aux;
    int mostrar;
    if(sizeArray > 0 && arrayDeAvisos != NULL && sizeCliente > 0 && arrayDeClientes != NULL)
    {
        mostrar = clte_mostrar(arrayDeClientes, sizeCliente);
        printf("Ingrese el ID del cliente.\n");
        scanf("%d", &aux);
        if(arrayDeClientes[aux].isEmpty == 0)
        {
            for(i = 0; i < sizeArray; i++)
            {
                if(arrayDeAvisos[i].isEmpty == 1)
                {
                    do
                    {
                        printf("Ingrese el rubro del aviso. [1/2/3/4]\n");
                        scanf("%d", &arrayDeAvisos[i].rubro);
                    }while(arrayDeAvisos[i].rubro != 1 && arrayDeAvisos[i].rubro != 2 && arrayDeAvisos[i].rubro != 3 && arrayDeAvisos[aux].rubro != 4);
                    printf("Ingrese el texto del aviso.\n");
                    fflush(stdin);
                    gets(arrayDeAvisos[i].texto);
                    arrayDeAvisos[i].isEmpty = 0;
                    arrayDeAvisos[i].estado = 1;
                    arrayDeAvisos[i].idAviso = i;
                    break;
                }
                else if(arrayDeAvisos[i+1].isEmpty == 1)
                {
                    continue;
                }
            }
            retorno = 0;
        }
        return retorno;
    }
}

int avi_pausarPublicacion(Aviso * arrayDeAvisos, int sizeArray, Cliente * arrayDeClientes, int sizeCliente)
{
    int retorno = -1;
    int aux;
    char respuesta;
    int mostrar;

    if(sizeArray > 0 && arrayDeAvisos != NULL && sizeCliente > 0 && arrayDeClientes != NULL)
    {
        mostrar = avi_mostrar(arrayDeAvisos, sizeArray);
        printf("Ingrese el ID del aviso a pausar.\n");
        scanf("%d", &aux);
        if(arrayDeAvisos[aux].estado == 1)
        {
            printf("Datos del propietario del aviso:\n");
            printf("NOMBRE: %s - APELLIDO: %s - CUIT: %s\n", arrayDeClientes[aux].nombre,
                   arrayDeClientes[aux].apellido, arrayDeClientes[aux].cuit);
            printf("Desea pausar este aviso? S/N\n");
            fflush(stdin);
            scanf("%c", &respuesta);
            if(respuesta == 's')
            {
                arrayDeAvisos[aux].estado = 0;
                printf("El aviso elegido fue pausado.\n");
            }
            else
            {
                printf("El aviso no fue pausado.\n");
            }
        }
        else
        {
            printf("No existen avisos publicados para pausar.\n");
        }
        retorno = 0;
    }
    return retorno;
}

int avi_reanudarPublicacion(Aviso * arrayDeAvisos, int sizeArray, Cliente * arrayDeClientes, int sizeCliente)
{
    int retorno = -1;
    int aux;
    int i;
    int flag = 0;
    char respuesta = 's';

    if(sizeArray > 0 && arrayDeAvisos != NULL && sizeCliente > 0 && arrayDeClientes != NULL)
    {
        do
        {
            for(i = 0; i < sizeArray; i++)
            {
                if(arrayDeAvisos[i].isEmpty == 0 && arrayDeAvisos[i].estado == 0)
                {
                    printf("Los avisos pausados son los siguientes:\n");
                    printf("TEXTO: %s - RUBRO: %d - ID: %d\n", arrayDeAvisos[i].texto, arrayDeAvisos[i].rubro, arrayDeAvisos[i].idAviso);
                    flag = 1;
                }
                else if(arrayDeAvisos[i].isEmpty == 0 && arrayDeAvisos[i].estado == 1)
                {
                    printf("No existen avisos pausados a reanudar.\n");
                    flag = 2;
                    retorno = 0;
                }
            }
        }while(flag == 0);
        if(flag == 1)
        {
            printf("Ingrese el ID del aviso a reanudar.\n");
            scanf("%d", &aux);
            if(arrayDeAvisos[aux].estado == 0)
            {
                printf("Datos del propietario del aviso:\n");
                printf("NOMBRE: %s - APELLIDO: %s - CUIT: %s\n", arrayDeClientes[aux].nombre,
                       arrayDeClientes[aux].apellido, arrayDeClientes[aux].cuit);
                printf("Desea reanudar este aviso? S/N\n");
                fflush(stdin);
                scanf("%c", &respuesta);
                if(respuesta == 's')
                {
                    arrayDeAvisos[aux].estado = 1;
                    printf("El aviso elegido fue reanudado.\n");
                    retorno = 0;
                    flag = 0;
                }
                else
                {
                    printf("El aviso no fue reanudado.\n");
                    flag = 0;
                }
            }
        }
    }
    return retorno;
}
