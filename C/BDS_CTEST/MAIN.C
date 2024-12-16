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