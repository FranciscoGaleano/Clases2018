#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    char apellido;
    float sueldo;
    int aumento;
    float sueldoFinal;

    printf("Ingrese aqui el apellido \n");
    scanf("%c", &apellido);
    printf("Ingrese el sueldo \n");
    scanf("%f", &sueldo);
    while(sueldo < 8000)
    printf("Ingrese un aumento \n");
    scanf("%d", &aumento);
    sueldoFinal = sueldo + (sueldo/100)*aumento;
    printf("El apellido es: %c El sueldo es: %f El sueldo final es: %f", apellido, sueldo, sueldoFinal );

    return 0;
}
