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

#undef munit_assert_string_equal
#define munit_assert_string_equal(a, b, msg)                                  \
  do                                                                          \
  {                                                                           \
    if (MUNIT_UNLIKELY(strcmp((a), (b)) != 0))                                \
    {                                                                         \
      munit_errorf("Assertion failed: %s (\"%s\" != \"%s\")", msg, (a), (b)); \
    }                                                                         \
  } while (0)

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

#define munit_test(name, func) \
  {(char *)name, func, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}

#define munit_null_test \
  {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}

#define munit_suite(name, tests) \
  {(char *)name, tests, NULL, 1, MUNIT_SUITE_OPTION_NONE}

munit_case(RUN, test_concat_empty_strings, {
  char str1[100] = "";
  const char *str2 = "";
  concat_strings(str1, str2);
  munit_assert_string_equal(
      str1, "",
      "Concatenating two empty strings should result in an empty string");
});

munit_case(RUN, test_concat_empty_to_nonempty, {
  char str1[100] = "Hello";
  const char *str2 = "";
  concat_strings(str1, str2);
  munit_assert_string_equal(str1, "Hello",
                            "Concatenating an empty string to a non-empty "
                            "string should not change the original string");
});

munit_case(RUN, test_concat_small_strings, {
  char str1[100] = "Hello ";
  const char *str2 = "World";
  concat_strings(str1, str2);
  munit_assert_string_equal(str1, "Hello World",
                            "Concatenating strings should work correctly");
});

munit_case(SUBMIT, test_concat_long_strings, {
  char str1[200] = "This is a longer string that ";
  const char *str2 = "will be concatenated with another long string.";
  concat_strings(str1, str2);
  munit_assert_string_equal(
      str1,
      "This is a longer string that will be concatenated with another long "
      "string.",
      "Concatenating longer strings should work correctly");
});

munit_case(SUBMIT, test_concat_nonempty_to_empty, {
  char str1[100] = "";
  const char *str2 = "Hello";
  concat_strings(str1, str2);
  munit_assert_string_equal(
      str1, "Hello",
      "Concatenating a string to an empty should change the original string");
});

munit_case(RUN, test_concat_null_terminator_explicit, {
  char str1[10];
  memset(str1, 'x', sizeof(str1));
  str1[0] = 'A';
  str1[1] = 'B';
  str1[2] = '\0';

  const char *str2 = "CD";
  concat_strings(str1, str2);

  munit_assert_string_equal(str1, "ABCD", "Content should match");
  munit_assert_int(str1[4], ==, '\0',
                   "Must explicitly write null terminator at the end");
});

int main()
{
  MunitTest tests[] = {
      munit_test("/test_concat_small_strings", test_concat_small_strings),
      munit_test("/test_concat_empty_strings", test_concat_empty_strings),
      munit_test("/test_concat_empty_to_nonempty",
                 test_concat_empty_to_nonempty),
      munit_test("/test_concat_long_strings", test_concat_long_strings),
      munit_test("/test_concat_nonempty_to_empty",
                 test_concat_nonempty_to_empty),
      munit_test("/test_concat_null_terminator_explicit",
                 test_concat_null_terminator_explicit),
      munit_null_test,
  };

  MunitSuite suite = munit_suite("concat_strings", tests);

  return munit_suite_main(&suite, NULL, 0, NULL);
}
