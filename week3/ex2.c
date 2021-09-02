/* OS Lab 3
*  Exercise 2
*
*  @author  Aliaksei Korshuk
*  @version 1.0
*  @since   2021-02-09
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Method that swaps two integers
 * @param a Reverence to an integer
 * @param b Reverence to an integer
 */
void swap(int *a, int *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

/**
 * Method that sorts an array of integers with the bubble sort
 * @param array Pointer to the first element of the array
 * @param size Size of the array
 * @return Pointer to the first element of the array
 */
int* bubble_sort(int* array, int size){

    for (int i = 0; i < size; i++){
        for (int j = i; j < size; j++){
            if (array[i] > array[j]) swap(&array[i], &array[j]);
        }
    }

    return array;
}

int main() {
    int size = 5;
    int* array = malloc(size*sizeof(size));

    printf("Before:\n");
    for (int i = 0; i < size; i++){
        array[i] = size - i;
        printf("%d ", array[i]);
    }
    printf("\n");

    array = bubble_sort(array, size);

    printf("After:\n");
    for (int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }

    return 0;
}
