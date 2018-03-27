#include <stdio.h>
#include <stdlib.h>
#define numero 45


int main()
{
    //int numero;
    int numeroAdivinar;
    int contador = 0;

    //printf("Numero asignado \n");
    //scanf("%d", &numero);
    do{
        contador++;
        printf("Ingrese un numero \n");
        fflush(stdin);
        scanf("%d", &numeroAdivinar);
        while(numeroAdivinar <= 0 || numeroAdivinar > 100){
            printf("Ingrese un numero dentro de los parametros \n");
            scanf("%d", &numeroAdivinar);
            }
        if(numero > numeroAdivinar){
            printf("El numero ingresado es menor, intente de nuevo \n");
            }
        if(numero < numeroAdivinar){
            printf("El numero ingresado es mayor, intente de nuevo \n");
            }
    }while(numeroAdivinar != numero);

    printf("Ese es el numero! Y solo te tomo %d intentos. \n", contador);

    if(contador < 5){
        printf("Excelente!\n");
        }
    else if(contador > 4 && contador < 10){
            printf("Muy bien!\n");
            }
    else{
        printf("Hace falta practica \n");
        }









    return 0;
}
