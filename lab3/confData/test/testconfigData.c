#include <unity.h>
#include "configData.h"

void setUp(void)
{
	return;
}

void tearDown(void)
{
	return;
}

void test_configInit()
{
    configInit();
    TEST_ASSERT_EQUAL_INT(0,configGetMaxConnections());
}

void test_configSetMaxConnections()
{
    TEST_ASSERT_EQUAL_INT(0,configGetMaxConnections());
    configSetMaxConnections(16);
    TEST_ASSERT_EQUAL_INT(16,configGetMaxConnections());
    configSetMaxConnections(75);
    TEST_ASSERT_EQUAL_INT(75,configGetMaxConnections());
    configSetMaxConnections(10);
    TEST_ASSERT_EQUAL_INT(10,configGetMaxConnections());
    configSetMaxConnections(0);
    TEST_ASSERT_EQUAL_INT(0,configGetMaxConnections());
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_configInit);
    RUN_TEST(test_configSetMaxConnections);

    return UNITY_END();
}