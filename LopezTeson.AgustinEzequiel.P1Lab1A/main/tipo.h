#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED
#include "mascota.h"
typedef struct
{
    int id;
    char descripcion[20];
}Tipo;

int mostrarTipos(Tipo tipos[], int tam);
int traerTipo(Tipo tipos[], int tamTipo, int idTipo, char descTipo[]);
//int mostrarMascotaColor(Mascota lista[],int tam,Tipo tipos[], Color colores[], int tamcol,int tamTipo, eCliente clientes[], int tamCli);

#endif // TIPO_H_INCLUDED
