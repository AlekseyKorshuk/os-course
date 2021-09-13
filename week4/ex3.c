/* OS Lab 4
*  Exercise 3
*
*  @author  Aliaksei Korshuk
*  @version 1.0
*  @since   2021-02-16
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int main(){
    char *command = "";
    printf("Enter your command: \n");
    scanf("%10[0-9a-zA-Z ]", &command);
    system(&command);
}
