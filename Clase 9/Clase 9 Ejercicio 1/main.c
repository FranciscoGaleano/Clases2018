#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"
#define QTY 5


int main()
{
    int proximaId = 0;
    int opcion;
    Empleado arrayEmpleados[QTY];
    char continuar = 's';

    printf("1) Crear una nueva lista.\n");
    printf("2) Buscar lugares libres para ingresar datos.\n");
    printf("3) Dar de alta a un nuevo empleado.\n");
    printf("4) Mostrar el empleado por ID.\n");
    printf("5) Dar de baja a un empleado existente.\n");
    printf("6) Terminar de trabajar.\n");


    do
    {
        printf("Ingrese la opcion que desea realizar.\n");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            emp_init(arrayEmpleados, QTY);
            printf("Desea continuar? S/N \n");
            fflush(stdin);
            scanf("%c", &continuar);
            break;
        case 2:
            buscarLibre(arrayEmpleados, QTY);
            printf("Desea continuar? S/N \n");
            fflush(stdin);
            scanf("%c", &continuar);
            break;
        case 3:
            emp_alta(arrayEmpleados, QTY, proximaId);
            printf("Desea continuar? S/N \n");
            fflush(stdin);
            scanf("%c", &continuar);
            break;
        case 4:
            emp_mostrar(arrayEmpleados, QTY);
            printf("Desea continuar? S/N \n");
            fflush(stdin);
            scanf("%c", &continuar);
            break;
        case 5:
            emp_baja(arrayEmpleados, QTY, proximaId);
            printf("Desea continuar? S/N \n");
            fflush(stdin);
            scanf("%c", &continuar);
            break;
        case 6:
            continuar = 'n';
            break;
        default:
            printf("Ingrese una opcion valida.\n");
            scanf("%d", &opcion);
            break;

        }

    }while(continuar = 's');

    return 0;
}
