#include "file_utils.h"

/* Return the number of lines that the file has */
int count_lines(char* filename)
{
    /* Open the file and create a new stream */
    FILE *file = fopen(filename,"r");
    /* Check if the file was open sucessfully */
    if(file == NULL)
    {
        printf("Couldn't open the file");
        return ERROR_FILE_NOT_OPENED;
    }

    int count = 0;
    // fgetc returns an int (not a char) because EOF is technically -1
    int ch; 

    // Read one character at a time until we hit End Of File
    // fgetc(file) reads the next character from the stream
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }

    // Close the file in the end o the function
    fclose(file); 

    return count;
}

/* Return the number of character that the file has */
int count_char(char* filename)
{
        /* Open the file and create a new stream */
    FILE *file = fopen(filename,"r");
    /* Check if the file was open sucessfully */
    if(file == NULL)
    {
        printf("Couldn't open the file");
        return ERROR_FILE_NOT_OPENED;
    }

    int count = 0;
    // fgetc returns an int (not a char) because EOF is technically -1
    int ch; 

    // Read one character at a time until we hit End Of File
    // fgetc(file) reads the next character from the stream
    while ((ch = fgetc(file)) != EOF) {
        if (ch != '\n') {   
            count++;
        } 
    }

    // Close the file in the end o the function
    fclose(file); 

    return count;
}