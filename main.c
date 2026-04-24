#include <pthread.h>
#include <stdio.h>
#define FILAS 3
#define COLUMNAS 9

void numeracion(int i,int j, int matriz[FILAS][COLUMNAS]){
	matriz[i][j] = (j+1);
}
void numeracionImpar(int i, int j, int matriz[FILAS][COLUMNAS]){
	matriz[i][j] = (2*j)+1;
}
void numeracionPar(int i, int j, int matriz[FILAS][COLUMNAS]){
	matriz[i][j] = 2*(j+1);
}

void llenarMatriz(int matriz[FILAS][COLUMNAS]){
	for(int i=0; i<FILAS; i++){
		for(int j=0; j<COLUMNAS; j++){
			int operador = j+1;
			switch(i){
				case 0:
					numeracion(i,operador,matriz);
					break;
				case 1:
					numeracionImpar(i,operador,matriz);
					break;
				case 2:
					numeracionPar(i,operador,matriz);
					break;
			}
		}
	}
}


int main(){
	int matriz[FILAS][COLUMNAS];
	llenarMatriz(matriz);
	for(int i=0;i<FILAS;i++){
		for(int j=0; j<COLUMNAS;j++){
			printf("%d,", matriz[i][j]);
		}
		printf("\n");
	}
	return 0;
}
