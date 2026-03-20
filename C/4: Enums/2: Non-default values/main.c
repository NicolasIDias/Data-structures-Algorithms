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

munit_case(RUN, test_colors_defined, {
    assert_int(RED, ==, 55, "RED is defined as 55 (nvim green!)");
    assert_int(GREEN, ==, 176, "GREEN is defined as 176 (nvim green!)");
    assert_int(BLUE, ==, 38, "BLUE is defined as 38 (nvim green!)");
});

munit_case(SUBMIT, test_colors_defined_correctly, {
    assert_int(RED, !=, 0, "RED is not defined as 0 (vsc*de blue!)");
    assert_int(GREEN, !=, 120, "GREEN is not defined as 120 (vsc*de blue!)");
    assert_int(BLUE, !=, 215, "BLUE is not defined as 215 (vsc*de blue!)");
});

int main()
{
    MunitTest tests[] = {
        munit_test("/defined", test_colors_defined),
        munit_test("/defined_vscode", test_colors_defined_correctly),
        munit_null_test,
    };

    MunitSuite suite = munit_suite("colors", tests);

    return munit_suite_main(&suite, NULL, 0, NULL);
}
