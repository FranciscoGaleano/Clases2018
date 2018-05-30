#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"

static int isValidNombre(char* nombre);
static int isValidApellido(char* apellido);
static int isValidIsEmpty(char* isEmpty);

//pasar todos los protof}tipos/firmas al .h
//static = privadas

static int isValidNombre(char* nombre)
{
    return 1;
}

static int isValidApellido(char* apellido)
{
    return 1;
}

static int isValidIsEmpty(char* isEmpty)
{
    return 1;
}

Employee* employee_newParametros(int id, char* nombre, char* apellido,int isEmpty)
{
    Employee* auxiliarEmployee = employee_new();//A-- me llama la funcion q crea un espacio de memoria dinamico para el puntero

    if(     !employee_setId(auxiliarEmployee, id)//si esto y lo otro y lo otro, etc, no están, me crea ese espacio
       &&   !employee_setNombre(auxiliarEmployee,nombre)
       &&   !employee_setApellido(auxiliarEmployee, apellido)
       &&   !employee_setIsEmpty(auxiliarEmployee, isEmpty))
    {
         return auxiliarEmployee;//aca me lo devuuelve
    }
    employee_delete(auxiliarEmployee);//en el caso de que lo otro este, me borra el espacio creado en A
    return NULL;
}

int employee_compareByName(void* pEmployeeA,void* pEmployeeB)
{
    char nameA[51];
    char nameB[51];
    employee_getNombre(pEmployeeA, nameA);
    employee_getNombre(pEmployeeB, nameB);
    return strcmp(nameA, nameB);
}


void employee_print(Employee* this)
{
    int id;
    char name[50];
    char lastName[50];
    int isEmpty;

    employee_getNombre(this, name);
    employee_getApellido(this, lastName);
    employee_getId(this, id);
    employee_getIsEmpty(this, isEmpty);
    printf("ID: %d - Nombre: %s - Apellido: %s - Is Empty: %d\n", id, name, lastName, isEmpty);

}


Employee* employee_new(void)
{
    Employee * auxiliar;
    if(auxiliar != NULL)
    {
        auxiliar = (Employee*) malloc(sizeof(Employee));
    }

    //Employee* auxiliar = NULL;
    //*auxiliar = malloc(sizeof(Employee));

    return auxiliar;
}

Employee* employee_newParametrosString(char* stringName, char* stringLastName, char* stringId, char* stringIsEmpty)
{
    //podemos validar que todo lo que nos dan sea algo potable
    Employee * this;
    int id = atoi(stringId);
    char name[50];
    char lastName[50];
    int isEmpty;
    if(!strcmp(stringIsEmpty, "true"))
       {
           isEmpty = 1;
       }
    this = employee_new();
    employee_setId(this, id);
    employee_setIsEmpty(this, isEmpty);
    employee_setNombre(this, stringName);
    employee_setApellido(this, stringLastName);
}

void employee_delete(Employee* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

int employee_setNombre(Employee* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL && isValidNombre(nombre))
    {
        retorno = 0;
        strcpy(this->name,nombre);
    }
    return retorno;
}

int employee_getNombre(Employee* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        retorno = 0;
        strcpy(nombre,this->name);
    }
    return retorno;
}

int employee_setApellido(Employee* this, char* apellido)
{
    int retorno = -1;
    if(this != NULL && apellido != NULL && isValidApellido(apellido))
    {
        retorno = 0;
        strcpy(this->lastName,apellido);
    }
    return retorno;
}

int employee_getApellido(Employee* this, char* apellido)
{
    int retorno = -1;
    if(this != NULL && apellido != NULL)
    {
        retorno = 0;
        strcpy(apellido,this->lastName);
    }
    return retorno;
}

int employee_setId(Employee* this, int id)
{
    int retorno = -1;
    static int maximoId = -1;
    if(this != NULL)
    {
        retorno = 0;
        if(id >= 0)
        {
            if(id > maximoId)
            {
                maximoId = id;//AHORA MAXIMO ID VA A VALER ESO, DE ACA AL FIN DE LOS TIEMPOS
                this->id = id;
            }
        }
        else
        {
            maximoId++;
            this->id = maximoId;
        }
    }
    return retorno;
}


int employee_getId(Employee* this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        retorno = 0;
        *id = this->id;
    }
    return retorno;
}


int employee_setIsEmpty(Employee* this, int isEmpty)
{
    int retorno = -1;

    if(this != NULL && isValidIsEmpty(isEmpty))
    {
        retorno = 0;
        this->isEmpty = isEmpty;
    }
    return retorno;
}

int employee_getIsEmpty(Employee* this, int* isEmpty)
{
    int retorno = -1;
    if(this != NULL && isEmpty != NULL)
    {
        retorno = 0;
        *isEmpty = this->isEmpty;
    }
    return retorno;
}



