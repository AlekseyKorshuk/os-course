#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <unistd.h>
#include <sys/resource.h>

int main(){
    char* ptr;
    int size = 10 * 1024 * 1024;

    for(int i = 0; i < 10; i++){
        ptr = malloc(size);
        memset(ptr, 0, size);

        struct rusage r;
        getrusage(getpid(), &r);
        printf("In RAM: %ld, in Swap: %ld\n", r.ru_maxrss, r.ru_nswap);

        sleep(1);
        free(ptr);
    }

}

