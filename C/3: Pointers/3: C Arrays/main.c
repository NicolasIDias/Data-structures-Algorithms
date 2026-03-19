#include "exercise.h"
#include "munit.h"

#define RUN
#define SUBMIT

#define munit_case(case_name, test_name, block) \
  static MunitResult test_name(const MunitParameter params[], void* user_data_or_fixture) { \
    (void) params; \
    (void) user_data_or_fixture; \
    block \
    return MUNIT_OK; \
  }

#undef munit_assert_int
#define munit_assert_int(a, op, b, msg) \
  do { \
    int munit_tmp_a_ = (a); \
    int munit_tmp_b_ = (b); \
    if (MUNIT_UNLIKELY(!(munit_tmp_a_ op munit_tmp_b_))) { \
      munit_errorf("Assertion failed: %s (%d %s %d)", msg, munit_tmp_a_, #op, munit_tmp_b_); \
    } \
  } while (0)

#define munit_test(name, func) \
  { (char*) name, func, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }

#define munit_null_test \
   { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }

#define munit_suite(name, tests) \
   { (char*) name, tests, NULL, 1, MUNIT_SUITE_OPTION_NONE }

munit_case(RUN, test_update_file_basic, {
  int filedata[200] = {0};
  update_file(filedata, 1, 100);
  munit_assert_int(filedata[1], ==, 100,
                   "Number of lines should be updated to 100");
  munit_assert_int(filedata[2], ==, 1, "File type should be updated to 1");
  munit_assert_int(filedata[199], ==, 0, "Last element should be set to 0");
});

munit_case(SUBMIT, test_update_file_different_values, {
  int filedata[200] = {0};
  for (int i = 0; i < 200; i++) {
    filedata[i] = 69;
  }
  update_file(filedata, 3, 250);
  munit_assert_int(filedata[1], ==, 250,
                   "Number of lines should be updated to 250");
  munit_assert_int(filedata[2], ==, 3, "File type should be updated to 3");
  munit_assert_int(filedata[199], ==, 0, "Last element should be set to 0");
});

int main() {
  MunitTest tests[] = {
      munit_test("/test_update_file_basic", test_update_file_basic),
      munit_test("/test_update_file_different_values",
                 test_update_file_different_values),
      munit_null_test,
  };

  MunitSuite suite = munit_suite("update_file", tests);

  return munit_suite_main(&suite, NULL, 0, NULL);
}
