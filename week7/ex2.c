#include <stdio.h>
#include <stdlib.h>

int main() {

    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("\n");

    int* array = malloc(size*sizeof(int));
    for (int i = 0; i < size; i++)
        *(array + i) = i;

    printf("Array:\n");
    for (int i = 0; i < size; i++)
        printf("%d ", *(array + i));

    free(array);
    printf("\nCleaned!");

    return 0;
}