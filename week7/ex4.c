#include <stdio.h>
#include <stdlib.h>


void* my_realloc(int* p, int size) {
    if (p == NULL) {
        return malloc(size);

    } else if (size == 0) {
        free(p);
        return NULL;

    } else {
        int* new_array = malloc(size);

        if (new_array)
            for (int i = 0; i < size; i++)
                *(new_array + i) = *(p + i);

        free(p);
        return new_array;
    }
}

int main() {
    printf("Enter the initial array size:");
    int size_initial = 10;
    scanf("%d", &size_initial);
    printf("Enter new array size:");
    int size_new = size_initial * 2;
    scanf("%d", &size_new);
    int *arr = malloc(sizeof(int)*size_initial);

    printf("Ininital Array: ");
    for (int i = 0; i < size_initial; ++i) {
        *(arr + i) = i;
        printf("%d ", *(arr + i));
    }

    arr = my_realloc(arr, sizeof(int)*size_new);

    printf("\nAfter my_realloc(): ");
    for (int i = 0; i < size_new; ++i)
        printf("%d ", *(arr + i));

    return 0;
}