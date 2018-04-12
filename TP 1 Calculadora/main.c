#include <stdio.h>
#include <stdlib.h>

int main()
{
    int primerNumero;
    int segundoNumero;
    char operador;
    int factorial;
    float resultado;

    printf("Ingresar el 1er operando\n");
    printf("Ingresar el 2do operando\n");
    printf("Calcular suma (A+B)\n");
    printf("Calcular resta (A-B)\n");
    printf("Calcular la division (A/B)\n");
    printf("Calcular la multiplicacion (A*B)\n");
    printf("Calcular el factorial (A!)\n");
    printf("Calcular todas las operaciones\n");
    printf("Salir\n");

    printf("Bienvenido! Ahora vamos a trabajar juntos\n");
    getInt("Ingrese el primer numero\n", "Ingrese un valor valido\n", 999, -32000,  32000, &primerNumero);
    getInt("Ingrese el segundo numero\n", "Ingrese un valor valido\n", 999, -32000,  32000, &segundoNumero);
    calculadora("Ingrese un operador\n", "Ingrese un operador valido\n", &operador, &primerNumero, &segundoNumero, &resultado);
    obtenerFactorial(&primerNumero, &factorial);
    printf("El resultado de la operacion es %.2f", resultado);
    return 0;
}
