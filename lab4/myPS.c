#include <stdio.h>

int main(void){

    char* command = "ps -axu"; 

    int returnCode = system(command);

    if (returnCode == 0) {
        printf("Command executed successfully.\n");
    }
    else {
        printf("Command execution failed or returned non-zero: %i", returnCode);
    }

    return 0;
};