#include <unity.h>
#include <diorama/point.h>

#include <math.h>

void test_point_equals()
{
    point_t p1 = {1.5f, -2.37f};
    point_t p2 = {-0.1f, 2.56f};

    point_t p3 = {1.5f, -2.37f};
    point_t p4 ={-0.1f, 2.56f};

    TEST_ASSERT_TRUE(point_equals(&p1, &p3));
    TEST_ASSERT_TRUE(point_equals(&p2, &p4));
    TEST_ASSERT_FALSE(point_equals(&p1, &p2));

    p3.x = nextafterf(p3.x, INFINITY);
    p3.y = nextafterf(p3.y, INFINITY);

    p4.x = nextafterf(p4.x, -INFINITY);
    p4.y = nextafterf(p4.y, -INFINITY);

    TEST_ASSERT_FALSE(point_equals(&p1, &p3));
    TEST_ASSERT_FALSE(point_equals(&p2, &p4));
}

void test_point_equals_approx()
{
    point_t p1 = {1.5f, -2.37f};
    point_t p2 = {-0.1f, 2.56f};

    point_t p3 = {1.5f, -2.37f};
    point_t p4 ={-0.1f, 2.56f};

    TEST_ASSERT_TRUE(point_equals_approx(&p1, &p3));
    TEST_ASSERT_TRUE(point_equals_approx(&p2, &p4));
    TEST_ASSERT_FALSE(point_equals_approx(&p1, &p2));

    p3.x = nextafterf(p3.x, INFINITY);
    p3.y = nextafterf(p3.y, INFINITY);

    p4.x = nextafterf(p4.x, -INFINITY);
    p4.y = nextafterf(p4.y, -INFINITY);

    TEST_ASSERT_TRUE(point_equals_approx(&p1, &p3));
    TEST_ASSERT_TRUE(point_equals_approx(&p2, &p4));
}

void run_tests_point()
{
    RUN_TEST(test_point_equals);
    RUN_TEST(test_point_equals_approx);
}