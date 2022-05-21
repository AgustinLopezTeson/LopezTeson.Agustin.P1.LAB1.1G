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

#define TAM 20
#define TAMTIPO 5
#define TAMCOL 5
#define TAMSER 3


int mostrarColores(Color colores[], int tam)
{
     int todoOk = 0;
    if (colores != NULL && tam > 0 )
    {
        system("cls");
        printf("      *** Listado de colores *** \n\n");
        printf("  Id         Nombre Color\n");
        for (int i = 0; i < tam; i++)
        {
            printf("  %d       %-10s\n",colores[i].id,colores[i].nombreColor);
        }
        printf("\n\n");
        todoOk = 1;
    }

    return todoOk;
}

int traerColor(Color colores[], int tamCol, int idColor , char descColor[])
{
    int todoOk = 0;
	if(colores!= NULL && tamCol > 0 && descColor != NULL)
	{
		for(int i = 0; i < tamCol; i++)
		{
			if(colores[i].id == idColor)
			{
				strcpy(descColor, colores[i].nombreColor);
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}
