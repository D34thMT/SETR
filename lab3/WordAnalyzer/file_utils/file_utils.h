#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR_FILE_NOT_OPENED -1;
#define SUCESS 0;

/* Function Prototypes */
int count_lines(char* filename);                    /* Return the number of lines that a file has */
int count_char(char* filename);                     /* Return the number of character that a file has */
int count_word(char* filename);                     /* Return the number of words that a file has*/
void extract_word(char* filename, char*** word);    /**/

#endif