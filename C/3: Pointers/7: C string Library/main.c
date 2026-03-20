#include "exercise.h"
#include "munit.h"
#include <string.h>

#define RUN
#define SUBMIT

#define munit_case(case_name, test_name, block)                                           \
  static MunitResult test_name(const MunitParameter params[], void *user_data_or_fixture) \
  {                                                                                       \
    (void)params;                                                                         \
    (void)user_data_or_fixture;                                                           \
    block return MUNIT_OK;                                                                \
  }

#undef munit_assert_int
#define munit_assert_int(a, op, b, msg)                                                      \
  do                                                                                         \
  {                                                                                          \
    int munit_tmp_a_ = (a);                                                                  \
    int munit_tmp_b_ = (b);                                                                  \
    if (MUNIT_UNLIKELY(!(munit_tmp_a_ op munit_tmp_b_)))                                     \
    {                                                                                        \
      munit_errorf("Assertion failed: %s (%d %s %d)", msg, munit_tmp_a_, #op, munit_tmp_b_); \
    }                                                                                        \
  } while (0)

#undef munit_assert_string_equal
#define munit_assert_string_equal(a, b, msg)                                  \
  do                                                                          \
  {                                                                           \
    if (MUNIT_UNLIKELY(strcmp((a), (b)) != 0))                                \
    {                                                                         \
      munit_errorf("Assertion failed: %s (\"%s\" != \"%s\")", msg, (a), (b)); \
    }                                                                         \
  } while (0)

#define munit_test(name, func) \
  {(char *)name, func, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}

#define munit_null_test \
  {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}

#define munit_suite(name, tests) \
  {(char *)name, tests, NULL, 1, MUNIT_SUITE_OPTION_NONE}

munit_case(RUN, test_return_1_for_null_value, {
  TextBuffer dest;
  const char *src = NULL;
  int result = smart_append(&dest, src);
  munit_assert_int(result, ==, 1, "Should return 1 for null value");
});

munit_case(RUN, test_smart_append_empty_buffer, {
  TextBuffer dest;
  strcpy(dest.buffer, "");
  dest.length = 0;
  const char *src = "Hello";
  int result = smart_append(&dest, src);
  munit_assert_int(result, ==, 0, "Should return 0 for successful append");
  munit_assert_string_equal(dest.buffer, "Hello",
                            "Buffer should contain 'Hello'");
  munit_assert_int(dest.length, ==, 5, "Length should be 5");
});

munit_case(SUBMIT, test_smart_append_full_buffer, {
  TextBuffer dest;
  strcpy(dest.buffer,
         "This is a very long string that will fill up the entire buffer.");
  dest.length = 63;
  const char *src = " Extra";
  int result = smart_append(&dest, src);
  munit_assert_int(result, ==, 1, "Should return 1 for unsuccessful append");
  munit_assert_string_equal(
      dest.buffer,
      "This is a very long string that will fill up the entire buffer.",
      "Buffer should remain unchanged");
  munit_assert_int(dest.length, ==, 63, "Length should remain 63");
});

munit_case(SUBMIT, test_smart_append_overflow, {
  TextBuffer dest;
  strcpy(dest.buffer, "This is a long string");
  dest.length = 21;
  const char *src = " that will fill the whole buffer and leave no space for "
                    "some of the chars.";
  int result = smart_append(&dest, src);
  munit_assert_int(result, ==, 1, "Should return 1 for overflow append");
  munit_assert_string_equal(
      dest.buffer,
      "This is a long string that will fill the whole buffer and leave",
      "Buffer should be filled to capacity");
  munit_assert_int(dest.length, ==, 63,
                   "Length should be 63 after overflow append");
});

int main()
{
  MunitTest tests[] = {
      munit_test("/test_return_1_for_null_value", test_return_1_for_null_value),
      munit_test("/test_smart_append_empty_buffer",
                 test_smart_append_empty_buffer),
      munit_test("/test_smart_append_full_buffer",
                 test_smart_append_full_buffer),
      munit_test("/test_smart_append_overflow", test_smart_append_overflow),
      munit_null_test,
  };

  MunitSuite suite = munit_suite("smart_append", tests);

  return munit_suite_main(&suite, NULL, 0, NULL);
}
