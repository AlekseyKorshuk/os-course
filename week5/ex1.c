#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


void *threadFunction(void *args){
    pthread_t self_tid = pthread_self();
    printf("Thread ID: %lu, and some text...\n", self_tid);
    return NULL;
}


int main(){
    int i;
    pthread_t tid;

    for (i = 0; i < 10; i++){
        pthread_create(&tid, NULL, threadFunction, NULL);
        printf("Creating thread #%d\n", i+1);
        pthread_join(tid, NULL);
    }
    pthread_exit(NULL);
    return 0;
}
