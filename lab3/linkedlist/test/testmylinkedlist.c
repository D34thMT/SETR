#include <unity.h>
#include "mylinkedlist.h"

void setUp(void)
{
    // This is run before EACH test
    return;
}

void tearDown(void)
{
    // This is run after EACH test
    return;
}

void test_createNode(void)
{
    struct Node* head = createNode(20);
    
    TEST_ASSERT_NOT_NULL(head);
    TEST_ASSERT_EQUAL_INT(20, head->data);
    TEST_ASSERT_NULL(head->next);
    
    // Clean up to prevent memory leaks during testing
    free(head);
}

void test_insertNode(void)
{
    struct Node* head = NULL;

    // Test inserting the first node
    insertNode(&head, 10);
    TEST_ASSERT_NOT_NULL(head);
    TEST_ASSERT_EQUAL_INT(10, head->data);
    TEST_ASSERT_NULL(head->next);

    // Test inserting a second node (should be prepended)
    insertNode(&head, 20);
    TEST_ASSERT_NOT_NULL(head);
    TEST_ASSERT_EQUAL_INT(20, head->data);
    TEST_ASSERT_NOT_NULL(head->next);
    TEST_ASSERT_EQUAL_INT(10, head->next->data);

    // Clean up
    deleteNode(&head);
    deleteNode(&head);
}

void test_deleteNode(void)
{
    struct Node* head = NULL;

    // Test deleting from an empty list (safety check)
    // If the safety check fails, this will likely cause a segfault and fail the test
    deleteNode(&head);
    TEST_ASSERT_NULL(head);

    // Populate the list
    insertNode(&head, 5);
    insertNode(&head, 15);
    insertNode(&head, 25);

    // Test deleting the head node (25)
    deleteNode(&head);
    TEST_ASSERT_NOT_NULL(head);
    TEST_ASSERT_EQUAL_INT(15, head->data); // 15 should now be the head

    // Test deleting the rest
    deleteNode(&head);
    TEST_ASSERT_EQUAL_INT(5, head->data); // 5 should now be the head
    
    deleteNode(&head);
    TEST_ASSERT_NULL(head); // List should now be completely empty
}

void test_printNodedata(void)
{
    struct Node* head = NULL;
    
    // Print empty list
    printNodedata(head); 
    
    // Print populated list
    insertNode(&head, 100);
    insertNode(&head, 200);
    printNodedata(head);

    // Clean up
    deleteNode(&head);
    deleteNode(&head);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_createNode);
    RUN_TEST(test_insertNode);
    RUN_TEST(test_deleteNode);
    RUN_TEST(test_printNodedata);

    return UNITY_END();
}