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

#undef munit_assert_null
#define munit_assert_null(ptr, msg)                                    \
  do                                                                   \
  {                                                                    \
    if (MUNIT_UNLIKELY((ptr) != NULL))                                 \
    {                                                                  \
      munit_errorf("Assertion failed: %s (pointer is not NULL)", msg); \
    }                                                                  \
  } while (0)

#undef munit_assert_not_null
#define munit_assert_not_null(ptr, msg)                            \
  do                                                               \
  {                                                                \
    if (MUNIT_UNLIKELY((ptr) == NULL))                             \
    {                                                              \
      munit_errorf("Assertion failed: %s (pointer is NULL)", msg); \
    }                                                              \
  } while (0)

#define munit_test(name, func) \
  {(char *)name, func, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}

#define munit_null_test \
  {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}

#define munit_suite(name, tests) \
  {(char *)name, tests, NULL, 1, MUNIT_SUITE_OPTION_NONE}

munit_case(RUN, test_assign_employee1, {
  employee_t emp = create_employee(2, "CEO Dax");
  department_t dept = create_department("C Suite");
  assign_employee(&emp, &dept);
  munit_assert_string_equal(emp.department->name, "C Suite",
                            "should match names");
});

munit_case(RUN, test_assign_manager1, {
  employee_t manager = create_employee(3, "Influencer Prime");
  department_t dept = create_department("Marketing");
  assign_manager(&dept, &manager);
  munit_assert_string_equal(dept.manager->name, "Influencer Prime",
                            "should match names");
});

munit_case(SUBMIT, test_assign_employee2, {
  employee_t emp = create_employee(4, "Vegan Intern Adam");
  department_t dept = create_department("Marketing");
  assign_employee(&emp, &dept);
  munit_assert_string_equal(emp.department->name, "Marketing",
                            "should match names");
});

munit_case(SUBMIT, test_assign_manager2, {
  employee_t manager = create_employee(5, "CDO David");
  department_t dept = create_department("C Suite");
  assign_manager(&dept, &manager);
  munit_assert_string_equal(dept.manager->name, "CDO David",
                            "should match names");
  munit_assert_int(manager.id, ==, 5, "should match ids");
});

int main()
{
  MunitTest tests[] = {
      munit_test("/test_assign_employee1", test_assign_employee1),
      munit_test("/test_assign_manager1", test_assign_manager1),
      munit_test("/test_assign_employee2", test_assign_employee2),
      munit_test("/test_assign_manager2", test_assign_manager2),
      munit_null_test,
  };

  MunitSuite suite = munit_suite("employee_department_tests", tests);

  return munit_suite_main(&suite, NULL, 0, NULL);
}
