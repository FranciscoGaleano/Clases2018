#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 10

int main()
{
    char letra;
    int aContador = 0;
    int eContador = 0;
    int iContador = 0;
    int oContador = 0;
    int uContador = 0;
    int restoContador = 0;
    int i;

    for(i = 0; i < CANTIDAD; i++){
        printf("Ingrese aqui un caracter \n");
        fflush(stdin);
        scanf("%c", &letra);
        letra = tolower(letra);

        switch(letra){
        case 'a':
        aContador++;
        break;
        case 'e':
        eContador++;
        break;
        case 'i':
        iContador++;
        break;
        case 'o':
        oContador++;
        break;
        case 'u':
        uContador++;
        break;
        default:
        restoContador++;
        break;
        }




}
        printf("Hay %d cantidad de A\nHay %d cantidad de E\nHay %d cantidad de I\nHay %d cantidad de O\nHay %d cantidad de U\nHay %d cantidad de otras letras", aContador, eContador, iContador, oContador, uContador, restoContador);
        return 0;

}
