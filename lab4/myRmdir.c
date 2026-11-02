#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    
    
    if(argc != 3){
        printf("Usage: deleteFold <prefix> <count>\n");
        return 1;
    }

    int count = atoi(argv[2]);

    char option[16];
    char command[256];

    for (int i = count; i>= 1; i--){
        printf("Ready to remove the folder %s %i\n",argv[1],i);
        scanf("%s",option);
        if(!strcmp(option, "y   ")){
            printf("Deleting folder %s %i\n",argv[1],i);
            
            sprintf(command, "rmdir %s%i", argv[1], i);

            int returnCode = system(command);
            if (returnCode == 0){
                printf("Command executed successfully.\n");
            }
            else {
                printf("Command execution failed or returned non-zero: %i\n", returnCode);
            }
        } else if(!strcmp(option, "n")){
            printf("Not deleting the folder %s %i\n",argv[1],i);
        } else {
            printf("Invalid option, please write y or n\n");
            i++;
        }
    }
    
    
    return 0;
}
