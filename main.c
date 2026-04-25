#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

int main(){
	//int matriz[FILAS][COLUMNAS];
	MatrizData data;
	llenarMatriz(data.matriz);
	manejoHilos((void *)&data);
	mostrarResultados(data.arr_results);
	return 0;
}
