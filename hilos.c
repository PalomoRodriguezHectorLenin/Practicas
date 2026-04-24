#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include "operaciones.h"
#define MAX_THREADS 3
//Presentacion Hilos
void *presentacionHilos(){
	printf("\nHilo %lu creado\n", (unsigned long)pthread_self());
	pthread_exit(NULL);
}
//Creacion de hilos
void creacionDeHilos(){
	pthread_attr_t atr;
	pthread_t ids[MAX_THREADS];
	pthread_attr_init(&atr);
	pthread_attr_setdetachstate(&atr, PTHREAD_CREATE_DETACHED);
	for(int i=0;i<MAX_THREADS;i++){
		pthread_create(&ids[i], &atr, presentacionHilos,NULL);
	}
	pthread_attr_destroy(&atr);
	sleep(1);
}


