#include "munit.h"
#include "snek.h"

#define RUN
#define SUBMIT

#define munit_case(case_name, test_name, block) \
  static MunitResult test_name(const MunitParameter params[], void* user_data_or_fixture) { \
    (void) params; \
    (void) user_data_or_fixture; \
    block \
    return MUNIT_OK; \
  }

#undef munit_assert_ulong
#define munit_assert_ulong(a, op, b, msg) \
  do { \
    unsigned long munit_tmp_a_ = (a); \
    unsigned long munit_tmp_b_ = (b); \
    if (MUNIT_UNLIKELY(!(munit_tmp_a_ op munit_tmp_b_))) { \
      munit_errorf("Assertion failed: %s (%lu %s %lu)", msg, munit_tmp_a_, #op, munit_tmp_b_); \
    } \
  } while (0)

#define munit_test(name, func) \
  { (char*) name, func, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }

#define munit_null_test \
   { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }

#define munit_suite(name, tests) \
   { (char*) name, tests, NULL, 1, MUNIT_SUITE_OPTION_NONE }

munit_case(RUN, size_of_addr_16, {
  unsigned long size = size_of_addr(16);
  munit_assert_ulong(size, ==, sizeof(void *), "size must match pointer size");
});

munit_case(RUN, size_of_addr_32, {
  unsigned long size = size_of_addr(32);
  munit_assert_ulong(size, ==, sizeof(void *), "size must match pointer size");
});

munit_case(SUBMIT, size_of_addr_64, {
  unsigned long size = size_of_addr(64);
  munit_assert_ulong(size, ==, sizeof(void *), "size must match pointer size");
});

munit_case(SUBMIT, size_of_addr_128, {
  unsigned long size = size_of_addr(128);
  munit_assert_ulong(size, ==, sizeof(void *), "size must match pointer size");
});

int main() {
  MunitTest tests[] = {
      munit_test("/size_of_addr_16", size_of_addr_16),
      munit_test("/size_of_addr_32", size_of_addr_32),
      munit_test("/size_of_addr_64", size_of_addr_64),
      munit_test("/size_of_addr_128", size_of_addr_128),

      munit_null_test,
  };

  MunitSuite suite = munit_suite("colors", tests);

  return munit_suite_main(&suite, NULL, 0, NULL);
}
