#include <stdio.h>
#include <stdlib.h>
#define QTY 5

int main()
{
    int arrayEnteros[QTY];
    crearArray(arrayEnteros, QTY);
    printf("El array creado es el siguiente\n");
    mostrarArray(arrayEnteros, QTY);
    printf("El array ordenado de mayor a menor seria\n");
    ordenarArray(arrayEnteros, QTY, 1);
    mostrarArray(arrayEnteros, QTY);
    printf("El array ordenado de menor a mayor seria\n");
    ordenarArray(arrayEnteros, QTY, 0);
    mostrarArray(arrayEnteros, QTY);




    return 0;
}
