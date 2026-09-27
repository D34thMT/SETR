#ifndef CONFIG_DATA_H
#define CONFIG_DATA_H

#include <stdio.h>
#include <stdint.h>

/* Return codes */
#define CONFIGDATA_OK 0;   /* Sucess return code */

/* Prototype Functions */
int configInit(void);                           /* Initialize the maxConnections as zero*/
void configSetMaxConnections(uint16_t value);   /* Set the value of maxConnections */
uint16_t configGetMaxConnections(void);         /* Get the value of maxConnections */


#endif