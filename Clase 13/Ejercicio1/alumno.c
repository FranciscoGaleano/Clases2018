#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"

Alumno* alumno_new()
{
    return malloc(sizeof(Alumno));
}

void alumno_delete(Alumno* this)
{
    free(this);
}

