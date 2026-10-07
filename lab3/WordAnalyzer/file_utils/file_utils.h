#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ERROR_FILE_NOT_OPENED -1;

/* Function Prototypes */
int count_lines(char* filename);            /* Return the number of lines that the file has */
int count_char(char* filename);             /* Return the number of character that the file has */
#endif