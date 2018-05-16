#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"


int main()
{
    Alumno* arrayDeAlumnos[50];
    cargar(arrayDeAlumnos, 50);
    mostrar(arrayDeAlumnos, 50);
    printf("Hello world!\n");
    return 0;
}

void cargar(Alumno * arrayDeAlumnos, int cantidad)
{
    int i;
    for(i = 0; i < cantidad; i++)
    {
        (arrayDeAlumnos+i)->edad = 10 + i;//esta notacion es de mas agrado para el profe//
        //para mi tambien//
    }
}

void mostrar(Alumno * arrayDeAlumnos, int cantidad)
{

    for(; cantidad > 0; arrayDeAlumnos++, cantidad--)
    {
        printf("EDAD: %d\n", arrayDeAlumnos->edad);
    }
}
