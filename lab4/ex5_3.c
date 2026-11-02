#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

// Signal handler to catch SIGUSR1. 
// It does nothing, but catching it prevents the process from terminating.
void handle_sigusr1(int sig) {
    (void)sig; // Suppress unused parameter warning
}

// Thread function
void* thread_routine(void* arg) {
    int thread_id = *(int*)arg;
    
    printf("Thread %d: Started and waiting for signal...\n", thread_id);
    
    // pause() suspends the thread until a signal is caught
    pause(); 
    
    // Once the signal is caught and the handler returns, the thread continues here
    printf("Thread %d: Received signal. Terminating...\n", thread_id);
    
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    int id1 = 1, id2 = 2;
    
    // 1. Register the signal handler for SIGUSR1
    struct sigaction sa;
    sa.sa_handler = handle_sigusr1;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("Error setting up sigaction");
        exit(EXIT_FAILURE);
    }

    // 2. Create the two threads
    if (pthread_create(&thread1, NULL, thread_routine, &id1) != 0) {
        perror("Failed to create thread 1");
        exit(EXIT_FAILURE);
    }
    if (pthread_create(&thread2, NULL, thread_routine, &id2) != 0) {
        perror("Failed to create thread 2");
        exit(EXIT_FAILURE);
    }

    // Short delay to ensure threads reach the pause() state before signals are sent
    sleep(1); 

    // 3. Send signal SIGUSR1 to the first thread
    printf("Main: Sending SIGUSR1 to Thread 1...\n");
    pthread_kill(thread1, SIGUSR1);
    
    // 4. Wait for a one-second interval
    sleep(1);
    
    // 5. Send signal SIGUSR1 to the second thread
    printf("Main: Sending SIGUSR1 to Thread 2...\n");
    pthread_kill(thread2, SIGUSR1);

    // 6. Wait for both threads to terminate
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    printf("Main: Both threads have terminated. Main thread exiting.\n");
    
    return 0;
}