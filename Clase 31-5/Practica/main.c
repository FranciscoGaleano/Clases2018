#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Cliente.h"

/****************************************************
    Menu:
        1. Cargar datos desde data.csv
        2. Listar Clientes
        3. Ordenar por nombre y apellido
        4. Ordenar por mail
        5. Agregar un Cliente
        6. Elimina un Cliente
        7. Modificar Cliente (Nombre, Apellido y Mail)
        8. Listar Clientes
        9. Guardar datos en data.csv (modo texto)
       10. Guardar datos en data.bin (modo binario)
*****************************************************/


int main()
{
    printf("Aca empieza.\n");
    ArrayList* pArrayClientes;
    pArrayClientes = al_newArrayList();

    Cliente * auxCliente;
    auxCliente = cliente_new();

    parserEmployee("data.csv", pArrayClientes);
    printf("Aca sigue.\n");
    cliente_listar(pArrayClientes);
    printf("Esto funciona bien.\n");


    return 0;
}
