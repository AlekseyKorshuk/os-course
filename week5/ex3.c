#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>

// Global variables
int bConsumerSleeping = 0, bProducerSleeping = 0;
int position = 0;


void *consumerThread(void* args){
    int counter = 0;
    while(true){
        if(bConsumerSleeping == 1)
            continue;

        if(counter < 100)
            printf("I am consumer - %d\n", position);

        if(position > 0){
            bProducerSleeping = 0;
            position--;
            counter++;
        }
        else{
            bConsumerSleeping = 1;
        }
    }
}


void *producerThread(void* args){
    int counter = 0;
    while(true){
        if(bProducerSleeping == 1)
            continue;

        if(counter < 100)
            printf("I am producer - %d\n", position);

        if(position <= 100){
            bConsumerSleeping = 0;
            position++;
            counter++;
        }
        else{
            bProducerSleeping = 1;
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