#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* Prototype Functions */

/* Generates a random number between [0,max] */
void myRand(int *value, int max); 

/* Allocate memory to an array, with random values between 1 and M and returns the pointer, average, min and max*/
int *arrayManage(int N, int M, int *avg, int *min, int *max);

/* Swap two integer values using pointers */
int swap(int *value1, int *value2);

/* Reverse a string using pointer arithmetic */
int reverse(char *str);

int main(void)
{
    /* Initialize the random number generator */
    srand(time(NULL));

    int n = 20;
    int m = 100;
    int avg, min, max;

    int *arr = arrayManage(n, m, &avg, &min, &max);

    if (arr != NULL) {
        printf("Array elements: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\nMin: %d | Max: %d | Avg: %d\n", min, max, avg);

        /* Free allocated memory */
        free(arr);
    }

    int a = 6;
    int b = 183;

    printf("VALUE A: %i       VALUE B: %i\n", a, b);
    swap(&a,&b);
    printf("VALUE A: %i     VALUE B: %i\n", a, b);  
    
    
    char text[] = "Embedded Systems";

    printf("Original: %s\n", text);
    reverse(text);
    printf("Reversed: %s\n", text);

    return 0;
}

void myRand(int *value, int max)
{
    /* Define the minimum interger value */
    int min = 1;
    
    /* Generate the random number */
    (*value) = rand() % (max - min + 1) + min;
}

int *arrayManage(int N, int M, int *avg, int *min, int *max)
{
    /* Allocate the memory for an Array of N integers */
    int *vector = malloc(N * sizeof(int));
    /* Initialize the variable that stores the random values of the array */
    int randomValue = 0;
    /* Initialize the variables needed to compute the avg, maximum and minimum */
    int sum = 0;
    int maximum = 1;
    int minimum = 1000;

    /* Initialize the array with random values between 1 and M */
    for (int i = 0; i < N; i++)
    {
        /* Call myRand to compute the random values */
        myRand(&randomValue, M);
        /* Putting the random values inside the array */
        vector[i] = randomValue;
        /* Computing the sum of all elements */
        sum = sum + vector[i]; 

        /* Verify if the element is greater then the previous maximum */
        if(vector[i] > maximum)
        {
            maximum = vector[i];
        } 

        /* Verify if the element is greater then the previous minimum */
        if (vector[i] < minimum)
        {
            minimum = vector[i];
        }
    }

    /* Compute the average */
    (*avg) = sum/N;
    (*max) = maximum;
    (*min) = minimum;
    /* Return the pointer to the array */
    return vector;
}

int swap(int *value1, int *value2)
{
    /* Create a local variable*/
    int temp;

    if (value1 != NULL && value2 != NULL)
    {
        /* Put the value of one of the number inside the temp variable */
        temp = (*value2);
        /* Change the values */
        (*value2) = (*value1);
        (*value1) = temp;
        /* Return 0 if went good */
        return 0;
    } else {
        /* Return 1 if it went bad */
        return 1;
    }
}

int reverse(char *str)
{
    /* Check for NULL pointer */
    if (str == NULL) {
        return 1; 
    }

    char *start = str;
    char *end = str;

    /* Advance 'end' until it points to the null terminator '\0' */
    while (*end != '\0') {
        end++;
    }

    /* If string is empty, nothing to reverse */
    if (end == start) {
        return 0;
    }

    /* Move 'end' back to the last printable character */
    end--;

    /* Swap characters moving pointers inward until they cross */
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;

        /* Pointer arithmetic: advance start forward, end backward */
        start++;
        end--;
    }

    return 0;
}