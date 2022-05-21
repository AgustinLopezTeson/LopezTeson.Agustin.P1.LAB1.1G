#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"
#include "servicio.h"
#include "trabajo.h"
#include "fecha.h"
#include "tipo.h"
#include "mascota.h"
#include "data.h"

#define TAM 20
#define TAMTIPO 5
#define TAMCOL 5
#define TAMSER 3


char nombres [10][21] = {
            {"Pepe"},
            {"Lula"},
            {"Maylo"},
            {"Tato"},
            {"Tati"},
            {"Simon"},
            {"Hugo"}

                                };


char vacunados [10]={'s','n','s','n','n','s','n'};
int colores[8] = {5001, 5002, 5000, 5001, 5001, 5003, 5004};
int tipos[8] = {1001, 1002, 1000, 1001, 1001, 1003, 1004};
int edades[8]={2,5,6,9,2,4,9,2};
int servicios[10]={20001,20002,20000,20001,20001,20000,20002,20001,20003};
int idMascotas[10]={10000,10001,10002,10003,10004,10005,10006,10007,10008,10009};
int dia[10]={1,5,7,9,14,63,12,16,22,27};
int mes[10]={5,2,7,8,11,5,2,7,10,12};
int anio[10]={2022,2022,2021,2022,2022,2022,2021,2022,2022,2022};
int clientes[10]={500,504,503,507,505,502,500,501,508};

int hardcodearMascotas(Mascota lista[], int tam, int cant, int* pId)
{

    int contador = -1;
    if(lista != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL)
    {
        contador = 0;
        for(int i = 0; i < cant; i++)
        {
            lista[i].id = *pId;
            (*pId)++;
            strcpy(lista[i].nombre ,nombres[i]);
            lista[i].idTipo= tipos[i];
            lista[i].idColor=colores[i];
            lista[i].edad=edades[i];
            lista[i].vacunados=vacunados[i];
            lista[i].idCliente=clientes[i];
            lista[i].isEmpty = 0;
            contador++;
        }
    }

    return contador;
}


int hardcodearTrabajos(Trabajo trabajos[], int tamTra, int cant, int* pTrabajos)
{

    int contador = -1;
    if(trabajos != NULL && tamTra > 0 && cant >= 0 && cant <= tamTra && pTrabajos != NULL)
    {
        contador = 0;
        for(int i = 0; i < cant; i++)
        {
            trabajos[i].id = *pTrabajos;
            (*pTrabajos)++;
            trabajos[i].idMascota=idMascotas[i];
            trabajos[i].idServicio=servicios[i];
            trabajos[i].isEmpty = 0;
            trabajos[i].fecha.dia=dia[i];
            trabajos[i].fecha.mes=mes[i];
            trabajos[i].fecha.anio=anio[i];
            contador++;
        }
    }

    return contador;
}


