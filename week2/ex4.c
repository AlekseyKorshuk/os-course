/* OS Lab 2
*  Exercise 4
*
*  @author  Aliaksei Korshuk
*  @version 1.0
*  @since   2021-26-08
*/

#include <stdio.h>

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
 * Function that solves the given exercise
 */
void solve(){
    int a;
    int b;
    char str[100];
	
    printf("Enter A:\n");
    scanf("%s", str);
    sscanf(str ,"%d", &a);
	
    printf("Enter B:\n");
    scanf("%s", str);
    sscanf(str ,"%d", &b);
	
    printf("Before swap:\nA: %d, B: %d\n", a, b);
	
    swap(&a, &b);
    printf("After swap:\nA: %d, B: %d\n", a, b);
}

int main() {
    solve();
    return 0;
}
