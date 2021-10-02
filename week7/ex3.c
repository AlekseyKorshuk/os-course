#include <stdlib.h>
#include <stdio.h>

int main(){

    printf("Enter the initial array size:");

    int size_initial = 0;
    scanf("%d", &size_initial);

    int* array_initial = malloc(sizeof(int)*size_initial);

    for(int i = 0; i < size_initial; i++){
        *(array_initial + i) = i;
        printf("%d ", *(array_initial + i));
    }
    printf("\nEnter new array size: ");

    int size_new = 0;

    scanf("%d", &size_new);

    array_initial = realloc(array_initial, size_new*sizeof(int));

    for (int i = size_initial; i < size_new; ++i)
        array_initial[i] = 0;

    for(int i = 0; i < size_new; i++)
        printf("%d ", *(array_initial + i));

    return 0;
}