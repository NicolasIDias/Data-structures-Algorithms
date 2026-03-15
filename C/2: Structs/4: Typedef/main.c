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

munit_case(RUN, test_new_coordinate, {
  coordinate_t c = new_coord(1, 2, 3);

  assert_int(c.x, ==, 1, "should set x");
  assert_int(c.y, ==, 2, "should set y");
  assert_int(c.z, ==, 3, "should set z");
});

munit_case(RUN, test_scale_coordinate, {
  coordinate_t c = new_coord(1, 2, 3);
  coordinate_t scaled = scale_coordinate(c, 2);

  assert_int(scaled.x, ==, 2, "should scale x");
  assert_int(scaled.y, ==, 4, "should scale y");
  assert_int(scaled.z, ==, 6, "should scale z");
});

int main() {
  MunitTest tests[] = {
      munit_test("/create_coordinate", test_new_coordinate),
      munit_test("/test_scale_coordinate", test_scale_coordinate),
      munit_null_test,
  };

  MunitSuite suite = munit_suite("coordinates", tests);

  return munit_suite_main(&suite, NULL, 0, NULL);
}
