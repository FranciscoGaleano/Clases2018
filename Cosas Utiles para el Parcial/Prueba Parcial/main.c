#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"
#include "producto.h"
#include "compra.h"
#define QTY 50

int main()
{

   /*1) llamo a una funcion que me de de alta una lista de usuarios (user_crear) y me muestre sus datos. el isEmpty es ahora 0
   2) llamo a una funcion donde, sabiendo la Id del usuario, me permite modificar sus datos (user_modificar)
   3) llamo a una funcion donde, sabiendo la Id del usuario, me permite darlo de baja. el isEmpty vuelve a 1
   4) llamo a una funcion donde, sabiendo la Id del usuario, me permite ingresar los datos del producto (prod_crear). el isEmpty es ahora 0 -esto es la tbn la venta-
   5) llamo a una funcion donde, sabiendo la Id del usuario, me muestre los productos ingresados y que luego, sabiendo la Id del producto, me permita modificarlo (prod_modificar)
   6) llamo a una funcion donde, sabiendo la Id del usuario, me muestre los productos ingresados y que luego, sabiendo la Id del produco, me permite darlo de baja. el isEmpty vuelve a 1
   7) llamo a una funcion donde, sabiendo la Id del producto, me permite comprarlo si hay stock y calificar al usuario (vent_comprar) -revisar estructura-
   8) llamo a una funcion donde, sabiendo la Id del usuario, me muestre los productos que haya dado de alta (prod_mostrar)
   9) llamo a una funcion que me muestre la lista de publicaciones (vent_mostrar)
   10) llamo a una funcion que me muestre la lista de usuarios y el promedio de las calificaciones*/

    Usuario listaDeUsuarios[QTY];
    Producto listaDeProductos[QTY];
    int opcion;
    int usuarioId;
    int productoId;

    user_crear(listaDeUsuarios, QTY);
    //user_buscarLibre(listaDeUsuarios, QTY);
    //user_alta(listaDeUsuarios, QTY);
    user_alta(listaDeUsuarios, QTY);
    //user_baja(listaDeUsuarios, QTY, &usuarioId);
    //user_mostrar(listaDeUsuarios, QTY);
    user_modificar(listaDeUsuarios, QTY);
    user_mostrar(listaDeUsuarios, QTY);


    /*prod_crear(listaDeProductos, QTY);
    prod_buscarLibre(listaDeProductos, QTY);
    prod_alta(listaDeProductos, QTY);
    prod_mostrar(listaDeProductos, QTY);
    prod_baja(listaDeProductos, QTY, &productoId);
    prod_mostrar(listaDeProductos, QTY);*/

    return 0;
}
