/* OS Lab 4
*  Exercise 2
*
*  @author  Aliaksei Korshuk
*  @version 1.0
*  @since   2021-02-16
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(){

    for (int i = 0; i < 3; i++){
        fork();
    }

    sleep(5);
}
