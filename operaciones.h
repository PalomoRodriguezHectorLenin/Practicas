#define OPERACIONES_H

#define FILAS 3
#define COLUMNAS 9

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


//Matriz
void numeracion(int i,int j, int matriz[FILAS][COLUMNAS]);
void numeracionImpar(int i, int j, int matriz[FILAS][COLUMNAS]);
void numeracionPar(int i, int j, int matriz[FILAS][COLUMNAS]);
void llenarMatriz(int matriz[FILAS][COLUMNAS]);

//Hilos
void *presentacionHilos();
void creacionDeHilos();