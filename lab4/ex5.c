#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

/* Define the function for the thread number 1*/
void *worker1(void *arg){
    printf("Thread 1 is starting.\n");
    sleep(3);
    printf("Thread 1 is finishing.\n");
    fflush(stdout);
    return NULL;
}
/* Define the function for the thread number 2 */
void *worker2(void *arg){
    printf("Thread 2 is starting.\n");
    sleep(1);
    printf("Thread 2 is finishing.\n");
    fflush(stdout);
    return NULL;
}


int main(int argc, char* argv[]){

    pthread_t tid_w1,tid_w2;

    printf("Main thread: creating two threads named 1 and 2\n");

    pthread_create(&tid_w1,NULL,worker1,NULL);
    pthread_create(&tid_w2,NULL,worker2,NULL);
    pthread_join(tid_w1,NULL);
    pthread_join(tid_w2,NULL);

    printf("Main thread: both threads finished, exiting.\n");

    return 0;
}