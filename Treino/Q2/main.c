#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv){
    // Process ID
    pid_t cpid, w;
    int wstatus;
    // Fork to create a child process
    cpid = fork();
    // Check if the process was created
    if (cpid == -1){
        perror("fork");
        _exit(EXIT_FAILURE);
    }
    // Code done by the child process
    if (cpid == 0){
        printf("Child PID is %jd\n", (intmax_t) getpid());
        execl("/usr/bin/find","find",".","-type","f","-name","*.temp","-delete",NULL);

        perror("Error in the command find");
        _exit(EXIT_FAILURE);
    } else {
        w = wait(&wstatus);     
        if (w == -1){
            perror("wait");
            _exit(EXIT_FAILURE);
        }
        printf("The cleanup was done sucessfully.\n");
        _exit(EXIT_SUCCESS);
    }
}
