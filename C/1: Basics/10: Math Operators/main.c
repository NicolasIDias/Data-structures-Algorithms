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

#undef munit_assert_double_equal
#define munit_assert_double_equal(a, b, msg) \
  do { \
    double munit_tmp_a_ = (double)(a); \
    double munit_tmp_b_ = (double)(b); \
    double munit_tmp_diff_ = munit_tmp_a_ - munit_tmp_b_; \
    if (munit_tmp_diff_ < 0) munit_tmp_diff_ = -munit_tmp_diff_; \
    if (munit_tmp_diff_ > 0.00001) { \
       munit_errorf("Assertion failed: %s (expected %g, got %g)", msg, munit_tmp_b_, munit_tmp_a_); \
    } \
  } while (0)

#define munit_test(name, func) \
  { (char*) name, func, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }

#define munit_null_test \
   { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }

#define munit_suite(name, tests) \
   { (char*) name, tests, NULL, 1, MUNIT_SUITE_OPTION_NONE }

munit_case(RUN, test_snek_score_1, {
  float result = snek_score(3, 4, 5, 0.1);
  munit_assert_double_equal(result, 1.9, "result must be 1.9");
});

munit_case(RUN, test_snek_score_2, {
  float result = snek_score(10, 10, 10, 0.1);
  munit_assert_double_equal(result, 11.0, "result must be 11.0");
});

munit_case(SUBMIT, test_snek_score_3, {
  float result = snek_score(105, 205, 207, 0.1);
  munit_assert_double_equal(result, 2194, "result must be 2194.0");
});

int main() {
  MunitTest tests[] = {
      munit_test("/test_snek_score_1", test_snek_score_1),
      munit_test("/test_snek_score_2", test_snek_score_2),
      munit_test("/test_snek_score_3", test_snek_score_3),
      munit_null_test,
  };

  MunitSuite suite = munit_suite("snek_score", tests);

  return munit_suite_main(&suite, NULL, 0, NULL);
}
