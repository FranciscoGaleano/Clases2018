#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "avisos.h"
#include "clientes.h"
#include "informar.h"



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



int avi_mostrarActivos(Aviso * arrayDeAvisos, int sizeArray)
{
    int retorno = -1;
    int i;
    if(sizeArray > 0 && arrayDeAvisos != NULL)
    {
        for(i = 0; i < sizeArray; i++)
        {
            if(arrayDeAvisos[i].isEmpty == 0 && arrayDeAvisos[i].estado == 1)
            {
                 printf("TEXTO: %s - RUBRO: %d -  ID: %d\n", arrayDeAvisos[i].texto,
                        arrayDeAvisos[i].rubro, i);
                        retorno = 0;
            }
        }
    }
    return retorno;
}

int avi_mostrarPausados(Aviso * arrayDeAvisos, int sizeArray)
{
    int retorno = -1;
    int i;
    if(sizeArray > 0 && arrayDeAvisos != NULL)
    {
        for(i = 0; i < sizeArray; i++)
        {
            if(arrayDeAvisos[i].isEmpty == 0 && arrayDeAvisos[i].estado == 0)
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

int avi_pausarPublicacion(Aviso * arrayDeAvisos, int sizeArray, Cliente * arrayDeClientes, int sizeCliente)
{
    int retorno = -1;
    int aux;
    int flag = 1;
    char respuesta;
    int mostrar;

    if(sizeArray > 0 && arrayDeAvisos != NULL && sizeCliente > 0 && arrayDeClientes != NULL)
    {
        mostrar = avi_mostrarActivos(arrayDeAvisos, sizeArray);
        if(flag == 1)
        {
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
                    flag = 0;
                }
                else
                {
                    printf("El aviso no fue pausado.\n");
                    flag = 0;
                }
            }
            else
            {
                printf("No existen avisos publicados para pausar.\n");
                flag = 0;
            }

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
    int mostrarPausados;
    int flag = 1;
    char respuesta = 's';

    if(sizeArray > 0 && arrayDeAvisos != NULL && sizeCliente > 0 && arrayDeClientes != NULL)
    {
        printf("Los avisos pausados son los siguientes:\n");
        mostrarPausados = avi_mostrarPausados(arrayDeAvisos, sizeArray);
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

int avi_buscarAvisosPorId(Aviso * arrayDeAvisos , int sizeArray, int *idCliente)
{
    int i;
    int contadorPublicaciones = 0;
    //int auxiliar = idCliente;
    if(sizeArray > 0 && arrayDeAvisos != NULL)
    {

        for(i = 0; i < sizeArray; i++)
        {
            if(arrayDeAvisos[i].isEmpty == 0 && arrayDeAvisos[i].idCliente == *idCliente)
            {
               contadorPublicaciones++;
            }
            else if(arrayDeAvisos[i].isEmpty == 0 && arrayDeAvisos[i].idCliente != *idCliente)
            {
                continue;
            }

        }
    }
    return contadorPublicaciones;
}

int avi_alta(Aviso * arrayDeAvisos, int sizeArray, Cliente * arrayDeClientes, int sizeCliente)
{
    int retorno = -1;
    int mostrar;
    int i;
    int id;
    int aux;
    int indice;

    if(sizeArray > 0 && arrayDeAvisos != NULL && sizeCliente > 0 && arrayDeClientes != NULL)
    {
        mostrar = clte_mostrar(arrayDeClientes, sizeCliente);
        printf("Ingrese el ID del cliente.\n");
        scanf("%d", &id);
        indice = clte_obtenerID(arrayDeClientes, sizeCliente, id);
        if(arrayDeClientes[indice].idCliente == indice)
        {
            for(i = 0; i < sizeArray; i++)
            {
                if(arrayDeAvisos[i].isEmpty == 1)
                {
                    do
                    {
                        printf("Ingrese el rubro del aviso. [1/2/3/4]\n");
                        scanf("%d", &aux);
                    }while(aux != 1 && aux != 2 && aux != 3 && aux != 4);
                    printf("Ingrese el texto del aviso.\n");
                    fflush(stdin);
                    gets(arrayDeAvisos[i].texto);
                    arrayDeAvisos[i].isEmpty = 0;
                    arrayDeAvisos[i].estado = 1;
                    arrayDeAvisos[i].idAviso = i;
                    arrayDeAvisos[i].idCliente = indice;
                    retorno = 0;
                    break;
                }
                else
                {
                    continue;
                }
            }
        }
        else
        {
            printf("Ese ID no pertenece a un cliente existente.\n");
        }
    return retorno;
    }
}


