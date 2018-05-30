#include <stdio.h>
#include <stdlib.h>
#include "pelicula.h"

Pelicula * pelicula_new()
{
    return malloc(sizeof(Pelicula));
}

void pelicula_delete(Pelicula* this)
{
    free(this);
}

int pelicula_setTitulo(Pelicula* this, char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL && isValidString(titulo))
    {
        retorno = 0;
        strcpy(this->titulo, titulo);
    }
    return retorno;
}

int pelicula_getTitulo(Pelicula* this, char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL)
    {
        retorno = 0;
        strcpy(titulo, this->titulo);
    }
    return retorno;
}

int pelicula_setGenero(Pelicula* this, char* genero)
{
    int retorno = -1;
    if(this != NULL && genero != NULL && isValidString(genero))
    {
        retorno = 0;
        strcpy(this->genero, genero);
    }
    return retorno;
}

int pelicula_getGenero(Pelicula* this, char* genero )
{
    int retorno = -1;
    if(this != NULL && genero != NULL)
    {
        retorno = 0;
        strcpy(genero, this->genero);
    }
    return retorno;
}
int pelicula_setDuracion(Pelicula* this, char* duracion)
{
    int retorno = -1;
    float auxiliar;
    if(this != NULL && duracion != NULL && isValidDuracion(duracion))
    {
        retorno = 0;
        auxiliar = atof(duracion);
        this->duracion = auxiliar;
    }
    return retorno;
}

int pelicula_getDuracion(Pelicula* this, char * duracion)
{
    int retorno = -1;
    float auxiliar;
    if(this != NULL && duracion != NULL)
    {
        retorno = 0;
        auxiliar = atof(duracion);
        auxiliar = this->duracion;
    }
    return retorno;
}

int pelicula_setDescripcion(Pelicula* this, char* descripcion)
{
    int retorno = -1;
    if(this != NULL && descripcion != NULL && isValidString(descripcion))
    {
        retorno = 0;
        strcpy(this->descripcion, descripcion);
    }
    return retorno;
}

int pelicula_getDescripcion(Pelicula* this, char* descripcion)
{
    int retorno = -1;
    if(this != NULL && descripcion != NULL)
    {
        retorno = 0;
        strcpy(descripcion, this->descripcion);
    }
    return retorno;
}

int pelicula_setPuntaje(Pelicula* this, char* puntaje)
{
    int retorno = -1;
    float auxiliar;
    if(this != NULL && puntaje != NULL && isValidPuntaje(puntaje))
    {
        retorno = 0;
        auxiliar = atof(puntaje);
        this->puntaje = auxiliar;
    }
    return retorno;
}

int pelicula_getPuntaje(Pelicula* this, char* puntaje)
{
    int retorno = -1;
    float auxiliar;
    if(this != NULL && puntaje != NULL)
    {
        retorno = 0;
        auxiliar = atof(puntaje);
        auxiliar = this->puntaje;
    }
    return retorno;
}

int pelicula_setLinkImagen(Pelicula* this, char* linkImagen)
{
    int retorno = -1;
    if(this != NULL && linkImagen != NULL && isValidString(linkImagen))
    {
        retorno = 0;
        strcpy(this->linkImagen, linkImagen);
    }
    return retorno;
}

int pelicula_getLinkImagen(Pelicula* this, char* linkImagen)
{
    int retorno = -1;
    if(this != NULL && linkImagen != NULL)
    {
        retorno = 0;
        strcpy(linkImagen, this->linkImagen);
    }
    return retorno;
}

int pelicula_add(Pelicula* this, )

 char titulo[50];
    char genero[50];
    float duracion;
    char descripcion[200];
    float puntaje;
    char linkImagen[100];



