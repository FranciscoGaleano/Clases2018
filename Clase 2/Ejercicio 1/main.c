#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 5

int main()
{
    int numero;
    float promedio;
    int algo;
    int suma = 0;
    int numeroMayor;
    int numeroMenor;
    int contador = 0;
    int flag = 0;

    for(algo = 0; algo < CANTIDAD; algo++){
     //   printf("Ingrese un numero \n");
     //   scanf("%d", &numero);
     //    while(numero <= 0){
            do{
            printf("Ingrese un numero \n");
            scanf("%d", &numero);
            }while(numero <= 0);
         //   }
             suma = suma + numero;
             contador = contador++;
            // if(contador == 1){

            if(flag == 0){
                numeroMayor = numero;
                numeroMenor = numero;
                flag = 1;
             }
             else{
                if(numero > numeroMayor && numeroMenor < numero){
                    numeroMayor = numero;
                }
                else{
                    numeroMenor = numero;
                }
             }
        }
    promedio = (float)suma / CANTIDAD;
    printf("El promedio es : %.2f \n", promedio);
    printf("El numero mayor es %d \nEl numero menor es %d \n", numeroMayor, numeroMenor);
    return 0;
}
