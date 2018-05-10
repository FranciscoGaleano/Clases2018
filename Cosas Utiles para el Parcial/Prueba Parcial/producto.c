#include <stdio.h>
#include <stdlib.h>
#include "producto.h"

int prod_crear(Producto * arrayDeProductos, int sizeArray)
{
    int i = 0;
    for(i = 0; i < sizeArray; i++)
    {
        arrayDeProductos[i].isEmpty = 1;
    }
}

int prod_buscarLibre(Producto * arrayDeProductos, int sizeArray)
{
    int i;
    for(i = 0; i < sizeArray; i++)
    {
        if(arrayDeProductos[i].isEmpty = 1)
        {
            printf("La posicion %d esta libre para usarse.\n", i);
        }
    }
}

int prod_alta(Producto * arrayDeProductos, int sizeArray)
{
    int i;
    int j;
    for(i = 0; i < sizeArray; i++)
    {
        if(arrayDeProductos[i].isEmpty == 1)
        {
            printf("Ingrese el nombre del producto.\n");
            fflush(stdin);
            gets(arrayDeProductos[i].nombre);
            printf("Ingrese la marca del producto.\n");
            fflush(stdin);
            gets(arrayDeProductos[i].marca);
            arrayDeProductos[i].productoId = i + 10;
            arrayDeProductos[i].isEmpty = 0;
            break;
        }
        else{
            while(arrayDeProductos[i].isEmpty == 0)
            {
                break;
            }
        }
    }
}

int prod_mostrar(Producto * arrayDeProductos,int sizeArray)
{
    int i;
    for(i = 0; i < sizeArray; i++)
    {
        if(arrayDeProductos[i].isEmpty == 0)
        {
             printf("El producto se llama %s %s, con ID %d\n", arrayDeProductos[i].nombre, arrayDeProductos[i].marca, arrayDeProductos[i].productoId);
             break;
        }
    }
}

int prod_baja(Producto * arrayDeProductos, int sizeArray, int * productoId)
{
    int aux;
    aux = *productoId;

    printf("Que producto desea eliminar?\n");
    scanf("%d", &aux);
    if(aux < sizeArray && arrayDeProductos[aux].isEmpty == 0)
    {
        arrayDeProductos[aux].isEmpty = 1;
        printf("Se dio de baja a %s %s, con el ID %d.\n", arrayDeProductos[aux].nombre, arrayDeProductos[aux].marca, arrayDeProductos[aux].usuarioId);
    }


}
