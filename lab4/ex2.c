#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdint.h>

#define MAX_CHAR_COMMAND 128

int main(int argc, char *argv[]){

    /* Check if the arguments count is right */
    if (argc != 3){
        printf("Usage: ex2 <prefix> <count>\n");
        return 1;
    }

    /* Convert the seconds argument (number of folders) to int type */
    int NUMBER_FOLDERS = atoi(argv[2]);
    char options[MAX_CHAR_COMMAND];
    pid_t cpid, ccpid,w;
    int errorCode, status;
    
    /* Create a fork */
    cpid = fork();
    /* Check if the child process was created */
    if (cpid == -1){
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (cpid == 0){                                             /* If cpid is 0, we are in the child process */
        printf("Child PID is %jd\n",(intmax_t) getpid());        
        for (int i = 0; i< NUMBER_FOLDERS; i++){
            ccpid = fork();

            if (ccpid == -1){
                perror("fork");
                exit(EXIT_FAILURE);
            }

            if (ccpid == 0){
                printf("Child of the 1st Child PID is %jd\n",(intmax_t) getpid());
                sprintf(options,"%s%i",argv[1],i);
                execl("/usr/bin/mkdir","mdkir",options,NULL);

                perror("mkdir failed in child");
                _exit(EXIT_FAILURE);
            } else {
                w = waitpid(ccpid,&status,0);
                if (w == -1) {
                    perror("waitpid");
                    exit(EXIT_FAILURE);
                }
            }
        } 
        execl("/usr/bin/ps", "ps", "-axu", NULL);

        perror("execl failed in child");
        _exit(EXIT_FAILURE);
    } else {                                                    /* If different than 0 and -1, we are in the parent process */
        w = waitpid(cpid, &status,0);
        if (w == -1) {
            perror("waitpid");
            exit(EXIT_FAILURE);
        }
        
       execl("/usr/bin/wc", "wc", "teste.txt", NULL);
       
       perror("excl failed in parent");
       exit(EXIT_FAILURE);
    }

    return 0;
}
