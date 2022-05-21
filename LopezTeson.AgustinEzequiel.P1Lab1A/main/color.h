
#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED


typedef struct
{
    int id;
    char nombreColor[20];
}Color;

int mostrarColores(Color colores[], int tam);
int traerColor(Color colores[], int tamCol, int idColor , char descColor[]);

#endif // COLOR_H_INCLUDED
