#include <stdio.h>
#include <pthread.h>
#define wait1 {double z1;for(z1=0;z1<10000;z1=z1+0.00003);}
#define BUFFER_SIZE 10
pthread_mutex_t locknt, lockout;


typedef struct
{
    int valor;
} item;
item buffer[BUFFER_SIZE];
int in = 0;
int out = 0;
int counter = 0;

void *Producer(void *arg)
{
    int val = 1, k = 0;
    item nextProduced;
    while (k++ < 50)
    {
        while (counter == BUFFER_SIZE)
            wait1; /* do nothing */
        nextProduced.valor = val++;
        buffer[in] = nextProduced;
        in = (in + 1) % BUFFER_SIZE;
        pthread_mutex_lock(&locknt);
        counter++;
        pthread_mutex_unlock(&locknt);
    }
    return (NULL);
}

void *Consumer(void *arg)
{
    item nextConsumed;
    int k = 0;
    while (k++ < 50)
    {
        while (counter == 0)
            wait1; /* do nothing */
        nextConsumed = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        printf("Valor=%d : %d\n", nextConsumed.valor, counter);
        pthread_mutex_lock(&lockout);
        counter--;
        pthread_mutex_unlock(&lockout);
    }
    return (NULL);
}

int main()
{
    pthread_t pid, cid, cid2;
    pthread_create(&pid, NULL, Producer, NULL);
    pthread_create(&cid, NULL, Consumer, NULL);
    pthread_join(pid, NULL);
    pthread_join(cid, NULL);
}