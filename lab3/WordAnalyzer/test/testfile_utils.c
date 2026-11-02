#include <unity.h>
#include <file_utils.h>

void setUp()
{

}

void tearDown()
{

}

void test_file_countlines(){
    char* filename = "helloworld";
    TEST_ASSERT_EQUAL_INT(-1,count_lines(filename));
    char* filename1 = "ficheiro_file_utils.txt";
    TEST_ASSERT_EQUAL_INT(1,count_lines(filename1));
}

void test_file_countchar(){
    char* filename = "helloworld";
    TEST_ASSERT_EQUAL_INT(-1,count_char(filename));
    char* filename1 = "ficheiro_file_utils.txt";
    TEST_ASSERT_EQUAL_INT(8,count_char(filename1));
}

void test_file_countword(){
    char* filename = "ficheiro_file_utils.txt";
    TEST_ASSERT_EQUAL_INT(2,count_word(filename));    
}

void test_file_extractword(){
    char* filename = "ficheiro_file_utils.txt";
    
}

int main(void) 
{
    UNITY_BEGIN();

    RUN_TEST(test_file_countlines);
    RUN_TEST(test_file_countchar);
    RUN_TEST(test_file_countword);

    return UNITY_END();
}