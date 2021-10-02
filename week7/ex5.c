#include <stdio.h>
#include <stdlib.h> // Include library for malloc()

int main() {
    char **s = malloc(sizeof(char*)); // Allocate memory for 's' beforehand
    char foo[] = "Hello World";

    *s = foo;
    printf( "s is %s\n", s);
    s [0] = foo ;
    printf("s[0] is %s\n", s[0]);
    return (0) ;
}