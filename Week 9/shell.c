#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>

#define SIZE 1024

int main(int argc , char const *argv[]){
    char cmd[SIZE];
    pid_t pid;
    int status;

    while(1){
        printf("shell> ");
        fgets(cmd , SIZE -1 , stdin);
        cmd[strlen(cmd)-1] = '\0' ; // --> replaces \n with \0
        pid = fork();
        if (pid == 0){
            execlp(cmd , "");
        }else{
            waitpid(pid , &status , 0);
        }
    }


    return 0;
}