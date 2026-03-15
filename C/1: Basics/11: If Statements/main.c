#include "exercise.h"
#include "munit.h" //  tem que instalar ai 
// git clone https://github.com/nemequ/munit.git
// COmpilar usando: gcc main.c exercise.c ../../munit/munit.c -o main -I../../munit && ./main

#define RUN
#define SUBMIT

#define munit_case(case_name, test_name, block) \
  static MunitResult test_name(const MunitParameter params[], void* user_data_or_fixture) { \
    (void) params; \
    (void) user_data_or_fixture; \
    block \
    return MUNIT_OK; \
  }

#undef munit_assert_string_equal
#define munit_assert_string_equal(a, b, msg) \
  do { \
    const char* munit_tmp_a_ = (a); \
    const char* munit_tmp_b_ = (b); \
    if (MUNIT_UNLIKELY(strcmp(munit_tmp_a_, munit_tmp_b_) != 0)) { \
      munit_errorf("Assertion failed: %s (expected \"%s\", got \"%s\")", msg, munit_tmp_b_, munit_tmp_a_); \
    } \
  } while (0)

#define munit_test(name, func) \
  { (char*) name, func, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }

#define munit_null_test \
   { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }

#define munit_suite(name, tests) \
   { (char*) name, tests, NULL, 1, MUNIT_SUITE_OPTION_NONE }




munit_case(RUN, test_cold, {
  char *result = get_temperature_status(50);
  munit_assert_string_equal(result, "too cold", "50 should be too cold");
});

munit_case(RUN, test_hot, {
  char *result = get_temperature_status(100);
  munit_assert_string_equal(result, "too hot", "100 should be too hot");
});

munit_case(SUBMIT, test_just_right, {
  char *result = get_temperature_status(70);
  munit_assert_string_equal(result, "just right", "70 should be just right");
});

munit_case(SUBMIT, test_just_right2, {
  char *result = get_temperature_status(75);
  munit_assert_string_equal(result, "just right", "75 should be just right");
});

int main() {
  MunitTest tests[] = {
      munit_test("/test_cold", test_cold),
      munit_test("/test_hot", test_hot),
      munit_test("/test_just_right", test_just_right),
      munit_test("/test_just_right2", test_just_right2),
      munit_null_test,
  };

  MunitSuite suite = munit_suite("get_temperature_status", tests);

  return munit_suite_main(&suite, NULL, 0, NULL);
}
