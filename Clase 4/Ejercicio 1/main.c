#include <stdio.h>
#include <stdlib.h>

int sumar(int, int);

int main()
{
    int primerNumero;
    int segundoNumero;
    int resultado;

    printf("Ingrese un numero \n");
    scanf("%d", &primerNumero);
    printf("Ingrese un numero \n");
    scanf("%d", &segundoNumero);

    resultado = sumar(primerNumero, segundoNumero);
    printf("El resultado es %d", resultado);
    //return 0;
}

int sumar(int primerNumero, int segundoNumero){

    int resultado = primerNumero + segundoNumero;
    return resultado;

}
