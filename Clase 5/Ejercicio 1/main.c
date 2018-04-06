#include <stdio.h>
#include <stdlib.h>
#include "clase5.h"
#define CANTIDAD 4

int main()
{
    int listaNumeros[CANTIDAD];
    int i;

    for(i = 0; i < CANTIDAD; i++)
    {
        getInt("Ingrese un numero\n", "Error \n", 3, 1, 100, &listaNumeros[i]);

    }

    mostrarArrayEnteros(listaNumeros, CANTIDAD);




    return 0;
}
