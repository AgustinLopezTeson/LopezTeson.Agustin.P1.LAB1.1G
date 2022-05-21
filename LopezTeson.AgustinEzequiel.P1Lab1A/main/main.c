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
#include "cliente.h"

#define TAM 20
#define TAMTIPO 5
#define TAMCOL 5
#define TAMSER 3
#define TAMTRA 20
#define TAMCLI 8



int main()
{
char seguir='s';

Mascota lista[TAM];
Trabajo trabajos[TAMTRA];
int pId=10000;
int idTrabajos=1;
int idCliente=500;



Color colores[TAMCOL]=
    {
        {5000, "Negro" },
        {5001, "Blanco" },
        {5002, "Rojo" },
        {5003, "Gris" },
        {5004, "Azul" }
    };

Tipo tipos[TAMTIPO]=
    {
        {1000, "Ave"},
        {1001, "Perro"},
        {1002, "Roedor"},
        {1003, "Gato"},
        {1004, "Pez"}
    };

Servicio servicios[TAMSER]=
    {
        {20000,"Corte",450},
        {20001,"Desparasitado",800},
        {20002,"Corte",600}
    };

eCliente clientes[TAMCLI]=
 {
        {500,"Juan",'m'},
        {501,"Marisa",'f'},
        {502,"Hugo",'m'},
        {503,"Tamara",'f'},
        {504,"Agustin",'m'},
        {505,"Hector",'m'},
        {506,"Marina",'f'},
        {507,"Cristian",'m'}

 };

inicializarMascotas(lista,TAM);
inicializarTrabajos(trabajos,TAMTRA);
hardcodearMascotas(lista,TAM,7,&pId);
hardcodearTrabajos(trabajos,TAMTRA,8,&idTrabajos);



     do
    {
        switch (menu())
        {
        case 1:
            altaMascota(lista,TAM,tipos,TAMTIPO,colores,TAMCOL,&pId,clientes,TAMCLI);
            break;
        case 2:
            modificarMascota(lista,TAM,tipos,TAMTIPO,colores,TAMCOL,clientes,TAMCLI);
            break;
        case 3:
            bajaMascota(lista,TAM,tipos,TAMTIPO,colores,TAMCOL,clientes,TAMCLI);
            break;
        case 4:
            mostrarMascotas(lista,TAM,tipos,TAMTIPO,colores,TAMCOL,clientes,TAMCLI);
            system("pause");
            break;
        case 5:
            system("cls");
            mostrarTipos(tipos,TAMTIPO);
            system("pause");
            break;
        case 6:
            system("cls");
            mostrarColores(colores,TAMCOL);
            system("pause");
            break;
        case 7:
            system("cls");
            mostrarServicios(servicios,TAMSER);
            system("pause");
            break;
        case 8:
            system("cls");
            altaTrabajo(lista,TAM,tipos,TAMTIPO,colores,TAMCOL,trabajos,TAMTRA,servicios,TAMSER,&idTrabajos,clientes,TAMCLI);
            system("pause");
            break;
        case 9:
            system("cls");
            mostrarTrabajos(trabajos,TAMTRA,servicios,TAMSER,lista,TAM);
            system("pause");
            break;
        case 10:
            informes(lista,TAM,tipos,TAMTIPO,colores,TAMCOL,servicios,TAMSER,trabajos,TAMTRA,clientes,TAMCLI);
            break;
        case 11:
            seguir ='n';
            break;
        default:
            printf("Opcion invalida\n");
            break;
        }
    }
    while(seguir == 's');



    return 0;
}
