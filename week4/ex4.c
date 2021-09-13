/* OS Lab 4
*  Exercise 4
*
*  @author  Aliaksei Korshuk
*  @version 1.0
*  @since   2021-02-16
*/

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    printf("Enter your command:\n");
    
    while(1){
        char c[1000];
        printf(">");
        scanf("%[^\n]%*c", c);

        char* argv[1000];
        int pos = 0;
        argv[pos] = strtok(c, " ");
        while(argv[pos] != NULL){
            pos++;
            argv[pos] = strtok(NULL, " ");

        }

        pid_t x = fork();

        if(x == 0){
            execvp(argv[0], argv);
        }else{
            wait(NULL);
        }

    }
}
