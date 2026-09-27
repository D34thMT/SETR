#include "configData.h"

int main()
{
    configInit();
    printf("Max Connections is %i\n",maxConnections);
    maxConnections = 10;
    printf("Max Connections is %i\n",maxConnections);
    configInit();
    printf("Max Connections is %i\n",maxConnections);

    return 0;
}