#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "ArrayList.h"

Cliente * cliente_new()
{
    return malloc(sizeof(Cliente));
}

void cliente_delete(Cliente* this)
{
    free(this);
}

static int isValidString(char* string)
{
    return 1;
}

Cliente * cliente_newParametros(char* nombre, char* apellido)
{
    Cliente * pAuxiliarCliente;
    pAuxiliarCliente = cliente_new();
    cliente_setNombre(pAuxiliarCliente, nombre);
    cliente_setApellido(pAuxiliarCliente, apellido);
    return pAuxiliarCliente;

}

Cliente * cliente_listar(Cliente * pArrayClientes)
{
    int retorno = -1;
    Cliente * auxiliarCliente;
    char bNombre[256];
    char bApellido[256];
    int i;
    for(i = 0; i < al_len(pArrayClientes); i++)
    {

        auxiliarCliente = al_get(pArrayClientes, i);
        cliente_getNombre(auxiliarCliente, bNombre);
        cliente_getApellido(auxiliarCliente, bApellido);
        printf("Nombre: %s - Apellido: %s\n", bNombre, bApellido);
        retorno = 0;
    }

    return retorno;
}

int cliente_setNombre(Cliente* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL && isValidString(nombre))
    {
        retorno = 0;
        strcpy(this->nombre, nombre);
    }
    return retorno;
}

int cliente_getNombre(Cliente* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        retorno = 0;
        strcpy(nombre, this->nombre);
    }
    return retorno;
}

int cliente_setApellido(Cliente* this, char* apellido)
{
    int retorno = -1;
    if(this != NULL && apellido != NULL && isValidString(apellido))
    {
        retorno = 0;
        strcpy(this->apellido, apellido);
    }
    return retorno;
}

int cliente_getApellido(Cliente* this, char* apellido)
{
    int retorno = -1;
    if(this != NULL && apellido != NULL)
    {
        retorno = 0;
        strcpy(apellido, this->apellido);
    }
    return retorno;
}
