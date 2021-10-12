#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <unistd.h>
#include <sys/resource.h>

int main(){
    char* ptr;
    int size = 10 * 1024 * 1024;

    for(int i = 0; i < 10; i++){
        ptr = (char *) malloc(size);;
        memset(ptr, 0, size);

        struct rusage r;
        getrusage(RUSAGE_SELF, &r);
        printf("RAM used: %ld\n", r.ru_maxrss);

        sleep(1);
//        free(ptr);
    }
}

