#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>


volatile int counter;

void handle_sigusr1(int sig){
    (void) sig;
    printf("[Handler] Entered SIGUSR1 handler\n");
    // simulate long work inside handler
    sleep(5);

    counter++;
    printf("[Handler] Leaving SIGUSR1 handler, counter=%d\n",counter);
    fflush(stdout);
}

int main(int argc, char* argv[]){
    
    /* Configure the sigaction struct and to wait for the handeler to finish for process the SIGUSR2*/
    struct sigaction sa;
    sa.sa_handler = handle_sigusr1;
    sigemptyset(&sa.sa_mask);
    sigaddset(&sa.sa_mask,SIGUSR2);
    sa.sa_flags = 0;    

    printf("The PID of this process is [%i]\n",getpid());

    if (sigaction(SIGUSR1, &sa, NULL) == -1){ perror("sigaction"); }

    while(1){ }

    return 0;
}