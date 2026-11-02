#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>




int main(void){
    // Define the constants for the code
    const char* pathname = "my_fifo";
    int descpritor, val;
    // Create and check if the fifo is created properly
    if(mkfifo(pathname,0666) == -1){
        if(errno != EEXIST){
            perror("mkfifo");
            _exit(EXIT_FAILURE);
        }
    }
    printf("Producer: Openning FIFO\n");
    // Open the file to write only 01 - 0_WRONLY
    descpritor = open(pathname, O_WRONLY);
    if (descpritor == -1){
        perror("open producer");
        _exit(EXIT_FAILURE);
    }
    printf("Producer: Enter integers (CTRL+D to stop):\n");
    while (scanf("%d", &val) == 1)
    {
        if (write(descpritor, &val, sizeof(int)) == -1){
            perror("write");
            break;
        }   
    }
    
    close(descpritor);
    printf("Producer: Finished sensding data.\n");
    return 0;
}