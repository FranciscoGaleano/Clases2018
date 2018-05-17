int informar_listarClientes(Cliente * arrayDeClientes, int limiteC, Aviso * arrayDeAvisos, int limiteA)
{
    int retorno = -1;
    int i;
    int id;
    int cantidadAvisos;

    if(limiteC > 0 && arrayDeClientes != NULL && limiteA > 0 && arrayDeAvisos != NULL)
    {
        for(i = 0; i < limiteC; i++)
        {

            if(arrayDeClientes[i].isEmpty == 0 && arrayDeClientes[i].idCliente == i)
            {
                id = arrayDeClientes[i].idCliente;
                cantidadAvisos = avi_buscarAvisosPorId(arrayDeAvisos, limiteA, &id);
                printf("NOMBRE: %s - APELLIDO: %s - ID: %d - CUIT: %s - AVISOS: %d\n", arrayDeClientes[id].nombre,
                           arrayDeClientes[id].apellido, arrayDeClientes[id].idCliente, arrayDeClientes[id].cuit, cantidadAvisos);
                           retorno = 0;
            }
        }
    }
    return retorno;
}


int informar_publicacionesActivas(Cliente * arrayDeClientes, int limiteC, Aviso * arrayDeAvisos, int limiteA)
{
    int retorno = -1;
    int i;
    int id;
    if(arrayDeAvisos != NULL && limiteA > 0 && arrayDeClientes != NULL && limiteC > 0)
    {
        for(i = 0; i < limiteA; i++)
        {
            if(arrayDeAvisos[i].isEmpty == 0 && arrayDeAvisos[i].estado == 1)
            {
                id = clte_obtenerCuit(arrayDeClientes, limiteC, arrayDeClientes[i].idCliente);
                printf("TEXTO: %s - RUBRO: %d - ESTADO: %d - CUIT Cliente: %s\n", arrayDeAvisos[i].texto, arrayDeAvisos[i].rubro,
                       arrayDeAvisos[i].estado, arrayDeClientes[i].cuit);
                        retorno = 0;
            }
        }
    }
    return retorno;
}

