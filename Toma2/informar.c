#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "aviso.h"
#include "informar.h"

/** \brief Realiza un listado de Clientes y sus datos, sumado a cuantos Avisos tienen
 *
 * \param arrayDeClientes Cliente* Puntero al array de Clientes con el que vamos a trabajar
 * \param limiteC int Dimension del array de Clientes
 * \param arrayDeAvisos Aviso* Puntero al array de Avisos con el que vamos a trabajar
 * \param limiteA int Dimension del array de Avisos
 * \return int Devuelve 0 si funciona de manera correcta, -1 si no funciona
 *
 */
int informar_listarClientes(Cliente * arrayDeClientes, int limiteC, Aviso * arrayDeAvisos, int limiteA)
{
    int retorno = -1;
    int i;
    int id;
    int cantidadAvisos;

    if(limiteC > 0 && arrayDeClientes != NULL && limiteA > 0 && arrayDeAvisos != NULL)
    {
        for(i = 0; i < limiteC; i++)
        {
            if(arrayDeClientes[i].isEmpty == 0 && arrayDeClientes[i].idCliente == i)
            {
                id = arrayDeClientes[i].idCliente;
                cantidadAvisos = avi_buscarAvisosPorId(arrayDeAvisos, limiteA, &id);
                printf("NOMBRE: %s - APELLIDO: %s - ID: %d - CUIT: %s - AVISOS: %d\n", arrayDeClientes[id].nombre,
                           arrayDeClientes[id].apellido, arrayDeClientes[id].idCliente, arrayDeClientes[id].cuit, cantidadAvisos);
                           retorno = 0;
            }
        }
    }
    return retorno;
}


/** \brief Devuelve una lista de Avisos activos y sus datos, sumado al ID del Cliente
 *
 * \param arrayDeClientes Cliente* Puntero al array de Clientes con el que vamos a trabajar
 * \param limiteC int Dimension del array de Clientes
 * \param arrayDeAvisos Aviso* Puntero al array de Avisos con el que vamos a trabajar
 * \param limiteA int Dimension del array de Avisos
 * \return int Devuelve 0 si funciona de manera correcta, -1 si no funciona
 *
 */
int informar_avisosActivos(Cliente * arrayDeClientes, int limiteC, Aviso * arrayDeAvisos, int limiteA)
{
    int retorno = -1;
    int i;
    int id;
    if(arrayDeAvisos != NULL && limiteA > 0 && arrayDeClientes != NULL && limiteC > 0)
    {
        for(i = 0; i < limiteA; i++)
        {
            if(arrayDeAvisos[i].isEmpty == 0 && arrayDeAvisos[i].estado == 1)
            {
                id = clte_obtenerID(arrayDeClientes, limiteC, arrayDeAvisos[i].idCliente);
                printf("TEXTO: %s - RUBRO: %d - ESTADO: %d - CUIT Cliente: %s\n", arrayDeAvisos[i].texto, arrayDeAvisos[i].rubro,
                       arrayDeAvisos[i].estado, arrayDeClientes[id].cuit);
                        retorno = 0;
            }
        }
    }
    return retorno;
}


int informar_cantidadAvisosPorCliente(Cliente * arrayDeClientes, int limiteC, Aviso * arrayDeAvisos, int limiteA)
{
    int retorno = -1;
    int i;
    int j;
    int id;
    int mostrar;

    if(arrayDeAvisos != NULL && limiteA > 0 && arrayDeClientes != NULL && limiteC > 0)
    {
        for(i = 0; i < limiteC; i++)
        {
            if(arrayDeClientes[i].isEmpty == 0)
            {
                id = arrayDeClientes[i].idCliente;
                mostrar = avi_buscarAvisosPorId(arrayDeAvisos, limiteA, &id);
                for(j = 0; j < limiteA; j++)
                {
                    if(arrayDeAvisos[j].isEmpty == 0 && arrayDeClientes[j].idCliente == arrayDeClientes[i].idCliente)
                    {
                        printf("El cliente %s %s tiene %d avisos.\n", arrayDeClientes[i].nombre, arrayDeClientes[i].apellido,
                               mostrar);
                               retorno = 0;
                               break;
                    }
                }
            }
        }
    }
    return retorno;
}

int informar_clienteConMasAvisos(Cliente* arrayDeClientes, int limiteC, Aviso* arrayDeAvisos,int limiteA)
{
    int retorno = -1;
    int i;
    int j;
    int aux;
    int contador = 0;
    int mayor = 0;
    if(arrayDeAvisos != NULL && limiteA > 0 && arrayDeClientes != NULL && limiteC > 0)
    {

        for(i = 0; i < limiteC; i++)
        {
            if(contador > mayor)
            {
                mayor = contador;
                aux = i-1;
            }
            contador = 0;
            for(j = 0; j < limiteA; j++)
            {
                if(arrayDeAvisos[j].isEmpty == 0 && arrayDeAvisos[j].idCliente == arrayDeClientes[i].idCliente)
                {
                    contador++;
                    retorno = 0;
                }
            }
        }
    }
    printf("El cliente con mas avisos es %s %s con %d avisos.\n",arrayDeClientes[aux].nombre,
           arrayDeClientes[aux].apellido, mayor);
    return retorno;
}


int informar_clienteConMasAvisosActivos(Cliente* arrayDeClientes,int limiteC, Aviso* arrayDeAvisos, int limiteA)
{
    int retorno = -1;
    int i;
    int j;
    int aux;
    int contador = 0;
    int mayor = 0;
    if(arrayDeAvisos != NULL && limiteA > 0 && arrayDeClientes != NULL && limiteC > 0)
    {
        for(i = 0; i < limiteC ; i++)
        {
            if(contador > mayor)
            {
                mayor = contador;
                aux = i - 1;
            }
            contador = 0;
            for(j = 0; j < limiteA; j++)
            {
                if(arrayDeAvisos[j].isEmpty == 0 && arrayDeAvisos[j].idCliente == arrayDeClientes[i].idCliente && arrayDeAvisos[j].estado == 1)
                {
                    contador++;
                    retorno = 0;
                }
            }
        }
    }
    printf("El cliente con mas avisos activos es %s %s con %d.\n",arrayDeClientes[aux].nombre,
                   arrayDeClientes[aux].apellido, mayor);
    return retorno;
}

int informar_clienteConMasAvisosPausados(Cliente* arrayDeClientes, int limiteC, Aviso* arrayDeAvisos, int limiteA)
{
    int retorno = -1;
    int i;
    int j;
    int aux;
    int contador = 0;
    int mayor = 0;
    if(arrayDeAvisos != NULL && limiteA > 0 && arrayDeClientes != NULL && limiteC > 0)
    {
        for(i = 0; i < limiteC; i++)
        {
            if(contador > mayor)
            {
                mayor = contador;
                aux = i - 1;
            }
            contador = 0;
            for(j = 0; j < limiteA; j++)
            {
                if(arrayDeAvisos[j].isEmpty == 0 && arrayDeAvisos[j].idCliente == arrayDeClientes[i].idCliente && arrayDeAvisos[j].estado == 0)
                {
                    contador++;
                    retorno = 0;
                }
            }
        }
    }
    if(contador == 0)
    {
        printf("No hay avisos pausados.\n");
    }
    else
    {
        printf("El cliente con mas avisos pausados es %s %s con %d\n",arrayDeClientes[aux].nombre,
               arrayDeClientes[aux].apellido, mayor);

    }
    return retorno;
}

int informar_seleccionDeInformeDeClientes(Cliente * arrayDeClientes, int limiteC, Aviso * arrayDeAvisos, int limiteA)
{
    int retorno = -1;
    char respuesta = 's';
    int menu;
    do
    {
        printf("Que informe desea ver?\n");
        printf("Cliente con mas avisos activos      -> Ingrese 1\n");
        printf("Cliente con mas avisos pausados     -> Ingrese 2\n");
        printf("Cliente con mas avisos totales      -> Ingrese 3\n");
        scanf("%d", &menu);
        switch(menu)
        {
            case 1:
                informar_clienteConMasAvisosActivos(arrayDeClientes, limiteC, arrayDeAvisos, limiteA);
                fflush(stdin);
                printf("Desea ver otro informe? S/N\n");
                scanf("%c", &respuesta);
                break;
            case 2:
                informar_clienteConMasAvisosPausados(arrayDeClientes, limiteC, arrayDeAvisos, limiteA);
                fflush(stdin);
                printf("Desea ver otro informe? S/N\n");
                scanf("%c", &respuesta);
                break;
            case 3:
                informar_clienteConMasAvisos(arrayDeClientes, limiteC, arrayDeAvisos, limiteA);
                fflush(stdin);
                printf("Desea ver otro informe? S/N\n");
                scanf("%c", &respuesta);
                break;
            default:
                printf("Ingrese una opcion valida.\n");
                break;
        }
        retorno = 0;
    }while(respuesta == 's');
    return retorno;
}

int informar_cantidadAvisosPorRubro(Aviso* arrayDeAvisos, int limiteA)
{
    int retorno = -1;
    int i;
    int rubro;
    int contador = 0;
    do
    {
        printf("Ingrese el rubro del que desea. [1/2/3/4]\n");
        scanf("%d", &rubro);
    }while(rubro != 1 && rubro != 2 && rubro != 3 && rubro != 4);
    if(limiteA > 0 && arrayDeAvisos != NULL)
    {
        for(i = 0; i < limiteA; i++)
        {
            if(arrayDeAvisos[i].isEmpty == 0 && arrayDeAvisos[i].rubro == rubro)
            {
                contador++;
                retorno = 0;
            }
        }
    }
    printf("El rubro ingresado tiene %d avisos.\n", contador);
    return retorno;
}

int informar_rubroConMasAvisosActivos(Aviso* arrayDeAvisos, int limiteA)
{
    int retorno = -1;
    int i;
    int j;
    int aux;
    int mayor = 0;
    int contador = 0;
    if(limiteA > 0 && arrayDeAvisos != NULL)
    {
        for(i = 0; i < limiteA; i++)
        {
            if(contador > mayor)
            {
                mayor = contador;
                aux = i - 1;
            }
            contador = 0;
            for(j = i + 1; j < limiteA; j++)
            {
                if(arrayDeAvisos[j].isEmpty == 0 && arrayDeAvisos[j].estado == 1 && arrayDeAvisos[j].rubro == arrayDeAvisos[i].rubro)
                {
                    contador++;
                    retorno = 0;
                }
            }
        }
    }
    printf("El rubro con mas avisos activos es el %d con %d avisos \n",arrayDeAvisos[aux].rubro, mayor);
    return retorno;
}


int informar_rubroConMenosAvisosActivos(Aviso* arrayDeAvisos, int limiteA)
{
    int retorno = -1;
    int i;
    int j;
    int aux;
    int contador = 0;
    int mayor = 0;
    if(limiteA > 0 && arrayDeAvisos != NULL)
    {
        for(i = 0; i < limiteA; i++)
        {
            if(contador < mayor)
            {
                mayor = contador;
                aux = i - 1;
                //aux = i;
            }
            contador = 0;
            for(j = i + 1; j < limiteA; j++)
            {
                if(arrayDeAvisos[j].isEmpty == 0 && arrayDeAvisos[j].estado == 1 && arrayDeAvisos[j].rubro == arrayDeAvisos[i].rubro)
                {
                    contador++;
                    retorno = 0;
                }
            }
        }
    }
    printf("El rubro con menos avisos activos es el %d con %d avisos \n",arrayDeAvisos[aux].rubro, mayor);
    return retorno;
}

int informar_seleccionDeInformeDeRubros(Cliente * arrayDeClientes, int limiteC, Aviso * arrayDeAvisos, int limiteA)
{
    int retorno = -1;
    char respuesta = 's';
    int menu;
    do
    {
        printf("Que informe desea ver?\n");
        printf("Cantidad de avisos por rubro        -> Ingrese 1\n");
        printf("Rubro con mas avisos activos        -> Ingrese 2\n");
        printf("Rubro con menos avisos activos      -> Ingrese 3\n");
        scanf("%d", &menu);
        switch(menu)
        {
            case 1:
                informar_cantidadAvisosPorRubro(arrayDeAvisos, limiteA);
                fflush(stdin);
                printf("Desea ver otro informe? S/N\n");
                scanf("%c", &respuesta);
                break;
            case 2:
                informar_rubroConMasAvisosActivos(arrayDeAvisos, limiteA);
                fflush(stdin);
                printf("Desea ver otro informe? S/N\n");
                scanf("%c", &respuesta);
                break;
            case 3:
                informar_rubroConMenosAvisosActivos(arrayDeAvisos, limiteA);
                fflush(stdin);
                printf("Desea ver otro informe? S/N\n");
                scanf("%c", &respuesta);
                break;
            default:
                printf("Ingrese una opcion valida.\n");
                break;
        }
        retorno = 0;
    }while(respuesta == 's');
    return retorno;
}
