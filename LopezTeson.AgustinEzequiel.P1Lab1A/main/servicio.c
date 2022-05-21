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


int mostrarServicios(Servicio servicios[], int tam)
{
    int todoOk = 0;
    if (servicios != NULL && tam > 0 )
    {
        system("cls");
        printf("      *** Listado de servicios *** \n\n");
        printf("  Id         Descripcion           Precio\n");
        for (int i = 0; i < tam; i++)
        {
            printf("  %d       %-14s       $%.2f \n",servicios[i].id,servicios[i].descripcion,servicios[i].precio);
        }
        printf("\n\n");
        todoOk = 1;
    }

    return todoOk;
}

int traerServicio(Servicio servicios[],int tamSer,int idServicio,char descServicio[])
{
    int todoOk=0;
    if(servicios != NULL && tamSer > 0 && descServicio != NULL){

         for(int i= 0; i < tamSer; i++){

            if( servicios[i].id == idServicio){
                strcpy( descServicio, servicios[i].descripcion);
                todoOk = 1;
                break;
            }

         }
    }


    return todoOk;
}
