#include <stdio.h>
#include <stdlib.h>
#define QTY 5

int main()
{


    int array[QTY] = {1, 2, 3, 4, 5};
    int i;
    int aux;
    aux = array[0];
    for(i = 0; i < 3; i++)
    {
        array[i] = array[i+1];
    }
    array[i] = aux;

    printf("%d %d %d %d %d \n \n", array[0], array[1], array[2], array[3], array[4]);

    int array2[QTY] = {6, 7, 8, 9, 10};
    int j;
    int coop;
    coop = array2[4];
    for(j = 4; j > 1; j--)
    {
        array2[j] = array2[j-1];
    }
    array2[j] = coop;

    printf("%d %d %d %d %d \n \n", array2[0], array2[1], array2[2], array2[3], array2[4]);





    return 0;
}
