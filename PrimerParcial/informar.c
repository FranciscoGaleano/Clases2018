#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "avisos.h"
#include "clientes.h"

int informar_listarClientes(Cliente * arrayDeClientes, int limiteC, Aviso * arrayDeAvisos, int limiteA)
{
    int retorno = -1;
    int i;
    int contadorAvisos = 0;

    if(limiteA > 0 && arrayDeAvisos != NULL)
    {
        for(i = 0; i < limiteA; i++)
        {
            if(arrayDeAvisos[i].isEmpty == 0 && arrayDeAvisos[i].estado == 1)
            {
                if((arrayDeAvisos[i].idCliente == arrayDeAvisos[i+1].idCliente))
                {
                    contadorAvisos++;
                    printf("NOMBRE: %s - APELLIDO: %s - CUIT: %s - AVISOS: %d\n", arrayDeClientes[i].nombre,
                           arrayDeClientes[i].apellido, arrayDeClientes[i].cuit, contadorAvisos);
                           retorno = 0;
                }
            }
        }
        printf("Hay %d avisos activos\n", contadorAvisos);
        /*for(i = 0; i < limiteA; i++)
        {
            if(arrayDeAvisos[i].isEmpty == 0 && arrayDeAvisos[i].estado == 1)
            {
                printf("NOMBRE: %s - APELLIDO: %s - CUIT: %s - AVISOS: %d\n", arrayDeClientes[i].nombre,
                       arrayDeClientes[i].apellido, arrayDeClientes[i].cuit, contadorAvisos);
            }
        }
        printf("NOMBRE: %s - APELLIDO: %s - CUIT: %s - AVISOS: %d\n", arrayDeClientes[i].nombre,
                       arrayDeClientes[i].apellido, arrayDeClientes[i].cuit, contadorAvisos);*/

    }

    return retorno;
}
