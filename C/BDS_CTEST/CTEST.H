#include <stdio.h>

#define TRUE 1;
#define FALSE 0;

unsigned num_tests;
unsigned passed;
unsigned failed;
char test_failed;

BEGIN_TESTING(file)
char *file;
{
    printf("\n \033[36m---\033[0m %s \033[36m---\033[0m\n", file); 
    num_tests = 0; 
    passed = 0; 
    failed = 0; 
    test_failed = TRUE;
}

#define TEST(description) printf("\n\033[34m-\033[0m %s\n", description); num_tests++;

ASSERT(boolean_expr)
int boolean_expr;
{
    if(boolean_expression) {
        PASS();
    } else {
        FAIL();
    }
}

#define ASSERT_EQ(a, b) if (a == b) PASS(); else FAIL();

PASS() {
     passed++;
     printf("\t\033[32mPassed\033[0m");
 }


FAIL() {
    failed++;
    printf("\t\033[31mFailed\033[0m");
}

END_TESTING() {
    printf("\n-----------------------------\n");
    printf(" Ran \033[36m%d\033[0m tests\n", num_tests);
    if(failed > 0) {
        printf(" \033[32m%d passed\033[0m, \033[31m%d failed\033[0m\n", passed, failed);
    } else {
        printf(" \033[32m%d passed\033[0m, %d failed\n", passed, failed);
    }
    printf("-----------------------------\n");
}