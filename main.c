#include <stdio.h>
#include "operaciones.h"

int main(){
	int matriz[FILAS][COLUMNAS];
	llenarMatriz(matriz);
	creacionDeHilos();
	return 0;
}
