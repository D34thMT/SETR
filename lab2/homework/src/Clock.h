#ifndef CLOCK_H
#define CLOCK_H

#include <stdint.h>

typedef struct {
    uint8_t hundredths;
    uint8_t seconds;
    uint8_t minutes;
} swClock_t;

void resetSwClock();    /* Set all fields to zero*/
void updateSwClock();   /* Called every 10ms to update the clock value*/


#endif