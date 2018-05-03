#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}Persona;

int per_crear(Persona * arrayDePersonas, int sizeArray);

int per_buscarLibre(Persona * arrayDePersonas, int sizeArray);

int per_alta(Persona * arrayDePersonas, int sizeArray);

int per_graficar(Persona * arrayDePersonas, int sizeArray);


/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
//int obtenerEspacioLibre(Persona lista[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */

//int buscarPorDni(Persona lista[], int dni);


#endif // FUNCIONES_H_INCLUDED
