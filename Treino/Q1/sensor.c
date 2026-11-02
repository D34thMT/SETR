#include "sensor.h"

// Define the necessary macros
#define MAX_TEMP             60
#define MIN_TEMP            -40
#define MAX_READ             64

static float tempRead[MAX_READ];
static int temp_idx;

// Initializes the module
void tempInit(void){
    // Initialize the vector module to 0
    memset(tempRead,0,sizeof(tempRead));
    // Initialize the idx of the vector
    temp_idx = 0;
}

// Registers a new reading
int tempAdd(float temp){
    if (temp_idx < MAX_READ){
        // Check if the sensor readings are inside the supposed range
        if (temp > MAX_TEMP || temp < MIN_TEMP){
            return ERROR_OUTB;
        } else {
            tempRead[temp_idx] = temp;
            temp_idx++;
            return SUCESS;
        }
    } else {
        return ERROR_EXC_LENGTH;
    }
}

// Returns the maximum temperature registered so far
int tempMax(float *tempMax){
    float temp = MIN_TEMP;
    if ((temp_idx == 0)){
        return ERROR_NO_DATA;
    } else {
        // Check if the temp reading is greater then the temporary maximum
        for (int i = 0; i < temp_idx; i++){
            if (tempRead[i] > temp){
                temp  = tempRead[i];
            }
        }

        (*tempMax) = temp;
        return SUCESS;
    }   
}

 // Returns the last temperature registered
int tempLast(float *tempLast){
    if(temp_idx == 0){
        return ERROR_NO_DATA;
    } else {
        (*tempLast) = tempRead[temp_idx - 1];
        return SUCESS;
    }
}