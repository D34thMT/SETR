#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>
#include <pthread.h>

volatile int counter=0;
volatile bool update = false; 
volatile bool terminate = false;

void* w_counter(void* arg){
    while(1){
        if (counter < 10){
            counter++;
            update = true;
        } else {
            terminate = true;
            return NULL;
        }
        sleep(1);
    }
}

void* w_print(void*arg){
    while(1){
        if(update){ 
            printf("Seconds elapsed : %i \n",counter);
            fflush(stdout);
            update = false;
        }

        if(terminate){
            return NULL;
        }
    }
}   

int main(int argc, char* argv[]){

    pthread_t tid_w1,tid_w2;

    printf("Main thread: Creating two threads named w_counter and w_print\n");

    pthread_create(&tid_w1,NULL,w_counter,NULL);
    pthread_create(&tid_w2,NULL,w_print,NULL);
    pthread_join(tid_w1,NULL);
    pthread_join(tid_w2,NULL);

    printf("Main thread: both threads finished, exiting.\n");

    return 0;
}