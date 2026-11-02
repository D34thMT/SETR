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

    /*  
    Read one character at a time until we hit End Of File
    fgetc(file) reads the next character from the stream
    When the character isn't a '\n', it's defined as a character
    */
    while ((ch = fgetc(file)) != EOF) {
        if (ch != '\n') {   
            count++;
        } 
    }

    // Close the file in the end o the function
    fclose(file); 

    return count;
}

/* Return the number of words that a file has*/
int count_word(char* filename)
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
    bool in_word = false;


    while((ch = fgetc(file)) != EOF){
        if (ch == ' '){
            in_word = false;                
        }
        else if (!in_word){
            in_word = true;
            count++;
        }
    }

    // Close the file in the end o the function
    fclose(file); 

    return count;
}

void extract_word(char* filename, char*** word)
{
    /* Open the file and create a new stream */
    FILE *file = fopen(filename,"r");
    /* Check if the file was open sucessfully */
    if(file == NULL)
    {
        printf("Couldn't open the file");
        return ERROR_FILE_NOT_OPENED;
    }
    /* Int to store the ASCII value of the actual character and the previous one */
    int ch, temp;
    /* Allocate temporary memory for the Array of array of characters */
    int array_size = 16;
    int array_index = 0;
    *word = malloc(array_size * sizeof(char*));
    /* Allocate temporary memory to build the word */
    int word_size = 10;
    int char_index = 0;
    (*word)[array_index] = malloc(word_size * sizeof(char*));

    while((ch = fgetc(file)) != EOF){
        if (isalpha(ch)){
            // If the char index is greater than the size of the word, we have to change the size and realloc 
            if (char_index >= word_size) {
                word_size *= 2;
                (*word)[array_index] = realloc((*word)[array_index], word_size * sizeof(char*));
            }   
            (*word)[array_index][char_index++] = (char)ch; 
        }else if (char_index > 0) {
            (*word)[array_index][char_index] = '\0';
            array_index++;
            if (array_index >= array_size - 1){
                array_size *= 2;
                *word = realloc(*word, array_size * sizeof(char)); 
            }
            word_size = 10;
            char_index = 0;
            (*word)[array_index] = malloc(word_size * sizeof(char*));
        }
    }

    if (char_index > 0) {
        (*word)[array_index][char_index] = '\0';
    } else {
        free((*word)[array_index]);
    }
    // Close the file in the end o the function
    fclose(file); 
}

/* Local function to see if the character cast as an integer is aphabetical*/
bool isalpha(int a)
{
    if ((a <= 0x7a && a >= 0x61) || (a <= 0x5a && a >= 0x41)){
        return true;
    } else {
        return false;
    }
}