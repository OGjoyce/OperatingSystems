#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <limits.h>
#include <stdlib.h>
#include <semaphore.h>
#include <string.h>
#include <stdbool.h>
#define VELOCIDAD_MENOR 216
#define VELOCIDAD_MEDIA 270
#define VELOCIDAD_MAYOR 360
#define LARGO 300


/* LINKED LIST STRUCTURE */
struct node {
   int data;
   int key;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

//display the list
void printList() {
   struct node *ptr = head;
   printf("\n[ ");
	
   //start from the beginning
   while(ptr != NULL) {
      printf("(%d,%d) ",ptr->key,ptr->data);
      ptr = ptr->next;
   }
	
   printf(" ]");
}

//insert link at the first location
void insertFirst(int key, int data) {
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
	
   link->key = key;
   link->data = data;
	
   //point it to old first node
   link->next = head;
	
   //point first to new first node
   head = link;
}

//delete first item
struct node* deleteFirst() {

   //save reference to first link
   struct node *tempLink = head;
	
   //mark next to first link as first 
   head = head->next;
	
   //return the deleted link
   return tempLink;
}

//is list empty
bool isEmpty() {
   return head == NULL;
}

int length() {
   int length = 0;
   struct node *current;
	
   for(current = head; current != NULL; current = current->next) {
      length++;
   }
	
   return length;
}

//find a link with given key
struct node* find(int key) {

   //start from the first link
   struct node* current = head;

   //if list is empty
   if(head == NULL) {
      return NULL;
   }

   //navigate through list
   while(current->key != key) {
	
      //if it is last node
      if(current->next == NULL) {
         return NULL;
      } else {
         //go to next link
         current = current->next;
      }
   }      
	
   //if data found, return the current Link
   return current;
}

//delete a link with given key
struct node* delete(int key) {

   //start from the first link
   struct node* current = head;
   struct node* previous = NULL;
	
   //if list is empty
   if(head == NULL) {
      return NULL;
   }

   //navigate through list
   while(current->key != key) {

      //if it is last node
      if(current->next == NULL) {
         return NULL;
      } else {
         //store reference to current link
         previous = current;
         //move to next link
         current = current->next;
      }
   }

   //found a match, update the link
   if(current == head) {
      //change first to point to next link
      head = head->next;
   } else {
      //bypass the current link
      previous->next = current->next;
   }    
	
   return current;
}

void sort() {

   int i, j, k, tempKey, tempData;
   struct node *current;
   struct node *next;
	
   int size = length();
   k = size ;
	
   for ( i = 0 ; i < size - 1 ; i++, k-- ) {
      current = head;
      next = head->next;
		
      for ( j = 1 ; j < k ; j++ ) {   

         if ( current->data > next->data ) {
            tempData = current->data;
            current->data = next->data;
            next->data = tempData;

            tempKey = current->key;
            current->key = next->key;
            next->key = tempKey;
         }
			
         current = current->next;
         next = next->next;
      }
   }   
}

void reverse(struct node** head_ref) {
   struct node* prev   = NULL;
   struct node* current = *head_ref;
   struct node* next;
	
   while (current != NULL) {
      next  = current->next;
      current->next = prev;   
      prev = current;
      current = next;
   }
	
   *head_ref = prev;
}

/* END OF LISTED LINK STRUCTURE */

/*  THREAD LIST [I,N]
	I -> thread index inserted.
	N -> lado derecha o izquierda (11,21)
	[2 LADO DERECHO], [21 LADO DERECHO CRUZANDO], [22 LADO DERECHO ESPERANDO]
	[1 LADO IZQUIERDO], [11 LADO IZQUIERDO CRUZANDO], [12 LADO IZQUIERDO ESPERANDO]
*/
void acceder_al_puente(int side, int *index_priority)
{	
	int size = length();

	if (side==0) 
		{
	
			if(size<5) //SOLO 5 pueden cruzar DERECHO
			{
				insertFirst(*index_priority, 21);
			}
			else{
				insertFirst(*index_priority, 22);
			}
			++(*index_priority);

		}
		else
		{ 
		
			if(size<5){ //SOLO 5 pueden cruzar IZQUIERDO
			
				insertFirst(*index_priority, 11);

			}
			else{	
				insertFirst(*index_priority, 12);
			}
			++(*index_priority);
	
		}
}
void calculate(int velocidad)
{
	printf("%d\n", velocidad);
	double time = 300/(velocidad*1000);
	sleep(time);
	printf("(%s,%lf)\n", "Tiempo que tardo cruzando: ", time );
}
void *run_for_your_life(int *data)
{	
	printf("%s\n", "Calculando velocidad...");
	
	int vel;
		vel = rand() % 3;
	if (*data == 11 || *data == 21)
	{
		if (*data==21)
		{
			/* code */
		printf("%s\n", ">" );
		}
		if (*data==11)
		{
			/* code */
			printf("%s\n", "<" );
		}
		if (vel ==0)
		{
			vel = 216;
		}	
		if (vel ==1)
		{
			vel = 270;
		}
		if (vel==2)
		{
			vel = 360;
		}
		calculate(vel);
	}
	if (*data == 12 || *data==22)
	{
		printf("%s\n", "Agregar a la lista de espera");
	}

}
void make_threads(int i)
{
	i=i+1;
	struct node *foundLink = find(i);
	printf("%s", "crear el thread: ");
	printf("%d\n", i);
	pthread_t thread_i[i];
	pthread_create(&thread_i[i], NULL, run_for_your_life, &foundLink->data);
	pthread_join(thread_i[i], NULL);
	

}
int main(void)
{
//GLOBAL VARIABLE TO CALCULATE PRIORITY
	int index =1;
//INPUT BUFFER
	printf("%s\n", "Ingrese la cantidad de personas: ");
	int length2;
	scanf("%d", &length2);
// 0 = LADO DERECHO
// 1 = LADO IZQUIERDO
	int r;
	srand ( time(NULL) );
	for (int i = 0; i < length2; ++i)
	{	
		r = rand() % 2;	
		acceder_al_puente(r, &index);			
	}
	int just_a_length = length();
	int i =0;
	printList();
	while(i<just_a_length)
	{
		make_threads(i);
	i++;
}


}
