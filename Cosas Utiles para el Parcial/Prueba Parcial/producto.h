#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

typedef struct
    {
        char nombre[50];
        char marca[50];
        float precio;
        int calificacion;
        int productoId;
        int usuarioId;
        int isEmpty;
    }Producto;



#endif // PRODUCTO_H_INCLUDED
