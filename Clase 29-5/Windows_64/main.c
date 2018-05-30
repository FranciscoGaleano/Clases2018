#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
//#include "parser.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{

    printf("Esto funciona bien a veces.\n");

    ArrayList * pArrayList;
    pArrayList = al_newArrayList();
    Employee * pEmployeeList;
    pEmployeeList = employee_new();
    FILE * pFile;
    pFile = fopen("data.csv", "r");
    parserEmployee(pFile, pArrayList);
    printf("Esto funciona bien.\n");


    return 0;
}
