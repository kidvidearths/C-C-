#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>
#define buffersize 10
pthread_mutex_t mutex;
pthread_t B,C[20];
sem_t full,empty;
int count,ticket,i;
int buffer[buffersize],seq[30];
void initialize()
{
    pthread_mutex_init(&mutex,NULL);
    sem_init(&full,1,0);
    sem_init(&empty,1,buffersize);
    count=0;
}
void write(int item)
{
    buffer[count++]=item;
}
int read()
{
    return(buffer[--count]);
}
int eventcount()
{
    ticket++;
    return ticket;
}
void * barista (void * param)
{
    int wait_time,item,i;
    item=eventcount();
    wait_time=ticket;
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);
    printf("\nBARISTA has SERVED: %d ID ITEM\n",item);
    write(item);pthread_mutex_unlock(&mutex);
    sem_post(&full);
}
void * customer (void * param){
    int wait_time,item;
    wait_time=ticket;
    sem_wait(&full);
    pthread_mutex_lock(&mutex);
    item=read();
    printf("\nCustomer has been recieved: %d id item\n",item);
    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
}
int main()
{
    ticket=0;
    int n,i;
    initialize();
    printf("\nEnter the number of customers: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        pthread_create(&B,NULL,barista,NULL);
        pthread_create(&C[i],NULL,customer,NULL);
    }
    for(i=0;i<n;i++)
    {
        pthread_join(B,NULL);
        pthread_join(C[i],NULL);
    }
    sleep(5);
    exit(0);
}