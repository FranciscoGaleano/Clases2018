#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED
typedef struct
    {
        char nombre[50];
        char apellido[50];
        int edad;
        int idPersona;
        int isEmpty;
    }Alumno;
#endif // ALUMNO_H_INCLUDED
Alumno* new_alumno();
