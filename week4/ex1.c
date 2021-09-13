/* OS Lab 4
*  Exercise 1
*
*  @author  Aliaksei Korshuk
*  @version 1.0
*  @since   2021-02-16
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int main(){
    int n = 100500;
    pid_t parentPID = getpid();

    if (getpid() == parentPID)
        printf("Hello from parent [%d - %d]\n", parentPID, n);

    fork();

    if (getpid() != parentPID)
        printf("Hello from child [%d - %d]\n", getpid(), n);
}
