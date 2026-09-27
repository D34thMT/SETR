#include "configData.h"

uint16_t maxConnections;

/* Initialize the maxConnections as zero*/
int configInit(void)
{
    maxConnections = 0;

    return CONFIGDATA_OK;
}

/* Set the value of maxConnections */
void configSetMaxConnections(uint16_t value)
{
    maxConnections = value;
}

/* Get the value of maxConnections */
uint16_t configGetMaxConnections(void)
{
    return maxConnections;
}