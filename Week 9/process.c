#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>

int main(int argc, char const *argv[]){
    pid_t pid;
    int status;
    char *args[] = {"ls" , "-l" , NULL};

    pid = fork();
    if(pid == -1){
        printf("unable to fork\n");
        exit(1);
    }
    if(pid == 0){
        printf("%d: Child Process: %d\n" , getppid() , getpid());
        execvp(args[0] , args);
    }else{
        printf("%d: Parent Process: %d\n" , getppid() , getpid());
        waitpid(pid , &status , 0);
        printf("Child Finished\n");
    }

    return 0;
}