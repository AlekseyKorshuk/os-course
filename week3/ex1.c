/* OS Lab 3
*  Exercise 1
*
*  @author  Aliaksei Korshuk
*  @version 1.0
*  @since   2021-02-09
*/

#include <stdio.h>

int main() {
    int* pc;
    int c;
    c=22;
    printf("Address of c:%d\n", &c);
    printf("Value of c:%d\n", c);
    pc=&c;
    printf("Address of pc:%d\n", &pc);
    printf("Content of pc:%d\n", *pc);
    c=11;
    printf("Address of pc:%d\n", &pc);
    printf("Content of pc:%d\n", *pc);
    *pc=2;
    printf("Address of c:%d\n", &c);
    printf("Value of c:%d\n", c);
    return 0;
}
