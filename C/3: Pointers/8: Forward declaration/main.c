#include "exercise.h"
#include "munit.h"
#include <string.h>

#define RUN
#define SUBMIT

#define munit_case(case_name, test_name, block)                                             \
    static MunitResult test_name(const MunitParameter params[], void *user_data_or_fixture) \
    {                                                                                       \
        (void)params;                                                                       \
        (void)user_data_or_fixture;                                                         \
        block return MUNIT_OK;                                                              \
    }

#undef munit_assert_int
#define munit_assert_int(a, op, b, msg)                                                            \
    do                                                                                             \
    {                                                                                              \
        int munit_tmp_a_ = (a);                                                                    \
        int munit_tmp_b_ = (b);                                                                    \
        if (MUNIT_UNLIKELY(!(munit_tmp_a_ op munit_tmp_b_)))                                       \
        {                                                                                          \
            munit_errorf("Assertion failed: %s (%d %s %d)", msg, munit_tmp_a_, #op, munit_tmp_b_); \
        }                                                                                          \
    } while (0)

#undef munit_assert_string_equal
#define munit_assert_string_equal(a, b, msg)                                        \
    do                                                                              \
    {                                                                               \
        if (MUNIT_UNLIKELY(strcmp((a), (b)) != 0))                                  \
        {                                                                           \
            munit_errorf("Assertion failed: %s (\"%s\" != \"%s\")", msg, (a), (b)); \
        }                                                                           \
    } while (0)

#undef munit_assert_null
#define munit_assert_null(ptr, msg)                                          \
    do                                                                       \
    {                                                                        \
        if (MUNIT_UNLIKELY((ptr) != NULL))                                   \
        {                                                                    \
            munit_errorf("Assertion failed: %s (pointer is not NULL)", msg); \
        }                                                                    \
    } while (0)

#undef munit_assert_not_null
#define munit_assert_not_null(ptr, msg)                                  \
    do                                                                   \
    {                                                                    \
        if (MUNIT_UNLIKELY((ptr) == NULL))                               \
        {                                                                \
            munit_errorf("Assertion failed: %s (pointer is NULL)", msg); \
        }                                                                \
    } while (0)

#define munit_test(name, func) \
    {(char *)name, func, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}

#define munit_null_test \
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}

#define munit_suite(name, tests) \
    {(char *)name, tests, NULL, 1, MUNIT_SUITE_OPTION_NONE}

munit_case(RUN, test_new_node_simple, {
    snekobject_t node = new_node("root");
    munit_assert_string_equal(node.name, "root", "Node name should be 'root'");
    munit_assert_null(node.child, "Child should be NULL for a new node");
});

munit_case(RUN, test_new_node_empty_name, {
    snekobject_t node = new_node("");
    munit_assert_string_equal(node.name, "",
                              "Node name should be an empty string");
    munit_assert_null(node.child, "Child should be NULL for a new node");
});

munit_case(SUBMIT, test_new_node_with_child, {
    snekobject_t child = new_node("child");
    snekobject_t parent = new_node("parent");
    parent.child = &child;

    munit_assert_string_equal(parent.name, "parent",
                              "Parent node name should be 'parent'");
    munit_assert_not_null(parent.child, "Parent's child should not be NULL");
    munit_assert_string_equal(parent.child->name, "child",
                              "Child node name should be 'child'");
    munit_assert_null(parent.child->child, "Child's child should be NULL");
});

munit_case(SUBMIT, test_new_node_nested_children, {
    snekobject_t grandchild = new_node("grandchild");
    snekobject_t child = new_node("child");
    snekobject_t parent = new_node("parent");

    child.child = &grandchild;
    parent.child = &child;

    munit_assert_string_equal(parent.name, "parent",
                              "Parent node name should be 'parent'");
    munit_assert_not_null(parent.child, "Parent's child should not be NULL");
    munit_assert_string_equal(parent.child->name, "child",
                              "Child node name should be 'child'");
    munit_assert_not_null(parent.child->child,
                          "Child's child should not be NULL");
    munit_assert_string_equal(parent.child->child->name, "grandchild",
                              "Grandchild node name should be 'grandchild'");
    munit_assert_null(parent.child->child->child,
                      "Grandchild's child should be NULL");
});

int main()
{
    MunitTest tests[] = {
        munit_test("/test_new_node_simple", test_new_node_simple),
        munit_test("/test_new_node_empty_name", test_new_node_empty_name),
        munit_test("/test_new_node_with_child", test_new_node_with_child),
        munit_test("/test_new_node_nested_children",
                   test_new_node_nested_children),
        munit_null_test,
    };

    MunitSuite suite = munit_suite("new_node", tests);

    return munit_suite_main(&suite, NULL, 0, NULL);
}
