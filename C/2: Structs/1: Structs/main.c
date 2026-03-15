#include "coord.h"
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

#undef assert_int
#define assert_int(a, op, b, msg) \
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

munit_case(RUN, test_new_coordinate1, {
  struct Coordinate c;
  c.x = 1;
  c.y = 2;
  c.z = 3;

  assert_int(c.x, ==, 1, "should set x");
  assert_int(c.y, ==, 2, "should set y");
  assert_int(c.z, ==, 3, "should set z");
});

munit_case(RUN, test_new_coordinate2, {
  struct Coordinate c;
  c.x = 4;
  c.y = 2;
  c.z = 0;

  assert_int(c.x, ==, 4, "should set x");
  assert_int(c.y, ==, 2, "should set y");
  assert_int(c.z, ==, 0, "should set z");
});

munit_case(SUBMIT, test_new_coordinate3, {
  struct Coordinate c;
  c.x = 10;
  c.y = 20;
  c.z = 30;

  assert_int(c.x, ==, 10, "should set x");
  assert_int(c.y, ==, 20, "should set y");
  assert_int(c.z, ==, 30, "should set z");
});

munit_case(SUBMIT, test_new_coordinate4, {
  struct Coordinate c;
  c.x = 0;
  c.y = 6;
  c.z = 9;

  assert_int(c.x, ==, 0, "should set x");
  assert_int(c.y, ==, 6, "should set y");
  assert_int(c.z, ==, 9, "should set z");
});

int main() {
  MunitTest tests[] = {
      munit_test("/create_coordinate1", test_new_coordinate1),
      munit_test("/create_coordinate2", test_new_coordinate2),
      munit_test("/create_coordinate3", test_new_coordinate3),
      munit_test("/create_coordinate4", test_new_coordinate4),
      munit_null_test,
  };

  MunitSuite suite = munit_suite("coordinates", tests);

  return munit_suite_main(&suite, NULL, 0, NULL);
}
