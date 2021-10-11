#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <unistd.h>

// If we remove memset(ptr, 0, size), there would be no swaps ('si' (swap-ins) and 'so' (swap-outs)), especially 'so'
// Moreover, depending on the computer, the size could be different
int main(){
    char* ptr;
    int size = 1024 * 1024 * 1024;

    for(int i = 0; i < 10; i++){
        ptr = malloc(size);
        memset(ptr, 0, size);
        sleep(1);

        printf("Run %d\n", i);
        free(ptr);
    }

}

