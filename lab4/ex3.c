#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define NUMBER_OF_LOOPS 10000

int main(int argc,char* agrv[]){

    pid_t cpid,w;
    int status;

    /* Create a fork */
    cpid = fork();
    /* Check if the child process was created */
    if (cpid == -1){
        perror("fork");
        _exit(EXIT_FAILURE);
    }

    /* If we are in the child process do a loop and say where you at*/
    if (cpid == 0){
        int count = 0;
        printf("This is the child process\n");
        printf("The parent process has the process PID %i \n",getppid());
        printf("The child process has the process PID %i \n",getpid());
        printf("PROCESS PID %i is finishing now. \n",getpid());
        for(int i = 0; i < NUMBER_OF_LOOPS; i++){
            count++;
        }
        printf("Number of loops done in the child process %i\n", count);
        fflush(stdout);
        _exit(EXIT_SUCCESS);
    } else {
        /* Wait for the status on the child process to change */
        w = waitpid(cpid,&status,0);
        printf("This is the parent process\n");
        printf("The parent process has the process PID %i \n",getpid());
        printf("The child process has the process PID %i \n",cpid);
        printf("PROCESS PID %i is finishing now. \n",getpid());
    }


    return 0;
}