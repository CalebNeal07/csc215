# CSC 215 - Computer Systems

## **Altair Manual Notes**
 1. [Logic & Number Systems](Notes/AltairManualPart1notes.md)

 3. [Operating the Altair 8800](Notes/AltairManualPart3notes.md)

## **CP/M Assembly Language Programming (1983) Notes**
 - [Chapter 1 - Hardware Components of The Computer System](./Notes/CPM_Asm-Chp1.md)
 - [Chapter 9 - Register Usage in the 8080](./Notes/CPM_chp9.md)
 - [Chapter 11](./Notes/Chapter11.md)
 - [Chapter 12](./Notes/Chapter12.md)
 - [Chapter 13](./Notes/Chapter13.md)

## The C Programming Language Exercises
[Line Counter](./C/LC.C)
 - *1-6:* [COUNT.C](./C/COUNT.C)
 - *1-7:* [SW.C](./C/SW.C)
 - *1-8:* [1-8.C](./C/1-8.C)
 - *1-9:* The boundaries are the limits of  

## Rudimentary Unit Testing Framework for BDS C
[CTEST.H](./C/BDS_CTEST/CTEST.H) - Single header with basic unit test functionality
### Example
**ISQRT.H**
```c
/* Source: https://en.wikipedia.org/wiki/Integer_square_root#Linear_search_using_addition 
Finds the floored square root of y*/
unsigned isqrt(y)
unsigned y;
{
    unsigned L;
    unsigned a;
    unsigned d;

    L = 0;
    a = 1;
    d = 3;

    while (a <= y)
    {
        a = a + d;
        d = d + 2;
        L = L + 1;
    }

    return L;
}
```

**TEST.C**
```c

#include "CTEST.H"

#include "VEC.H"

main() {
    BEGIN_TESTING("VEC.H");

    TEST("INTEGER SQUARE ROOT WITH ASSERT") {
        ASSERT(isqrt(4) == 2);
    }

    TEST("INTEGER SQUARE ROOT WITH ASSERT_EQ") {
        ASSERT_EQ(isqrt(4), 2);
    }

    TEST("INTENTIONAL FAILURE") {
        ASSERT(1 == 2);
    }

    TEST("MANUAL PASS/FAIL") {
        if (isqrt(5) == 3) {
            PASS();
        } else {
            FAIL();
        }
    }

    END_TESTING();
}
```

## Rational Numbers
Rational numbers implemented using the number's position in the [Calkin-Wilf Sequence](https://en.wikipedia.org/wiki/Calkin%E2%80%93Wilf_tree#Breadth_first_traversal)

Code is in [this](https://github.com/CalebNeal07/rational) repo.
