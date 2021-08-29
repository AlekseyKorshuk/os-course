/* OS Lab 2
*  Exercise 1
*
*  @author  Aliaksei Korshuk
*  @version 1.0
*  @since   2021-26-08
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

/**
 * Function that solves the given exercise
 */
void solve(){
    int integer_variable = INT_MAX;
    float float_variable = FLT_MAX;
    double double_variable = DBL_MAX;

    printf("Integer:\n");
    printf("-> Size: %llu\n", sizeof(integer_variable));
    printf("-> Value: %d\n", integer_variable);

    printf("Float:\n");
    printf("-> Size: %llu\n", sizeof(float_variable));
    printf("-> Value: %f\n", float_variable);

    printf("Double:\n");
    printf("-> Size: %llu\n", sizeof(double_variable));
    printf("-> Value: %f\n", double_variable);
}

int main() {
    solve();
    return 0;
}
