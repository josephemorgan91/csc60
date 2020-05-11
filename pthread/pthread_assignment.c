#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

int x = 30;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *add1(void *a);
void *add2(void *b);
void *add3(void *c);

int main() {
	pthread_t threads[2];
	int x1, x2, x3;
	x1 = 10;
	x2 = 20;
	x3 = 30;

	int id1 = pthread_create(&threads[0], NULL, add1, (void*)&x1);
	int id2 = pthread_create(&threads[1], NULL, add2, (void*)&x2);
	int id3 = pthread_create(&threads[2], NULL, add3, (void*)&x3);
	
	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);
	pthread_join(threads[2], NULL);
	printf("The value of x is: %d\n", x);
}

void *add1(void *a)
{
	// Assignment indicates to add *a to x
	pthread_mutex_lock(&lock);
	x += *(int*)a;
	pthread_mutex_unlock(&lock);
	pthread_exit((void*) 0);
}

void *add2(void *b)
{
	// Assignment indicates to add b to x, with the dereference operator omitted. I assume that's a typo, as we probably don't want to be adding a pointer to x
	pthread_mutex_lock(&lock);
	x += *(int*)b;
	pthread_mutex_unlock(&lock);
	pthread_exit((void*) 0);
}

void *add3(void *c)
{
	// Same note as add2
	pthread_mutex_lock(&lock);
	x += *(int*)c;
	pthread_mutex_unlock(&lock);
	pthread_exit((void*) 0);
}
