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



int menu()
{
    int opcion = 0;
    system("cls");
    printf("     *** Veterinaria  ***\n");
    printf("1- Alta Mascota\n");
    printf("2- Modificar Mascota\n");
    printf("3- Baja Mascota\n");
    printf("4- Listar Mascota\n");
    printf("5- Listar Tipos\n");
    printf("6- Listar Colores\n");
    printf("7- Listar servicios\n");
    printf("8- Alta Trabajo\n");
    printf("9- Listar Trabajos\n");
    printf("10- Informes\n");
    printf("11- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    printf("\n");
    return opcion;
}

int altaTrabajo(Mascota lista[],int tam,Tipo tipos[],int tamTipo,Color colores[], int tamCol,Trabajo trabajos[],int tamTra,Servicio servicios[],int tamSer,int* idTrabajos,eCliente clientes[],int tamCli)
{
    int todoOk = 0;
    int indice;
    Trabajo auxTrabajo;
    if (lista != NULL && tam > 0)
    {
        system("cls");
        printf("  ***Alta Trabajo*** \n\n");

        indice = buscarLibreTrabajo(trabajos,tamTra);
        if (indice == -1)
        {
            printf("No hay lugar\n");
        }
        else
        {
            auxTrabajo.id=*idTrabajos;
            (*idTrabajos)++;

            mostrarMascotas(lista,tam,tipos,tamTipo,colores,tamCol,clientes,tamCli);
            printf("\n\nIngrese el ID de la mascota: ");
            scanf("%d", &auxTrabajo.idMascota);

            while(buscarMascotaId(lista,tam,auxTrabajo.idMascota)==-1){

                printf("Ingrese un ID valida para una mascota");
                scanf("%d", &auxTrabajo.idMascota);
            }

            system("cls");

            mostrarServicios(servicios,tamSer);
            printf("Ingrese el servicio que desea: ");
            scanf("%d", &auxTrabajo.idServicio);

            while(auxTrabajo.idServicio<20000&&auxTrabajo.idServicio>20003)
            {
                printf("error, id no valido. Vuelva a ingresar el id del servicio que desea: ");
                scanf("%d", &auxTrabajo.idServicio);
            }

            printf(" ***Ingrese la fecha*** \n ");
            printf("  Formato (dd/mm/aaaa) \n\n");
            printf("Ingrese dia:");
            scanf("%d",&auxTrabajo.fecha.dia);
            printf("Ingrese mes:");
            scanf("%d", &auxTrabajo.fecha.mes);
            printf("Ingrese anio: ");
            scanf("%d", &auxTrabajo.fecha.anio);

          /*  while(!validarFecha(auxTrabajo.fecha.dia,auxTrabajo.fecha.mes,auxTrabajo.fecha.anio))
            {
                printf("Error, ingrese una fecha valida (dd/mm/aaaa): ");
                fflush(stdin);
                scanf("%d/%d/%d", &auxTrabajo.fecha.dia,&auxTrabajo.fecha.mes,&auxTrabajo.fecha.anio);
            }*/

            auxTrabajo.isEmpty = 0;

            trabajos[indice] = auxTrabajo;
            printf("Alta Exitosa !!! \n\n");
            todoOk = 1;
        }
    }
    return todoOk;
}

int buscarLibreTrabajo(Trabajo trabajos[], int tam)
{
    int indice = -1;
    for (int i = 0; i < tam; i++)
    {
        if (trabajos[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int inicializarTrabajos(Trabajo trabajos[], int tam)
{
    int todoOk = 0;
    if (trabajos != NULL && tam > 0)
    {

        for (int i = 0; i < tam; i++)
        {
            trabajos[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int validarFecha(int dia, int mes, int anio)
{
    int todoOk = 0;

    if(
        (dia > 0 && dia < 32) &&
        (mes > 0 && mes < 13) &&
        (anio > 0 && anio < 2022)
       )
    {
        todoOk = 1;
    }

    return todoOk;
}

void mostrarTrabajo(Trabajo unTrabajo,Servicio servicios[],int tamSer,Mascota mascotas[],int tamMascota)
{

    char descMascota[21];
    char descServicio[21];
    traerMascota(mascotas,tamMascota,unTrabajo.idMascota,descMascota);
    traerServicio(servicios,tamSer,unTrabajo.idServicio,descServicio);

   printf("%5d         %7s             %10s            %2d/%d/%d \n",unTrabajo.id,descMascota,descServicio,unTrabajo.fecha.dia,unTrabajo.fecha.mes,unTrabajo.fecha.anio);



}

int mostrarTrabajos(Trabajo trabajos[],int tam,Servicio servicios[],int tamSer,Mascota mascotas[],int tamMasc)
{
    int todoOk = 0;
    int flag = 1;
    if(trabajos != NULL && servicios != NULL && mascotas!= NULL && tam > 0 && tamSer > 0 && tamMasc > 0 )
    {
        system("cls");
        printf("       *** Listado de Trabajos ***      \n");
        printf("------------------------------------------------------------------------------\n");
        printf("   Id         Nombre             Servicio                    Fecha       \n");
        printf("-------------------------------------------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            if(trabajos[i].isEmpty == 0)
            {

                mostrarTrabajo(trabajos[i],servicios,tamSer,mascotas,tamMasc);
                flag = 0;

            }
        }
        if(flag)
        {
            printf("No hay trabajos para mostrar, \n se debe dar de alta algun trabajo antes de poder mostrarlo.\n");

        }
        todoOk=1;

    }

    return todoOk;
}


int buscarTrabajoId(Trabajo trabajos[], int tam, int id)
{
    int indice = -1;
    for (int i = 0; i < tam; i++)
    {
        if (trabajos[i].id == id && trabajos[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}



