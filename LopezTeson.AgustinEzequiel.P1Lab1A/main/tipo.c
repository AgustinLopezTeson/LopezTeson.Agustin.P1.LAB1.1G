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


int mostrarTipos(Tipo tipos[], int tam)
{
    int todoOk = 0;
    if (tipos != NULL && tam > 0 )
    {
        system("cls");
        printf("      *** Listado de tipos *** \n\n");
        printf("  Id         Descripcion\n");
        for (int i = 0; i < tam; i++)
        {
            printf("  %d       %-10s\n",tipos[i].id,tipos[i].descripcion);
        }
        printf("\n\n");
        todoOk = 1;
    }

    return todoOk;
}


int traerTipo(Tipo tipos[], int tamTipo, int idTipo, char descTipo[])
{
        int todoOk = 0;
    if(tipos != NULL && tamTipo > 0 && descTipo != NULL){

         for(int i= 0; i < tamTipo; i++){

            if( tipos[i].id == idTipo){
                strcpy( descTipo, tipos[i].descripcion);
                todoOk = 1;
                break;
            }

         }
    }
    return todoOk;
}

int mostrarMascotaColor(Mascota lista[],int tam,Tipo tipos[], Color colores[], int tamcol,int tamTipo, eCliente clientes[], int tamCli)
{
    int todoOk=0;
    int flag=1;

    if(lista != NULL && colores != NULL && tipos != NULL && tam > 0 && tamTipo > 0 && tamcol > 0 )
    {
        int idColor;
        char descColor[20];



        mostrarColores(colores,tamcol);
        printf("\n\n");
        printf("Ingrese el id del color que desea  : ");
        scanf("%d", &idColor);
        while(idColor<5000||idColor>5004)
        {
            printf("error. id ingresado no valido\n");
            printf("Ingrese id del Color que desea  : ");
            scanf("%d", &idColor);
        }


        traerColor(colores,tamcol,idColor,descColor);

        printf("       *** Listado de mascotas de color  %s***      \n",descColor);
        printf("---------------------------------------------------------------------------------------------\n");
        printf("   Id         Nombre           Tipo       Color        edad       Vacunado         Cliente\n");
        printf("---------------------------------------------------------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 0&&lista[i].idColor==idColor)
            {
                mostrarMascota(lista[i],tipos,colores,tamTipo,tamcol,clientes,tamCli);
                flag = 0;

            }
        }
        if(flag)
        {
            printf("No hay mascotas para mostrar de ese color.\n");

        }
        system("pause");
        todoOk=1;
    }

    return todoOk;


}



