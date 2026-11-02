#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>

/* Configure the necessary flags for the timer functionality */
volatile sig_atomic_t suspended;
volatile sig_atomic_t reset;

static void handler(int sig, siginfo_t *si, void *unused);

int main(int argc, char* argv[]){

    /* Initialize the counter */
    int count = 0;
    struct sigaction sa, sa_ignore;
    /* Configure sa struct */
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = handler;
    /* Configure sa_ignore struct */
    sa_ignore.sa_flags = 0;
    sigemptyset(&sa_ignore.sa_mask);
    sa_ignore.sa_handler = SIG_IGN;
    /* Configure sigaction to use the handler */
    for(int i = 0; i < 32; i++) {
        if ((i == SIGINT) || (i == SIGHUP) || (i == SIGCONT)){
            sigaction(i, &sa, NULL);
        } else if ((i == SIGKILL) || (i == SIGSTOP)){
            continue;
        } else {
            sigaction(i, &sa_ignore, NULL);
        }
    }

    printf("This is the process ID : %i\n",getpid());
    printf("Commands:\n");
    printf("  Ctrl+C (SIGINT)  : Reset and continue\n");
    printf("  kill -HUP %d     : Suspend counting\n", getpid());
    printf("  kill -CONT %d    : Resume counting\n", getpid());
    printf("----------------------------------------\n");

    while(1){
        /* If the reset flag is on we will reset the timer */
        if(reset){
            count = 0;
            /* After the reset we will put the flag down to start counting again */
            reset = 0;
        }
        /* If the activity is not suspended we will increment the counter and see how much time has passed */
        if(!suspended){
            printf("Seconds elapsed: %i \n",count);
            count++;
        }
        /* Sleep for one second */
        sleep(1);    
    }

    return 0;
}

static void handler(int sig, siginfo_t *si, void *unused) {
    const char *msg;
    
    switch (sig) {
        /* In case of SIGINT being receive the counter restarts */
        case SIGINT:
            reset = 1;
            suspended = 0;
            break;
        /* In case of SIGHUP being receive the counter suspends it */
        case SIGHUP:
            suspended = 1;
            break;
        /* In case of SIGCONT being received the counter resumes the functionality */
        case SIGCONT:
            suspended = 0;
            break;
        default:
        
    }
}
