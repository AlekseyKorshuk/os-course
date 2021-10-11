#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <unistd.h>

// If we remove memset(ptr, 0, size), top command will show 0.0% of memory consumption
// otherwise it will show non-negative number
int main(){
    char* ptr;
    int size = 256 * 1024 * 1024;

    for(int i = 0; i < 10; i++){
        ptr = malloc(size);
        memset(ptr, 0, size);
        sleep(1);

        printf("Run %d\n", i);
        free(ptr);
    }

}

