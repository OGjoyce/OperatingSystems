#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <pthread.h>
#define ARRAY_SIZE 100000
 	pthread_t tr;
int main (void)
{	
	double media = 0.0;
	struct timeval t0, t1;
	   static int vector [ARRAY_SIZE] = {0};
   	size_t i = 0;
   	int iterator = 0;
   	gettimeofday (&t0, NULL);
	

	void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
   void bubblesort(int v[] )
   {

   	int i, j; 
   for (i = 0; i < ARRAY_SIZE; i++) {      
  	printf("%i\n", i);
       // Last i elements are already in place    
       for (j = 0; j <= ARRAY_SIZE-i-1; j++)  
           if (v[j] > v[j+1]) 
              swap(&v[j], &v[j+1]); 	
      }

   }	


   srand((unsigned)time(NULL));
   for ( int i = 0 ; i < ARRAY_SIZE ; ++i )
   {
      vector[i] = rand();     
      iterator=i;
   }
   printf("%s\n", "bubblesort");
  bubblesort(vector);
    printf("%s\n", "fin bubblesort");
   gettimeofday (&t1, NULL);
	unsigned int ut1 = t1.tv_sec*1000000+t1.tv_usec;
	unsigned int ut0 = t0.tv_sec*1000000+t0.tv_usec;
	media += (ut1-ut0);
	printf("%f\n", (media/1000.0));
   return 0;
}