#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED

typedef struct
{
    char titulo[50];
    char genero[50];
    float duracion;
    char descripcion[200];
    float puntaje;
    char linkImagen[100];
    int idPelicula;
}Pelicula;



#endif // PELICULA_H_INCLUDED
