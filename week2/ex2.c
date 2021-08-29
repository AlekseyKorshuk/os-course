/* OS Lab 2
*  Exercise 2
*
*  @author  Aliaksei Korshuk
*  @version 1.0
*  @since   2021-26-08
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <string.h>

/**
 * Function that solves the given exercise
 */
void solve(){
    const int size = 100;
    char string[size];

    printf("Enter your string:\n");
    scanf("%s", string);

    for (int i = strlen(string)-1; i>=0; i--){
        printf("%c", string[i]);
    }
}

int main() {
    solve();
    return 0;
}
