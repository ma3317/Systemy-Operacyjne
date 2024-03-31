#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>


#define BSIZE 30
pthread_mutex_t mutexBuffer;
int count = 0;
typedef struct {
    int buf[BSIZE];
    sem_t full;
    sem_t empty;
} buffer_t;

buffer_t b;


void insert(int prod, int data) {
    int index = count;
    count++;
    b.buf[index] = data;
    fprintf(stdout, "PRODUCENT %d: Wyprodukowalem paczke no. %d na pozycji %d\n", prod, data, index);

}

int get(int cons) {
    int index = count;
    count--;
    int item = b.buf[index];
    fprintf(stdout, "KONSUMENT %d: Pobralem paczke no. %d z pozycji %d\n", cons, item, index);

    return item;
}

void *producer(void *nr)
{
    int no = *((int *) nr);
    for(int j = 0; j < 100; j++)   {
        sem_wait(&b.empty);
        pthread_mutex_lock(&mutexBuffer);
        insert(no, j); 
        sleep(1);
        pthread_mutex_unlock(&mutexBuffer);
        sem_post(&b.full);
        
    }
    pthread_exit(0);
}

void *consumer(void *nr)
{
    int no = *((int *) nr);
    for(int j = 0; j < 100; j++) {
        sem_wait(&b.full);
        int result = get(no); sleep(rand() % 10);
        pthread_mutex_unlock(&mutexBuffer);
        sem_post(&b.empty);
        
    }
    pthread_exit(0);
}

int main()
{
    sem_init(&b.empty, 0, 30);
    sem_init(&b.full, 0, 0);
    pthread_t prod[10], kons[10];
    int no[10] = {0, 1, 2, 3, 4, 5, 6, 7,8,9}; // numer producenta/konsumenta
    for(int i = 0; i < 10; i++)
    {
        if(pthread_create(&prod[i], NULL, producer, &no[i]))
        {fprintf(stderr, "Blad tworzenia watku Producenta %d\n", i); abort();}
        if(pthread_create(&kons[i], NULL, consumer, &no[i]))
        {fprintf(stderr, "Blad tworzenia watku Konsumenta %d\n", i); abort();}
    }
    sleep(10);
    for(int i = 0; i < 10; i++)
    {
        pthread_join(prod[i],NULL);
        pthread_join(kons[i],NULL);
    }
    sem_destroy(&b.empty);
    sem_destroy(&b.full);
    pthread_mutex_destroy(&mutexBuffer);
    exit(0);
}