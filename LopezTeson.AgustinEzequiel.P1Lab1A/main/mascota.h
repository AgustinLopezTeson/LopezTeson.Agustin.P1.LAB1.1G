#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED
#include "tipo.h"
#include "cliente.h"
#include "trabajo.h"

typedef struct
{
    int id;
    char nombre[20];
    int idTipo;
    int idColor;
    int idCliente;
    int edad;
    char vacunados;
    int isEmpty;
}Mascota;

int inicializarMascotas(Mascota lista[],int tam);
int altaMascota(Mascota lista[],int tam,Tipo tipos[],int tamTipo,Color colores[],int tamCol,int* pId,eCliente clientes[],int tamCli);
int buscarLibreMascota(Mascota lista[], int tam);
int modificarMascota(Mascota lista[],int tam,Tipo tipos[],int tamTipo,Color colores[],int tamCol,eCliente clientes[],int tamCli);
void mostrarMascota(Mascota unaMascota, Tipo tipos[], Color colores[], int tamTipo,int tamCol,eCliente clientes[],int tamCli);
int mostrarMascotas(Mascota lista[],int tam,Tipo tipos[],int tamTipo,Color colores[],int tamCol,eCliente clientes[], int tamCli);
int buscarMascotaId(Mascota lista[], int tam, int id);
int menuDeModificaciones();
int bajaMascota(Mascota lista[],int tam,Tipo tipos[],int tamTipo,Color colores[],int tamCol,eCliente clientes[],int tamCli);
int traerMascota(Mascota unaMascota[],int tamMasc,int idMascota,char descMascota[]);
//int informes(Mascota lista[],int tam,Tipo tipos[], int tamTipo, Color colores[], int tamCol,Servicio servicios[], int tamSer,Trabajo trabajos[],int tamTra,eCliente clientes[], int tamCli);
int MascotaMenor(Mascota vec[], int tam);
int mostrarMascotaTipo (Mascota lista[],int tam,Color colores[], Tipo tipos[], int tamTipo,int tamCol,eCliente clientes[],int tamCli);
int colorMasElegido(Mascota lista[],int tam,Color colores[],int tamCol);
#endif // MASCOTA_H_INCLUDED
