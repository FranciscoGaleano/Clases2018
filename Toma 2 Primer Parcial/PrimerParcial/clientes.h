#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "avisos.h"
#include "clientes.h"
#include "informar.h"

#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
typedef struct
    {
        char nombre[50];
        char apellido[50];
        char cuit[40];
        int idCliente;
        int isEmpty;
    }Cliente;
#endif // CLIENTES_H_INCLUDED
int clte_crear(Cliente * arrayDeClientes, int sizeArray);
int clte_alta(Cliente * arrayDeClientes, int sizeArray);
int clte_mostrar(Cliente * arrayDeClientes, int sizeArray);
int clte_baja(Cliente * arrayDeClientes, int sizeArray, int * ClienteId);
int clte_modificar(Cliente * arrayDeClientes, int sizeArray);
int clte_obtenerID(Cliente * arrayDeClientes, int sizeArray, int idCliente);
int clte_obtenerCuit(Cliente * arrayDeClientes, int limiteC, int idCliente);
