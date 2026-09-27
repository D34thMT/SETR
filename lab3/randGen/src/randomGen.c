#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Protype Functions */
void myRand(int *value, int *ncalls); /* Generates a random number between [0,100] 
                                         and keeps track of how many times it has been called */

int main()
{
    /* Initialize the random number generator */
    srand(time(NULL));

    /* Initialize the variables to start the count */
    int call = 0;
    int randValue = 0;

    int i = 0;
    while (i < 10)
    {
        /* Call in each iteration the fucntion */
        myRand(&randValue,&call);

        /* Print the output of the function */
        printf("The random number generated was %i. \n", randValue);
        printf("The function was called %i times.\n", call);
        i++;
    }

    return 0;
}

void myRand(int *value, int *ncalls)
{
    /* Define the maximum and minimum interger value */
    int max = 100;
    int min = 0;
    
    /* Generate the random number */
    (*value) = rand() % (max - min + 1) + min;
    /* Increment the number of times that the myRand function is called */
    (*ncalls)++;
}