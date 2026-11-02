#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

/* Use a flag to let the main loop know a signal arrived */
volatile sig_atomic_t signal_received = 0;

static void usr1_chandler (int sig, siginfo_t *si, void *unused){
    if (sig == SIGUSR1) {
        signal_received = 1;
    }
}


int main (int argc, char* argv[]){
    
    struct sigaction sa;
    pid_t c_pid;
    
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = usr1_chandler;
    if (sigaction(SIGUSR1, &sa, NULL) == -1){ perror("sigaction"); }

    c_pid = fork();

    if (c_pid == -1) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    if (c_pid == 0) {
        /* ---------------- CHILD PROCESS ---------------- */
        int count = 0;
        printf("Child  (PID %d): Ready and waiting for signals...\n", getpid());

        while (count < 10) {
            pause(); /* Sleep until ANY signal arrives */
            
            if (signal_received) {
                count++;
                printf("Child  (PID %d): Received SIGUSR1 (Total: %d/10)\n", getpid(), count);
                signal_received = 0; /* Reset flag for the next signal */
            }
        }

        printf("Child  (PID %d): Received 10 signals. Terminating now.\n", getpid());
        exit(EXIT_SUCCESS);
        
    } else {
        /* ---------------- PARENT PROCESS ---------------- */
        printf("Parent (PID %d): Starting to send signals to Child (PID %d)...\n", getpid(), c_pid);

        for (int i = 1; i <= 10; i++) {
            sleep(1); /* Wait one second between signals */
            
            printf("Parent (PID %d): Sending SIGUSR1 (Total: %d/10)\n", getpid(), i);
            if (kill(c_pid, SIGUSR1) == -1) {
                perror("kill failed");
            }
        }

        /* Wait for the child to finish its termination process to prevent zombies */
        wait(NULL); 
        printf("Parent (PID %d): Child has terminated. Parent terminating now.\n", getpid());
        exit(EXIT_SUCCESS);
    }

    
    return 0;
}