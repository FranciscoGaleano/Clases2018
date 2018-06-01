#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "cliente.h"


int parserEmployee(char* path, ArrayList* pArrayListEmployee)
{
    int retorno = -1;
    char nombreB[4096];
    char apellidoB[4096];
    char emailB[4096];
    char generoB[4096];
    char profesionB[4096];
    char nacionalidadB[4096];
    char idB[4096];
    char usuarioB[4096];
    FILE* archivo;
    Cliente * auxiliarCliente;


    if(path != NULL && pArrayListEmployee != NULL)
    {
        archivo = fopen(path, "r");
        while(!feof(archivo))
        {
            fscanf(archivo, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", idB, nombreB, apellidoB,
                   emailB, generoB, profesionB, usuarioB, nacionalidadB);
            //printf("ID: %s - Nombre: %s - Apellido: %s - Nacionalidad: %s\n",idB, nombreB, apellidoB, nacionalidadB);
            //VALIDAR
            auxiliarCliente = cliente_newParametros(nombreB, apellidoB); //LAS VARIABLES QUE FUERON VALIDADAS
            al_add(pArrayListEmployee, auxiliarCliente); //AGREGO EL CLIENTE AL ARRAY
        }
        retorno = 0;
    }
    fclose(archivo);
    return retorno;
}
