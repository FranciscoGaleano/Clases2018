int crearArray(int  * array, int cantidad)
{
    int retorno = -1;
    int i;
    for(i = 0; i < cantidad; i++)
    {
        printf("Ingrese aqui un numero\n");
        scanf("%d", &array[i]);
    }
    retorno = 0;
    return retorno;
}

int mostrarArray(int * array, int cantidad)
{
    int retorno = -1;
    int i;
    for(i = 0; i < cantidad; i++)
    {
        printf("%d\n", array[i]);
    }
    retorno = 0;
    return retorno;
}

int ordenarArray(int * array, int cantidad, int orden)
{
    int retorno = 1;
    int j;
    int aux;
    int flag;
    do
    {
        flag = 0;
        for(j = 0; j < cantidad-1; j++)
        {
            if((array[j] > array[j+1] && orden == 0) || (array[j] < array[j+1] && orden == 1))
            {
                aux = array[j];
                array[j] = array[j+1];
                array[j+1] = aux;
                flag = 1;
            }
        }
    }while(flag);
    return retorno;
}
