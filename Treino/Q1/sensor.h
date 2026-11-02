#ifndef SENSOR_H
#define SENSOR_H

#include <stdio.h>
#include <string.h>

#define SUCESS                0
#define ERROR_NO_DATA        -1
#define ERROR_OUTB           -2
#define ERROR_EXC_LENGTH     -3


void tempInit(void);            // Initializes the module
int tempAdd(float temp);        // Registers a new reading
int tempMax(float *tempMax);    // Returns the maximum temperature registered so far
int tempLast(float *tempLast);  // Returns the last temperature registered

#endif