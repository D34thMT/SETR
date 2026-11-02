#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    int n;
    char dirname[128];
    char i_str[32];

    printf("How many directories do you want to create?\n");
    scanf("%i",&n);
    printf("What is the name of the directories?\n");
    scanf("%s",dirname);

    for (int i=1; i <= n; i++){
        
        sprintf(i_str,"%i",i);

        char command[256];
        strcpy(command, "mkdir ");
        strcat(command, dirname);
        strcat(command, i_str);
        
        int returnCode = system(command);
        if (returnCode == 0) {
            printf("Command executed successfully.\n");
        }
        else {
            printf("Command execution failed or returned non-zero: %i", returnCode);
        }
    }
    return 0;
}