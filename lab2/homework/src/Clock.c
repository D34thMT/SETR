#include <Clock.h>

static swClock_t myClock;

static int tick = 0;

/* Increment a counter */
void countTick(void)
{
    tick += 1;

    /* If tick count reaches the PERIOD value, it hit 10ms */
    if (tick >= PERIOD)
    {
        updateSwClock();
        tick = 0;
    }
}

/* Function to check the counter value */
int countCheck(void)
{
    return tick;
}

/* Returns the values of the local variable myClock */
swClock_t getClock(void)
{
    return myClock;
}


/* Set all fields to zero */
void resetSwClock(void)
{
    myClock.hundredths = 0;
    myClock.seconds = 0;
    myClock.minutes = 0;
    tick = 0;
}

/* Called every 10ms to update the clock value */
void updateSwClock(void)
{
    /* hundreths + 1 */
    myClock.hundredths += 1;
    /* If the hundretdths reach a value of 100, round the seconds*/
    if (myClock.hundredths % 100 == 0)
    {
        myClock.seconds += 1;
        myClock.hundredths = 0;
        /* If the seconds reach a value of 60, round the minutes*/
        if(myClock.seconds % 60 == 0)
        {
            myClock.minutes += 1;
            myClock.seconds = 0;
        }
    }   
}