int getInt(char* mensaje, char* mensajeError, int reintentos, int minimo, int maximo, int *numeroObtenido)
{
    int retorno = -1;
    int datoRequerido;
    printf("%s", mensaje);
    scanf("%d", &datoRequerido);
    while(reintentos > 0)
    {
        reintentos--;
        if(datoRequerido > minimo && datoRequerido < maximo)
        {
            *numeroObtenido = datoRequerido;
            retorno = 0;
            break;
        }
        else if(datoRequerido < minimo)
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
    return retorno;
}

float calculadora(char* mensaje, char* mensajeError, char *operadorCuenta, int *primerNumero, int *segundoNumero, float *resultado)
{
    int retorno = -1;
    char operador;
    int numeroUno;
    int numeroDos;
    float auxiliarResultado;
    numeroUno = *primerNumero;
    numeroDos = *segundoNumero;
    printf("%s", mensaje);
    scanf(" %c", &operador);
    while(operador != 's' && operador != 'r' && operador != 'd' && operador != 'm')
    {
        printf("%s", mensajeError);
        scanf(" %c", &operador);
    }
    if(operador == 's' || operador == 'r' || operador == 'd' || operador == 'm')
    {
        *operadorCuenta = operador;
        retorno = 0;
    }
    switch(*operadorCuenta)
    {
        case 's':
        printf("Los numeros ingresados fueron %d y %d\nLa operacion a realizar es una suma\n", numeroUno, numeroDos);
        auxiliarResultado = numeroUno + numeroDos;
        *resultado = auxiliarResultado;
        return *resultado;
        break;

        case 'r':
        printf("Los numeros ingresados fueron %d y %d\nLa operacion a realizar es una resta\n", numeroUno, numeroDos);
        auxiliarResultado = numeroUno - numeroDos;
        *resultado = auxiliarResultado;
        return *resultado;
        break;

        case 'd':
        while(numeroDos == 0)
        {
            printf("No se puede dividir por 0. Intente de nuevo\nIngrese un nuevo numero\n");
            scanf("%d", &numeroDos);
        }
        printf("Los numeros ingresados fueron %d y %d\nLa operacion a realizar es una division\n", numeroUno, numeroDos);
        auxiliarResultado = (float) numeroUno / numeroDos;
        *resultado = auxiliarResultado;
        return *resultado;
        break;

        case 'm':
        printf("Los numeros ingresados fueron %d y %d\nLa operacion a realizar es una multiplicacion\n", numeroUno, numeroDos);
        auxiliarResultado = numeroUno * numeroDos;
        *resultado = auxiliarResultado;
        return *resultado;
        break;
    }
    return *resultado;
}

double obtenerFactorial(int *numeroBase, int *numeroFactorial)
{
    int retorno = -1;
    int a = *numeroBase;
    int b = a;
    double factorial = 1;

    for(b = a; b > 1; b--)
    {
        factorial = factorial * b;
        *numeroFactorial = factorial;
    }
    printf("El factorial de %d es igual a %d\n", a, *numeroFactorial);
    return retorno;
}
