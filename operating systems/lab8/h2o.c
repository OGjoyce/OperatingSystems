#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <limits.h>
#define NUM_THREADS 4
/*
CREAMOS UNA ESTRUCTURA STACK PARA PODER PROCESAR
LAS MOLECULAS DE AGUA
*/
struct Stack 
{ 
    int top; 
    unsigned capacity; 
    int* array; 
}; 
  
// function to create a stack of given capacity. It initializes size of 
// stack as 0 
struct Stack* createStack(unsigned capacity) 
{ 
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack)); 
    stack->capacity = capacity; 
    stack->top = -1; 
    stack->array = (int*) malloc(stack->capacity * sizeof(int)); 
    return stack; 
} 
  
// Stack is full when top is equal to the last index 
int isFull(struct Stack* stack) 
{   return stack->top == stack->capacity - 1; } 
  
// Stack is empty when top is equal to -1 
int isEmpty(struct Stack* stack) 
{   return stack->top == -1;  } 
  
// Function to add an item to stack.  It increases top by 1 
void push(struct Stack* stack, int item) 
{ 
    if (isFull(stack)) 
        return; 
    stack->array[++stack->top] = item; 
    //printf("%d pushed to stack\n", item); 
} 
  
// Function to remove an item from stack.  It decreases top by 1 
int pop(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top--]; 
} 
// FIN DE STACK
void *waiter()
{
	//printf("%s\n", "atom created!");

}
void Oxigeno()
{
	 pthread_t tidox;
 	 pthread_create(&tidox, NULL, waiter, NULL);
 	 pthread_join(tidox, NULL);

}
void hidrogeno()
{
	pthread_t tidhi;
 	pthread_create(&tidhi, NULL, waiter, NULL);
 	pthread_join(tidhi, NULL);
}

int main(void)
 {	
pthread_t tidox;
pthread_t tidhi; 
int length;
scanf("%d", &length);
int oxigenos;
int hidrogenos;
int r;
srand ( time(NULL) );
struct Stack* stack = createStack(length);
for (int i = 0; i < length; ++i)
{	
	r = rand() % 2;
	if (r==0)//atomo de oxigeno
	{
		Oxigeno();
		push(stack, 0);
	}
	else{ //atomo de hidrogeno
		hidrogeno();
		push(stack, 1);
	}


}
// 2*oxigen <= hidrogeno   
int ox = 0;
int hid = 0;
int bol = 0;
int iterator =0;
while(iterator!=length)
{
	int p = pop(stack);
	if (p==0)
	{
		/* code */
		ox++;
	}
	if (p==1)
	{
		/* code */
		hid++;
	}
	iterator++;

}
printf("%d Atomos de oxigeno: \n", ox);
printf("%d Atomos de hidrgeno: \n", hid);
while(2*ox>hid)
{
	ox--;
}
	if (2*ox<=hid)
{
	/* code */
	printf("%d Moleculas de agua creadas: \n", ox);
}

}