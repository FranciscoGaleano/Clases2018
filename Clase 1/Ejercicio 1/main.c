#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int numeroUno;
    int numeroDos;
    int numeroTres;
    int numeroMayor;

    printf("Ingrese el primer numero \n");
    scanf("%d", &numeroUno);
    printf("Ingrese el segundo numero \n");
    scanf("%d", &numeroDos);
    printf("Ingrese el tercer numero \n");
    scanf("%d", &numeroTres);

    if(numeroUno > numeroDos && numeroDos > numeroTres){

        numeroMayor = numeroUno;
    }
    else{

        if(numeroDos > numeroTres){

            numeroMayor = numeroDos;

        }
        else{

            numeroMayor = numeroTres;

        }



    }

     printf("El numero mayor es: %d", numeroMayor);

    return 0;

}
