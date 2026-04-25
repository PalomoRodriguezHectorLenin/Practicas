#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include "operaciones.h"

void *presentacionHilos(){
	printf("\nHilo %lu creado\n", (unsigned long)pthread_self());
	pthread_exit(NULL);
}
void *multiplicacionFilaMatriz(void *paquete){
	//Obtener datos matriz
	MatrizData *data = (MatrizData *)paquete;

	int res_temp=data->matriz[data->id_fila][0];
	//Calculo de multiplicacion
	for(int i=1; i<COLUMNAS; i++){
		printf("\nHilo trabajando con la fila %d\n", data->id_fila);
		printf("\nMultiplicacion de %d con %d\n", res_temp, data->matriz[data->id_fila][i]);
		res_temp = res_temp * data->matriz[data->id_fila][i];
		printf("\nResultado obtenido: %d\n", res_temp);
		sleep(1);
	}
	data->arr_results[data->id_fila]=res_temp;
	pthread_exit(NULL);
}
//Creacion de hilos
void manejoHilos(void *paquete){
	//HILOS
	pthread_attr_t atr;
	pthread_t ids[MAX_THREADS];
	pthread_attr_init(&atr);
	pthread_attr_setdetachstate(&atr, PTHREAD_CREATE_DETACHED);
	//DATA HILOS
	MatrizData *data = (MatrizData *)paquete;
	//Funciones de hilos
	for(int i=0;i<MAX_THREADS;i++){
		pthread_create(&ids[i], &atr, presentacionHilos,NULL);
	}
	pthread_attr_destroy(&atr);
	for(int j=0;j<MAX_THREADS;j++){
		data->id_fila = j;
		pthread_create(&ids[j], NULL, multiplicacionFilaMatriz, paquete);
		pthread_join(ids[j], NULL);
	}	
	sleep(1);
}


