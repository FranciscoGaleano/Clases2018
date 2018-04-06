int getInt(char* mensaje, char* mensajeError, int reintentos, int minimo, int maximo, int* resultado)
{
    int retorno = -1;
    int datoRequerido;
    do{
        reintentos--;
        printf("%s", mensaje);
        scanf("%d", &datoRequerido);
        if(datoRequerido >= minimo && datoRequerido <= maximo)
        {
            *resultado = datoRequerido;
            retorno = 0;
            break;
        }
        else if(datoRequerido > maximo)
        {
            retorno = -1;
        }
        else
        {
            retorno = -2;
        }
        printf("%s", mensajeError);
        scanf("%d", &datoRequerido);
        }
    while(reintentos >= 0);
    return retorno;
}



int mostrarArrayEnteros(int* array, int cantidad)
{
    int retorno = -1;

    if(cantidad > 0)
    {
        int i;
        for(i = 0; i < cantidad; i++)
        {
            printf("El numero es %d\n", array[i]);
        }
        retorno = 0;
    }
    return retorno;
}


float promedioArrays(int* array)


