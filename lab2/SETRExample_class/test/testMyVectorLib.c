#include <unity.h>
#include "MyVectorLib.h"

void setUp(void)
{
		
	return;
}
void tearDown(void)
{
	return;
}

void test_MyVectorLib_Init(void)
{	
	MyVectorLib_Init();
	TEST_ASSERT_EQUAL_INT(0, MyVectorLib_Len());	
}
	
void test_MyVectorLib_AddCheckSize(void)
{	
	MyVectorLib_Add(0);
	MyVectorLib_Add(27);
	MyVectorLib_Add(491);
	MyVectorLib_Add(520);
	MyVectorLib_Add(900);
	MyVectorLib_Add(3213);
	MyVectorLib_Add(12343);
	MyVectorLib_Add(999);
	TEST_ASSERT_EQUAL_INT(8, MyVectorLib_Len());	
}	

void test_MyVectorLib_Find_NotThere(void)
{
	TEST_ASSERT_EQUAL_INT(0, MyVectorLib_Find(-14));	
	TEST_ASSERT_EQUAL_INT(0, MyVectorLib_Find(40000));
	TEST_ASSERT_EQUAL_INT(0, MyVectorLib_Find(999999));
}

void test_MyVectorLib_Find_AreThere(void)
{
	TEST_ASSERT_EQUAL_INT(0, MyVectorLib_Find(0));
	TEST_ASSERT_EQUAL_INT(1, MyVectorLib_Find(27));
	TEST_ASSERT_EQUAL_INT(4, MyVectorLib_Find(900));
	TEST_ASSERT_EQUAL_INT(7, MyVectorLib_Find(999));
	
}

void test_MyVectorLib_Len_RightSize(void)
{
	TEST_ASSERT_EQUAL_INT(8, MyVectorLib_Len());
}


void test_MyVectorLib_DeleteCheckSize(void)
{
	MyVectorLib_Delete(900);
	MyVectorLib_Delete(27);
	MyVectorLib_Delete(11111);
	TEST_ASSERT_EQUAL_INT(6, MyVectorLib_Len());
}

void test_MyVectorLib_Sort(void)
{
	TEST_ASSERT_EQUAL_INT(4, MyVectorLib_Find(12343));
	MyVectorLib_Sort();
	TEST_ASSERT_EQUAL_INT(5, MyVectorLib_Find(12343));
}

void test_MyVectorLib_Max(void)
{
	TEST_ASSERT_EQUAL_INT(12343, MyVectorLib_Max());
	MyVectorLib_Add(500000);
	TEST_ASSERT_EQUAL_INT(500000, MyVectorLib_Max());
	MyVectorLib_Add(20);
	TEST_ASSERT_EQUAL_INT(500000, MyVectorLib_Max());
	MyVectorLib_Delete(500000);
	MyVectorLib_Delete(20);	
}

void test_MyVectorLib_Min(void)
{
	TEST_ASSERT_EQUAL_INT(0, MyVectorLib_Min());
	MyVectorLib_Delete(0);
	TEST_ASSERT_EQUAL_INT(491, MyVectorLib_Min());
	MyVectorLib_Add(0);
	MyVectorLib_Sort();

}

void test_MyVectorLib_Avg(void)
{
	TEST_ASSERT_EQUAL_INT(2927, MyVectorLib_Avg());
}


int main(void)
{
	UNITY_BEGIN();
	
	RUN_TEST(test_MyVectorLib_AddCheckSize);			
	RUN_TEST(test_MyVectorLib_Find_NotThere);
	RUN_TEST(test_MyVectorLib_Find_AreThere);
	RUN_TEST(test_MyVectorLib_Len_RightSize);
	RUN_TEST(test_MyVectorLib_DeleteCheckSize);
	RUN_TEST(test_MyVectorLib_Sort);
	RUN_TEST(test_MyVectorLib_Max);
	RUN_TEST(test_MyVectorLib_Min);
	RUN_TEST(test_MyVectorLib_Avg);

	return UNITY_END();
}
