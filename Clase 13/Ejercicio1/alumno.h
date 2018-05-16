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
void alumno_delete(Alumno* this);
int  alumno_setEdad(Alumno* this, int edad);
int alumno_getEdad(Alumno* this, int* edad);
void cargar(Alumno** array,int cantidad);
void mostrar(Alumno* array[],int cantidad);
