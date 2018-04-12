#include <stdio.h>
#include <stdlib.h>
#define QTY 5

int main()
{
    int array[QTY];
    int flag;
    int j;
    int aux;

    for(j = 0; j < QTY; j++)
    {
        printf("Ingrese un numero\n");
        scanf("%d", &array[j]);
    }

    do
    {
        flag = 0;
        for(j = 0; j < QTY-1; j++)
        {
            if(array[j] > array[j+1])
            {
                aux = array[j];
                array[j] = array[j+1];
                array[j+1] = aux;
                flag = 1;
            }
        }
    }while(flag);

    printf("El numero mayor es %d\n", array[4]);













    return 0;
}
