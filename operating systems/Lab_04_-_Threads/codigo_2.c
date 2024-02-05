/*
>>3 PCD_Activity3_Session1 de www.um.es 
Un thread que crea 100 threads hijos, 
midiendo el tiempo medio que tarda
en la creacion de cada uno de ellos.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
struct timeval t0, t1;
double media = 0.0;
void *hilo (void *arg) {
	gettimeofday (&t1, NULL);
	unsigned int ut1 = t1.tv_sec*1000000+t1.tv_usec;
	unsigned int ut0 = t0.tv_sec*1000000+t0.tv_usec;
	media += (ut1-ut0);
}
int main () {
	int i = 0;
	pthread_t h;
	for ( i = 0 ; i < 100 ; i ++ ) {
		gettimeofday (&t0, NULL);
		pthread_create (&h, NULL, &hilo , NULL);
	
	}
	/*Tiempo medio en microsegundos */
	printf("%f\n", (media/100.0));
}