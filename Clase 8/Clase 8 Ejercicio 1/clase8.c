float sacarPromedio(int primerNumero, int segundoNumero)
{
    int numeroA;
    int numeroB;
    float auxiliar;
    numeroA = primerNumero;
    numeroB = segundoNumero;
    auxiliar = (float)(numeroA  + numeroB) / 2;
    return auxiliar;

    //*resultado = auxiliar;
    //printf("El promedio es %.2f\n", *resultado);
}


float ordenarArrayFlotantes(float * array, int cantidad, int orden)
{
    float auxiliar;
    int i;
    int j;

    for(i = 1; i < cantidad; i++)
    {
        auxiliar = array[i];
        j = i;
        while(j > 0 && auxiliar < array[j-1])
        {
            array[j] = array[j-1];
            j--;
        }
        array[j] = auxiliar;
    }
}


float mostrarArrayFlotantes(float * array, int cantidad)
{
    int retorno = -1;
    int i;
    for(i = 0; i < cantidad; i++)
    {
        printf("%.2f\n", array[i]);
    }
    retorno = 0;
    return retorno;
}


char mostrarArrayString(char * arrayString, float * arrayFloat, int cantidad)
{
    char arrayS;
    int arrayF;
    arrayF = * arrayFloat;
    arrayS = * arrayString;
    int i;

    for(i = 0; i < cantidad, i++)
    {
       arrayFloat[i] = arrayString[i];
       printf("El alumno %s tiene promedio %.2f", array)
    }

}
