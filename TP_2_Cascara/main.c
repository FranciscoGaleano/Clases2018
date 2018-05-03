#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define QTY 20


int main()
{
    char seguir = 's';
    int opcion = 0;
    Persona listaDePersonas[QTY];
    int personaIndice;

    per_crear(listaDePersonas, QTY);

    strcpy(listaDePersonas[0].nombre,"Gerardo");
    strcpy(listaDePersonas[1].nombre,"Pablo");
    strcpy(listaDePersonas[2].nombre,"German");
    strcpy(listaDePersonas[3].nombre,"Jose");
    strcpy(listaDePersonas[4].nombre,"alfredo");
    strcpy(listaDePersonas[5].nombre,"Carlos");
    strcpy(listaDePersonas[6].nombre,"Ariel");
    strcpy(listaDePersonas[7].nombre,"Cesar");
    strcpy(listaDePersonas[8].nombre,"Pablo");
    strcpy(listaDePersonas[9].nombre,"Ezequiel");
    strcpy(listaDePersonas[10].nombre,"Olivia");
    strcpy(listaDePersonas[11].nombre,"Elena");
    strcpy(listaDePersonas[12].nombre,"Carolina");
    strcpy(listaDePersonas[13].nombre,"Marcos");
    strcpy(listaDePersonas[14].nombre,"Micaela");
    listaDePersonas[0].dni=23456756;
    listaDePersonas[1].dni=23456764;
    listaDePersonas[2].dni=33000984;
    listaDePersonas[3].dni=23765789;
    listaDePersonas[4].dni=12345433;
    listaDePersonas[5].dni=43234565;
    listaDePersonas[6].dni=43456543;
    listaDePersonas[7].dni=45334543;
    listaDePersonas[8].dni=26356632;
    listaDePersonas[9].dni=15345643;
    listaDePersonas[10].dni=3047394;
    listaDePersonas[11].dni=6438927;
    listaDePersonas[12].dni=6835323;
    listaDePersonas[13].dni=4375432;
    listaDePersonas[14].dni=1;
    listaDePersonas[0].edad=12;
    listaDePersonas[1].edad=16;
    listaDePersonas[2].edad=18;
    listaDePersonas[3].edad=14;
    listaDePersonas[4].edad=18;
    listaDePersonas[5].edad=9;
    listaDePersonas[6].edad=22;
    listaDePersonas[7].edad=33;
    listaDePersonas[8].edad=31;
    listaDePersonas[9].edad=19;
    listaDePersonas[10].edad=55;
    listaDePersonas[11].edad=64;
    listaDePersonas[12].edad=68;
    listaDePersonas[13].edad=43;
    listaDePersonas[14].edad=36;
    listaDePersonas[0].estado=0;
    listaDePersonas[1].estado=0;
    listaDePersonas[2].estado=0;
    listaDePersonas[3].estado=0;
    listaDePersonas[4].estado=0;
    listaDePersonas[5].estado=0;
    listaDePersonas[6].estado=0;
    listaDePersonas[7].estado=0;
    listaDePersonas[8].estado=0;
    listaDePersonas[9].estado=0;
    listaDePersonas[10].estado=0;
    listaDePersonas[11].estado=0;
    listaDePersonas[12].estado=0;
    listaDePersonas[13].estado=0;
    listaDePersonas[14].estado=0;

    while(seguir == 's')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n\n");

        printf("Que tarea desea realizar?\n\n");
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1:
                per_buscarLibre(listaDePersonas, QTY);
                per_alta(listaDePersonas, QTY);
                printf("Desea continuar? S/N\n");
                fflush(stdin);
                scanf("%c", &seguir);
                system("cls");
                break;
            case 2:
                printf("Aqui tiene la lista de personas ingresadas\n");
                per_mostrar(listaDePersonas, QTY);
                //printf("A quien desea eliminar?\n");
                //scanf("%d", &personaIndice);
                per_baja(listaDePersonas, QTY, &personaIndice);
                printf("Desea continuar? S/N\n");
                fflush(stdin);
                scanf("%c", &seguir);
                system("cls");
                break;
            case 3:
                break;
            case 4:
                per_graficar(listaDePersonas, QTY);
                printf("Desea continuar? S/N\n");
                fflush(stdin);
                scanf("%c", &seguir);
                system("cls");
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                while(opcion > 5)
                {
                    printf("Ingrese una opcion valida.\n");
                    scanf("%d", &opcion);
                    system("cls");
                    break;
                }
        }
    }

    return 0;
}
