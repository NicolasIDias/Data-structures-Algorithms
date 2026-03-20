#include "color.h"
#include "munit.h"

#define RUN
#define SUBMIT

#define munit_case(case_name, test_name, block)                                             \
    static MunitResult test_name(const MunitParameter params[], void *user_data_or_fixture) \
    {                                                                                       \
        (void)params;                                                                       \
        (void)user_data_or_fixture;                                                         \
        block return MUNIT_OK;                                                              \
    }

#undef assert_int
#define assert_int(a, op, b, msg)                                                                    \
    do                                                                                               \
    {                                                                                                \
        int assert_tmp_a_ = (a);                                                                     \
        int assert_tmp_b_ = (b);                                                                     \
        if (MUNIT_UNLIKELY(!(assert_tmp_a_ op assert_tmp_b_)))                                       \
        {                                                                                            \
            munit_errorf("Assertion failed: %s (%d %s %d)", msg, assert_tmp_a_, #op, assert_tmp_b_); \
        }                                                                                            \
    } while (0)

#define munit_test(name, func) \
    {(char *)name, func, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}

#define munit_null_test \
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}

#define munit_suite(name, tests) \
    {(char *)name, tests, NULL, 1, MUNIT_SUITE_OPTION_NONE}

munit_case(RUN, test_color_enum1, {
    assert_int(RED, ==, 0, "RED is defined as 0");
    assert_int(GREEN, ==, 1, "GREEN is defined as 1");
    assert_int(BLUE, ==, 2, "BLUE is defined as 2");
});

munit_case(SUBMIT, test_color_enum2, {
    assert_int(RED, !=, 4, "RED is not defined as 4");
    assert_int(GREEN, !=, 2, "GREEN is not defined as 2");
    assert_int(BLUE, !=, 0, "BLUE is not defined as 0");
});

int main()
{
    MunitTest tests[] = {
        munit_test("/are_defined", test_color_enum1),
        munit_test("/are_defined_correctly", test_color_enum2),
        munit_null_test,
    };

    MunitSuite suite = munit_suite("colors", tests);

    return munit_suite_main(&suite, NULL, 0, NULL);
}
