#include "alumno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int isValidCuit(char* cuit);
static int isValidAltura(int altura);

static int ultimoId = -1;

Alumno* alumno_new()
{
    return malloc(sizeof(Alumno));
}

Alumno* alumno_newParametros(char* nombre, float altura, int id)//similar alta forzada
{
    Alumno * auxiliarAlumno = alumno_new();

    if(   !alumno_setNombre(auxiliarAlumno, nombre)//EL SET YA VALIDA
       && !alumno_setAltura(auxiliarAlumno, altura)
       && !alumno_setId(auxiliarAlumno, id));
    {
        return auxiliarAlumno;//ASI SON TODAS LAS FUNCIONES QUE CREAN ENTIDADES
    }
    alumno_delete(auxiliarAlumno);
    return NULL;

}



void alumno_delete(Alumno* this)
{
    free(this);
}

//AHORA HAY QUE CONSTRUIR LOS SET Y LOS GET(LOS QUE SON STRING Y LOS QUE NO)

int alumno_setNombre(Alumno * this, char * nombre)//NECESITA CONTEXTO, ES A QUIEN O SOBRE QUIEN VA A TRABAJAR
{
    int retorno = -1;
    if(this != NULL && nombre != NULL) //&& isValidNombre)//HACER TODAS LAS FUNCIONES QUE VALIDAN COSAS
    {
        retorno = 0;
        strcpy(this->nombre, nombre);//TODOS LOS DEMAS SET SON IGUALES
    }
    return retorno;
}

int alumno_getNombre(Alumno * this, char * nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        retorno = 0;
        strcpy(nombre, this->nombre);//INVERTI EL ORDEN DE LA LINEA REFERIDO AL SET QUE LE CORRESPONDE
    }
    return retorno;

}

int alumno_setAltura(Alumno * this, float altura)
{
    int retorno = -1;
    if(this != NULL)// && isValidAltura(altura))
    {
        retorno = 0;
        this->altura = altura;
    }
    return retorno;
}

int alumno_getAltura(Alumno * this, float * altura)
{
    int retorno = -1;
    if(this != NULL && altura != NULL)
    {
        retorno = 0;
        *altura = this->altura;
    }
    return retorno;
}

int alumno_setIdAlumno(Alumno * this, int id)//ESTA ES UN POCO MAS COMPLICADA
{
    int retorno = -1;
    static int maximoId = -1;
    if(this != NULL)
    {
        if(id >= 0)
        {
            retorno = 0;
            if(id > maximoId)
            {
                maximoId = id;
            }
            this->id = id;
        }
        else
        {
            maximoId++;
            this->id = maximoId;

        }
    }

    return retorno;
}

int alumno_getIdAlumno(Alumno * this, int * id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        retorno = 0;
        *id = this->id;
    }
    return retorno;
}

static int isValidNombre(char * nombre)//LAS DECLARO STATIC PARA QUE NO LAS USEN DE AFUERA. ESO SIGNIFICA EL STATIC
{

    return 1;
}

/*static int isValidAltura(float altura)
{

    return 1;
}*/





//*************************************


int arrayAlumno_loadFromFile(Alumno ** arrayPunterosAlumnos, int * qtyOcupada, int qtyTotal, char * path)//DOS ASTERISCOS, ES UN ARRAY DE PUNTEROS
{
    int retorno = -1;
    char bNombre[300];
    char bAltura[300];
    char bId[300];
    char nombre[50];
    float altura;
    int id;
    FILE* pFile;
    pFile = fopen(path, "r");//MODOS DE COMO ABRIR UN FILE: ESCRITURA Y/O LECTURA
    if(pFile != NULL && arrayPunterosAlumnos != NULL && qtyTotal > 0 && *qtyOcupada >= 0 && qtyTotal > *qtyOcupada)
    {
        while(!feof(pFile))//feof = FILE END OF FILE
        {
            printf("Todo OK.\n");//SIEMPRE METO ALGO ASI PARA VER SI PUDE ABRIR EL ARCHIVO
            fscanf(pFile, "%[^,], %[^,], %[^\n]\n", bNombre, bAltura, bId);
            printf("%s - %s - %s\n", bNombre, bAltura, bId);//YA PARSEAMOS, NOS DEVUELVE LOS DATOS QUE QUERIAMOS VER
            //FALTA VALIDAR Y CONVERTIR LO QUE NOS TRAJIMOS
            strcpy(nombre, bNombre);
            altura = atof(bAltura);//atof = TRANSFORMA UN STRING EN FLOAT
            id = atoi(bId);//atoi = TRANSFORMA UN STRING EN INT
            arrayPunterosAlumnos[*qtyOcupada] = alumno_newParametros(nombre, altura, id);
            (*qtyOcupada)++;
        }
        retorno = 0;
    }
    fclose(pFile);
    return retorno;
}

int arrayAlumno_dumpInFile(Alumno ** arrayPunterosAlumnos, int * qtyOcupada, int qtyTotal, char * path)
{
    int retorno = -1;
    int i;
    FILE* pFile;
    pFile = fopen(path, "w");//MODOS DE COMO ABRIR UN FILE: ESCRITURA Y/O LECTURA
    if(pFile != NULL && arrayPunterosAlumnos != NULL && qtyTotal > 0 && *qtyOcupada >= 0 && qtyTotal > *qtyOcupada)
    {
        for(i = 0; i < qtyOcupada; i++)
        {
            alumno_getNombre(arrayPunterosAlumno[i].nombre, nombre);
            alumno_getAltura(arrayPunterosAlumnos[i].altura, altura);
            alumno_getIdAlumno(arrayPunterosAlumnos[i].id, id); //TODOS LOS GET
            fprintf(pFile, "%s - %.2f - %d\n", nombre, altura, id);
        }

    }
    return retorno;
}







Alumno* arrayAlumno_getById (Alumno* array[],int cantidad,int id)
{

}

void arrayAlumno_add(Alumno* array[],int cantidadMaxima,int* cantidadActual,char* dni, char* nombre, char* apellido, char* cuit,float altura,int id)
{

}

void arrayAlumno_remove(Alumno* array[],int cantidadMaxima,int* cantidadActual, int id)
{

}






