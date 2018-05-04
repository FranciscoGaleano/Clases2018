#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Contratacion.h"
#include "utn.h"
#include "Pantalla.h"


int informar_ConsultaFacturacion(Contratacion* arrayC,int limiteC,
              Pantalla* arrayP, int limiteP, char* cuit)
{
    int retorno = -1;
    int i;
    int indexPantalla;

    if(arrayC != NULL && arrayP != NULL && limiteC > 0 && limiteP > 0)
    {
        retorno = -2;
        for(i=0; i < limiteC; i++)
        {
            if(!arrayC[i].isEmpty && !strcmp(arrayC[i].cuit, cuit))
            {
                indexPantalla = pantalla_buscarPorId(arrayP, limiteP, arrayC[i].idPantalla);
                printf("CUIT: %s - ID %d - Valor: %.2f\n",
                        arrayC[i].cuit,
                        arrayC[i].id,
                        arrayC[i].dias*arrayP[indexPantalla].precio);
                retorno = 0;
            }
        }
    }

    return retorno;
}



int informar_ListarContrataciones(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;

    int i;

    for(i=0; i < limite; i++)
    {
        if(limite >= 0 && !arrayC[i].isEmpty)
        {
            if(limite >= 0 && !arrayC[i].idPantalla)
            {
                printf("%s - %s - %d - %s\n", pantallas[i].nombre, arrayC[i].archivo, arrayC[i].dias, arrayC[i].cuit);
            }
        }
    }

    return retorno;
}


int informar_ListarCantidadContratacionesImporte(Contratacion* arrayC,int limiteC,
              Pantalla* arrayP, int limiteP)
{
    int retorno = -1;
    int i;




    if(arrayC != NULL && arrayP != NULL && limiteC > 0 && limiteP > 0)
    {
        retorno = -2;
        cont_ordenarCuit(arrayC, limiteC, 1);
        for(i=0; i < limiteC; i++)
        {
            if(!arrayC[i].isEmpty )
            {


                retorno = 0;
            }

        }
    }

    return retorno;
}
