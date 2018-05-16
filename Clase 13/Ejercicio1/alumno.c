#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumno.h"

Alumno* alumno_new()
{
    return malloc(sizeof(Alumno));
}

void alumno_delete(Alumno* this)
{
    free(this);
}

int  alumno_setEdad(Alumno* this, int edad)
{
    int retorno = -1;
    if(this != NULL && edad >= 0)
    {
        retorno = 0;
        this->edad = edad;
    }
    return retorno;
}

int alumno_getEdad(Alumno* this, int* edad)
{
    int retorno = -1;
    if(this != NULL && edad != NULL)
    {
        retorno = 0;
        *edad = this->edad;
    }
    return retorno;

}

int alumno_setNombre(Alumno* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        retorno = 0;
        strcpy(this->nombre,nombre);
    }
    return retorno;
}

int alumno_getNombre(Alumno* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        retorno = 0;
        nombre = this->nombre;
    }
    return retorno;
}

void cargar(Alumno** array,int cantidad)
{
    int i;
    Alumno* auxiliarAlumno;
    for(i=0;i<cantidad;i++)
    {
        auxiliarAlumno = alumno_new();
        *(array+i)  = auxiliarAlumno;
        alumno_setEdad(auxiliarAlumno,i+10);
        alumno_setNombre(auxiliarAlumno, "Pepe Pecas");
        auxiliarAlumno = malloc(sizeof(Alumno));
    }
}

void mostrar(Alumno* array[],int cantidad)
{
    int auxiliarEdad;
    for(;cantidad > 0; array++,cantidad--)
    {
        alumno_getEdad(*array,&auxiliarEdad);
        printf("EDAD: %d\n",auxiliarEdad);
    }
}
