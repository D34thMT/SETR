#include <unity.h>
#include "Clock.h"

void setUp(void)
{
	resetSwClock();
	return;
}
void tearDown(void)
{
	return;
}

void test_TickCount(void)
{
    countTick();
	TEST_ASSERT_EQUAL_INT(1,countCheck());
	int i = 0;
	while(i<99)
	{
		countTick();
		i++;
	}
	TEST_ASSERT_EQUAL_INT(100,countCheck());
}

void test_GetClock(void)
{
	TEST_ASSERT_EQUAL_UINT8(0,getClock().hundredths);
	int i = 0;
	while(i<1000)
	{
		countTick();
		i++;
	}
	TEST_ASSERT_EQUAL_UINT8(1,getClock().hundredths);
}

void test_UpdateSwClock(void)
{	
	int i = 0;
	while (i<99000)
	{
		countTick();
		i++;
	}
	TEST_ASSERT_EQUAL_UINT8(99,getClock().hundredths);
	TEST_ASSERT_EQUAL_UINT8(0,getClock().seconds);	
	
	i = 0;
	while (i<1000)
	{
		countTick();
		i++;
	}
	TEST_ASSERT_EQUAL_UINT8(0,getClock().hundredths);
	TEST_ASSERT_EQUAL_UINT8(1,getClock().seconds);
	
	i = 0;
	while (i<5900000)
	{
		countTick();
		i++;
	}
	TEST_ASSERT_EQUAL_UINT8(0,getClock().hundredths);
	TEST_ASSERT_EQUAL_UINT8(0,getClock().seconds);
	TEST_ASSERT_EQUAL_UINT8(1,getClock().minutes);

	i = 0;
	while (i<3050000)
	{
		countTick();
		i++;
	}
	TEST_ASSERT_EQUAL_UINT8(50,getClock().hundredths);
	TEST_ASSERT_EQUAL_UINT8(30,getClock().seconds);
	TEST_ASSERT_EQUAL_UINT8(1,getClock().minutes);
}

void test_ResetSwClock(void)
{
	int i = 0;
	while (i<9050000)
	{
		countTick();
		i++;
	}
	TEST_ASSERT_EQUAL_UINT8(50,getClock().hundredths);
	TEST_ASSERT_EQUAL_UINT8(30,getClock().seconds);
	TEST_ASSERT_EQUAL_UINT8(1,getClock().minutes);

	resetSwClock();
	TEST_ASSERT_EQUAL_UINT8(0,getClock().hundredths);
	TEST_ASSERT_EQUAL_UINT8(0,getClock().seconds);
	TEST_ASSERT_EQUAL_UINT8(0,getClock().minutes);
		
}

int main(void)
{
	UNITY_BEGIN();

	RUN_TEST(test_TickCount);
	RUN_TEST(test_GetClock);
	RUN_TEST(test_UpdateSwClock);
	RUN_TEST(test_ResetSwClock);

	return UNITY_END();
}