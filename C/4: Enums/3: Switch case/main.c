#include "http.h"
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

#undef assert_string_equal
#define assert_string_equal(a, b, msg) \
  do { \
    if (MUNIT_UNLIKELY(strcmp((a), (b)) != 0)) { \
      munit_errorf("Assertion failed: %s (\"%s\" != \"%s\")", msg, (a), (b)); \
    } \
  } while (0)

#define munit_test(name, func) \
  { (char*) name, func, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }

#define munit_null_test \
   { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }

#define munit_suite(name, tests) \
   { (char*) name, tests, NULL, 1, MUNIT_SUITE_OPTION_NONE }

munit_case(RUN, test_switch_enum, {
    assert_string_equal(http_to_str(HTTP_BAD_REQUEST), "400 Bad Request", "");
    assert_string_equal(http_to_str(HTTP_UNAUTHORIZED), "401 Unauthorized", "");
    assert_string_equal(http_to_str(HTTP_NOT_FOUND), "404 Not Found", "");
    assert_string_equal(http_to_str(HTTP_TEAPOT), "418 I AM A TEAPOT!", "");
    assert_string_equal(http_to_str(HTTP_INTERNAL_SERVER_ERROR),
                        "500 Internal Server Error", "");
});

munit_case(SUBMIT, test_switch_enum_default, {
    assert_string_equal(http_to_str((http_error_code_t)999),
                        "Unknown HTTP status code", "");
});

int main()
{
    MunitTest tests[] = {
        munit_test("/switch_enum", test_switch_enum),
        munit_test("/switch_enum_default", test_switch_enum_default),
        munit_null_test,
    };

    MunitSuite suite = munit_suite("http", tests);

    return munit_suite_main(&suite, NULL, 0, NULL);
}
