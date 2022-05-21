

#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED


typedef struct{
int idCliente;
char nombre[21];
char sexo;
int isEmpty;
}eCliente;

int hardcodearCliente(eCliente clientes[],int tamCli,int cantidad,int* idCliente);
int inicializarClientes(eCliente clientes[],int tamCli);
int traerCliente(eCliente clientes[], int tamCli, int idCliente , char descCliente[]);
#endif // CLIENTE_H_INCLUDED
