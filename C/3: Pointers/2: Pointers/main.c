#include "coordinate.h"
#include "../../munit/munit.h"

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

coordinate_t new_coordinate(int x, int y, int z) {
  return (coordinate_t){.x = x, .y = y, .z = z};
}

munit_case(RUN, test_unchanged, {
  coordinate_t old = new_coordinate(1, 2, 3);
  munit_assert_int(old.x, ==, 1, "old.x must be 1");

  coordinate_update_x(old, 4);
  munit_assert_int(old.x, ==, 1, "old.x must still be 1");
});

munit_case(SUBMIT, test_changed, {
  coordinate_t old = new_coordinate(1, 2, 3);
  munit_assert_int(old.x, ==, 1, ".x must be 1");

  coordinate_t updated = coordinate_update_and_return_x(old, 4);
  munit_assert_int(updated.x, ==, 4, "updated .x must be 4");
  munit_assert_int(old.x, ==, 1, "old.x must still be 1");

  // Notice, they have different addresses
  munit_assert_ptr_not_equal(&old, &updated);
});

int main() {
  MunitTest tests[] = {
      munit_test("/test_unchanged", test_unchanged),
      munit_test("/test_changed", test_changed),
      munit_null_test,
  };

  MunitSuite suite = munit_suite("pointers", tests);

  return munit_suite_main(&suite, NULL, 0, NULL);
}
