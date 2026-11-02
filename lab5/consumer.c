#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>




int main(void){
    // Define the constants for the code
    const char* pathname = "my_fifo";
    ssize_t bytes_read;
    int descpritor, val;
    // Open the file to read only 00 - 0_RDONLY
    descpritor = open(pathname, O_RDONLY);
    if (descpritor == -1){
        perror("open producer");
        _exit(EXIT_FAILURE);
    }

    while ((bytes_read = read(descpritor, &val, sizeof(int))) > 0) {
        printf("[Consumer] Received: %d\n", val);
    }

    if (bytes_read == -1) {
        perror("read");
    }

    close(descpritor);
    unlink(pathname);
    printf("[Consumer] FIFO closed and removed.\n");

    return 0;
}