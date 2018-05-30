#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee)
{
    int retorno = -1;
    Employee * empleado;

    char bufferId[4096];
    char bufferFirstName[4096];
    char bufferLastName[4096];
    char bufferIsEmpty[4096];

    /*int id;
    char firstName[50];
    char lastName[50];
    int isEmpty;
    FILE * pFile;*/
    pFile = fopen("data.csv", "r");
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        //pFile = fopen(pFile, "r");
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferFirstName, bufferLastName, bufferIsEmpty);
            printf("ID: %s\n", bufferId);
            //FALTA VALIDAR
            empleado = employee_newParametrosString(bufferFirstName, bufferLastName, bufferId, bufferIsEmpty);
            //fijarme si tengo que hacer los atoi y compañia
            al_add(pArrayListEmployee, empleado);
        }
        retorno = 0;
    }
    fclose(pFile);
    return retorno;
}
