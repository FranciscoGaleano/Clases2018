#include <stdio.h>
#include <stdlib.h>
#include "clase8.h"
#define TAMANIO 5

int main()
{
    int nota1[TAMANIO] = {10, 4, 2, 9, 8};
    int nota2[TAMANIO] = {1, 8, 2, 8, 10};
    float promedioNotas[TAMANIO];
    char apellidos[TAMANIO][20] = {"Lopez", "Alvarez", "Zapata", "Perez", "Albornoz"};
    int i;

    for(i = 0; i < TAMANIO; i++)
    {
        promedioNotas[i] = sacarPromedio(nota1[i], nota2[i]);
        printf("El alumno %s tiene de promedio %.2f\n", apellidos[i], promedioNotas[i]);
    }

    ordenarArrayFlotantes(promedioNotas, TAMANIO, 1);
    mostrarArrayFlotantes(promedioNotas, TAMANIO);





    return 0;
}
