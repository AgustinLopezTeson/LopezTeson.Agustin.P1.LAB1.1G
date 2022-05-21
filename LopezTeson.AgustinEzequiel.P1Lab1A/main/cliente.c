#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"
#include "servicio.h"
#include "trabajo.h"
#include "fecha.h"
#include "tipo.h"
#include "mascota.h"
#include "cliente.h"


int idCliente[10]={500,501,502,503,504,505,506,507,508};
char nombresCli [10][21] = {
            {"Juan"},
            {"Luis"},
            {"Tamara"},
            {"Maria"},
            {"Cristian"},
            {"Marisa"},
            {"Roberto"},
            {"Pedro"}

                                };

char sexos [10]={'m','m','f','f','m','f','m'};


int hardcodearCliente(eCliente clientes[],int tamCli,int cantidad,int* idCliente)
{
    int contador = -1;
    if(clientes != NULL && tamCli > 0 && cantidad >= 0 && cantidad <= tamCli && idCliente != NULL)
    {
        contador = 0;
        for(int i = 0; i < cantidad; i++)
        {
            clientes[i].idCliente = *idCliente;
            strcpy(clientes[i].nombre,nombresCli[i]) ;
            clientes[i].sexo= sexos[i];
            clientes[i].isEmpty = 0;
            (*idCliente)++;
            contador++;
        }
    }
    return contador;



}

int inicializarClientes(eCliente clientes[],int tamCli)
{
    int todoOk = 0;
    if (clientes != NULL && tamCli > 0)
    {
        todoOk = 1;
        for (int i = 0; i < tamCli; i++)
        {
            clientes[i].isEmpty = 1;
        }
    }
    return todoOk;
}

int traerCliente(eCliente clientes[], int tamCli, int idCliente , char descCliente[])
{
    int todoOk = 0;
	if(clientes!= NULL && tamCli > 0 && descCliente != NULL)
	{
		for(int i = 0; i < tamCli; i++)
		{
			if(clientes[i].idCliente == idCliente)
			{
				strcpy(descCliente, clientes[i].nombre);
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}

int mostrarCliente(eCliente clientes[], int tam)
{
    int todoOk = 0;
    if (clientes != NULL && tam > 0 )
    {
        system("cls");
        printf("      *** Listado de clientes *** \n\n");
        printf("  Id         Nombre           Sexo\n");
        for (int i = 0; i < tam; i++)
        {
            printf("  %d       %-14s       %c \n",clientes[i].idCliente,clientes[i].nombre,clientes[i].sexo);
        }
        printf("\n\n");
        todoOk = 1;
    }

    return todoOk;
}
