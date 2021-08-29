/* OS Lab 2
*  Exercise 3
*
*  @author  Aliaksei Korshuk
*  @version 1.0
*  @since   2021-26-08
*/

#include <stdio.h>


/**
 * Function that solves the given exercise
 */
void solve(){
    int size;
    char str[80];
    printf("Enter N:\n");
    scanf("%s", str);
    sscanf(str ,"%d", &size);

    for (int i=0; i < size; i++){
        for (int k=0; k < size - i - 1; k++){
            printf(" ");
        }
        for (int k=0; k < i*2 + 1; k++){
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    solve();
    return 0;
}
