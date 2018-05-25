#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"

void mostrar(Alumno* array[],int cantidad);
void cargar(Alumno** array,int cantidadMaxima,int* cantidadActual);

int main()
{

    Alumno* arrayPunteroAlumnos[4000];
    int qtyActualArrayAlumnos = 0;
    int qtyMaximaArrayAlumnos = 4000;

    cargar(arrayPunteroAlumnos,qtyMaximaArrayAlumnos,&qtyActualArrayAlumnos);
    mostrar(arrayPunteroAlumnos,qtyActualArrayAlumnos);

    return 0;
}


void cargar(Alumno** array,int cantidadMaxima,int* cantidadActual)
{

}

void mostrar(Alumno* array[],int cantidad)
{

}

void modificar(Alumno* array[],int cantidad)
{

}
