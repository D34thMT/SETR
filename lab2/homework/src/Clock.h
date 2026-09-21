#ifndef CLOCK_H
#define CLOCK_H

#include <stdint.h>

#define PERIOD 1000

typedef struct {
    uint8_t hundredths;
    uint8_t seconds;
    uint8_t minutes;
} swClock_t;

/* Function prototypes */
void countTick(void);       /* Increment a counter */
int  countCheck(void);      /* Function to check the counter value*/
swClock_t getClock(void);   /* Returns the values of the local variable myClock */
void resetSwClock(void);    /* Set all fields to zero */
void updateSwClock(void);   /* Called every 10ms to update the clock value */


#endif