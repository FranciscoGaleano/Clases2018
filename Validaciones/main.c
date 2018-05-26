#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

int main()
{
    char nombre[40];
    getValidString("Ingrese un nombre.\n", "Eso no es un nombre. Trate de nuevo.\n", "Ese nombre supera el limite. Trate de nuevo.\n", nombre, 30, 5);
    printf("El nombre ingresado es %s.", nombre);
    return 0;
}
