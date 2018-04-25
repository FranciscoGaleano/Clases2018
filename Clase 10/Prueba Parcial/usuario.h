#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

typedef struct
    {
        char nombre[50];
        char apellido[50];
        char password[50];
        int usuarioId;
        int isEmpty;
    }Usuario;



#endif // USUARIO_H_INCLUDED
