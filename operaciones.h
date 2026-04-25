#define OPERACIONES_H

#define FILAS 3
#define COLUMNAS 9
#define MAX_THREADS 3

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

//Estructuras
typedef struct
{
    int id_fila;
    int matriz[FILAS][COLUMNAS];
    int arr_results[MAX_THREADS];
} MatrizData;

//Matriz
void mostrarResultados(int matriz[MAX_THREADS]);
void numeracion(int i,int j, int matriz[FILAS][COLUMNAS]);
void numeracionImpar(int i, int j, int matriz[FILAS][COLUMNAS]);
void numeracionPar(int i, int j, int matriz[FILAS][COLUMNAS]);
void llenarMatriz(int matriz[FILAS][COLUMNAS]);

//Hilos
void *presentacionHilos();
void *multiplicacionFilaMatriz(void *paquete);
void manejoHilos(void *paquete);