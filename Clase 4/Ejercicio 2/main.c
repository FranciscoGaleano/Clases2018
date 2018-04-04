#include <stdio.h>
#include <stdlib.h>
int getInt(char* mensaje, char* mensajeError, int intentos, int minimo, int maximo, int* resultado);

int main()
{
    int resultado;
    if(getInt("Ingrese una edad\n", "Ingrese una edad valida[De 1 a 199]\n", 5, 1, 199, &resultado) == 0)
        {
        printf("La edad es %d\n", resultado);
        }
        else{
        printf("Error\n");
        }

}

/** \brief
 *
 * \param mensaje char*
 * \param mensajeError char*
 * \param reintentos int
 * \param minimo int
 * \param maximo int
 * \param resultado int*
 * \return int
 *
 */
int getInt(char* mensaje, char* mensajeError, int reintentos, int minimo, int maximo, int* resultado)
{
    int retorno = -1;
    int datoRequerido;
    do{
        reintentos--;
        printf("%s", mensaje);
        scanf("%d", &datoRequerido);
        if(datoRequerido > minimo && datoRequerido < maximo)
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
