#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"

void mostrar(Alumno* array[],int cantidad);
void cargar(Alumno* array[],int cantidad);
int main()
{
    Alumno* arrayPunteroAlumnos[50];
    int array[50];
    cargar(arrayPunteroAlumnos,50);


    mostrar(arrayPunteroAlumnos,50);
    return 0;
}


