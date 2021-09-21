#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>

#define N 100

// Global variables
int isConsumerSleeping = 0, isProducerSleeping = 0;
int buffer = 0;


void *consumerThread(void* args){
    while(true){
        if(isConsumerSleeping == 1){
          printf("I am consumer - I am sleeping\n");
          continue;
        }            

        if(buffer < N)
            printf("I am consumer - %d\n", buffer);

        if(buffer > 0){
            isProducerSleeping = 0;
            buffer--;
        }
        else{
            isConsumerSleeping = 1;
        }
    }
}


void *producerThread(void* args){
    while(true){
        if(isProducerSleeping == 1){
          printf("I am producer - I am sleeping\n");
          continue;
        }

        if(buffer < N)
            printf("I am producer - %d\n", buffer);

        if(buffer <= N){
            isConsumerSleeping = 0;
            buffer++;
        }
        else{
            isProducerSleeping = 1;
        }
    }
}


int main(){
    pthread_t tProduce, tConsume;
    pthread_create(&tProduce, NULL, producerThread, NULL);
    pthread_create(&tConsume, NULL, consumerThread, NULL);

    pthread_join(tProduce, NULL);
    pthread_join(tConsume, NULL);
}
