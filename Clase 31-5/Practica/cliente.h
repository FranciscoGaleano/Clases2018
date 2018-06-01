#ifndef _CLIENTE_H
#define _CLIENTE_H
struct
{
    char nombre[64];
    char apellido[64];
    char email[256];
    char genero;
    char profesion[256];
    char nacionalidad[256];
    int id;
    char usuario[256];
}typedef Cliente;
#endif // _CLIENTE_H

Cliente * cliente_new();
void cliente_delete(Cliente* this);
Cliente * cliente_newParametros(char* nombre, char* apellido);
Cliente * cliente_listar(Cliente * pArrayClientes);
int cliente_setNombre(Cliente* this, char* nombre);
int cliente_getNombre(Cliente* this, char* apellido);
int cliente_setApellido(Cliente* this, char* apellido);
int cliente_getApellido(Cliente* this, char* apellido);
