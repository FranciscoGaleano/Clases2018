#include <stdio.h>
#include <stdlib.h>
#include "pelicula.h"

static int pelicula_setId(Pelicula *this, int id);

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
    if(this != NULL && duracion != NULL && isValidFloat(duracion))
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
    if(this != NULL && puntaje != NULL && isValidFloat(puntaje))
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

static int pelicula_setId(Pelicula *this, int idPelicula)
{
    int retorno = -1;
    static int maximoId = -1;
    if(this != NULL)
    {
        if(idPelicula >= 0)
        {
            if(idPelicula > maximoId)
                maximoId = idPelicula;
            this->idPelicula = idPelicula;
        }
        else
        {
            maximoId++;
            this->idPelicula = maximoId;
        }
        retorno = 0;
    }
    return retorno;
}

int pelicula_getId(Pelicula *this, int* idPelicula)
{
    int retorno = -1;
    if(this != NULL && idPelicula != NULL)
    {
        *idPelicula = this->idPelicula;
        retorno = 0;
    }
    return retorno;
}

Pelicula* pelicula_crear(char* titulo, char* genero, char* duracion, char* descripcion, char* puntaje, char* linkImagen)
{
    Pelicula *arrayPelicula = pelicula_new();

    pelicula_setTitulo(arrayPelicula, titulo);
    pelicula_setDescripcion(arrayPelicula, descripcion);
    pelicula_setDuracion(arrayPelicula, duracion);
    pelicula_setGenero(arrayPelicula, genero);
    pelicula_setLinkImagen(arrayPelicula, linkImagen);
    pelicula_setPuntaje(arrayPelicula, puntaje);

    return arrayPelicula;
}

int pelicula_alta(Pelicula ** arrayDePeliculas, int *sizeArray)
{
    int retorno = -1;
    char auxiliarTitulo[100];
    char auxiliarGenero[50];
    char auxiliarDuracion[20];
    char auxiliarDescripcion[200];
    char auxiliarPuntaje[10];
    char auxiliarLink[200];
    if(arrayDePeliculas != NULL && *sizeArray > -1)
    {
        if(getString("Ingrese el Titulo de la pelicula\n", auxiliarTitulo))
        {
            if(getString("Ingrese el Genero de la pelicula\n", auxiliarGenero))
            {
                if(getString("Ingrese una Descripcion para la pelicula\n", auxiliarDescripcion))
                {
                    if(!getValidFloat("Ingrese la Duracion de la pelicula\n", "Error. Intente de nuevo\n", &auxiliarDuracion, 30, 250, 2))
                    {
                        if(!getValidString("Ingrese el Link de imagen de la pelicula.", "Error. Intente de nuevo\n", "Error. Se excede la dimension. Intente de nuevo\n", auxiliarLink, 200, 2))
                        {
                            if(!getValidFloat("Inngrese un Puntaje para la pelicula\n", "Error. Intente de nuevo\n", &auxiliarPuntaje, 1, 10, 2))
                            {
                                arrayDePeliculas[*sizeArray] = pelicula_crear(auxiliarTitulo, auxiliarGenero, auxiliarDuracion, auxiliarDescripcion, auxiliarPuntaje, auxiliarLink);
                                *sizeArray = *sizeArray + 1;
                                retorno = 0;
                            }
                        }
                    }
                }
            }
        }
    }
    return retorno;
}

int pelicula_baja(Pelicula **arrayPeliculas, int *sizeArray, int idPelicula)
{
    int retorno = -1;
    int i;
    int j;
    int auxiliarId;
    if(arrayPeliculas != NULL && *sizeArray > 0)
    {
        if(idPelicula >= 0)
        {
            for(i = 0; i < *sizeArray; i++)
            {
                pelicula_getId(arrayPeliculas[i], &auxiliarId);
                if(auxiliarId == idPelicula)
                {
                    retorno = 0;
                    break;
                }
            }
            if(retorno == 0)
            {
                if(i < *sizeArray)
                {
                    for(j = i; i < *sizeArray; i++)
                    {
                        arrayPeliculas[i] = arrayPeliculas[i+1];
                    }
                }
                pelicula_delete(arrayPeliculas[*sizeArray]);
                *sizeArray = *sizeArray - 1;
            }
        }
    }
    return retorno;
}


int pelicula_modificar(Pelicula **arrayPeliculas, int *sizeArray, int idPelicula)
{
    int retorno = -1;
    char auxiliarTitulo[100];
    char auxiliarGenero[50];
    char auxiliarDuracion[20];
    char auxiliarDescripcion[200];
    char auxiliarPuntaje[20];
    char auxiliarLinkImagen[200];
    int posicion;
    int i;
    int auxiliarId;

    if(arrayPeliculas != NULL && *sizeArray > 0)
    {
        if(idPelicula >= 0)
        {
            for(i = 0; i < *sizeArray; i++)
            {
                pelicula_getId(arrayPeliculas[i], &auxiliarId);
                if(auxiliarId == idPelicula)
                {
                    posicion = i;
                    retorno = 0;
                    break;
                }
            }
            if(retorno == 0)
            {
                if(getString("Ingrese el nuevo Titulo\n", auxiliarTitulo))
                {
                    if(getString("Ingrese el nuevo Genero\n", auxiliarGenero))
                    {
                        if(getString("Ingrese la nueva Descripcion\n", auxiliarDescripcion))
                        {
                            if(!getValidFloat("Ingrese la nueva Duracion\n", "Error. Intente de nuevo\n", &auxiliarDuracion, 30, 250, 2))
                            {
                                if(!getValidString("Ingrese el nuevo Link de la imagen\n", "Error. Intente de nuevo\n", "Error. Se excede la dimension. Intente de nuevo\n", auxiliarLinkImagen, 200, 2))
                                {
                                    if(!getValidFloat("Ingrese el nuevo Puntaje:\n", "Error. Intente de nuevo\n", &auxiliarPuntaje, 1, 10, 2))
                                    {
                                        arrayPeliculas[i] = pelicula_crear(auxiliarTitulo, auxiliarGenero, auxiliarDuracion, auxiliarDescripcion, auxiliarPuntaje, auxiliarLinkImagen);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return retorno;
}

