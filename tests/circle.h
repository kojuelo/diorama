#pragma once

#include "util.h"

#include <unity.h>
#include <diorama/circle.h>

#include <math.h>

void test_circle_equals()
{
    circle_t c1 = {1.0f, 2.0f, 3.0f};
    circle_t c2 = {-3.0f, -4.0f, 5.0f};

    circle_t c3 = {1.0f, 2.0f, 3.0f};
    circle_t c4 = {-3.0f, -4.0f, 5.0f};

    TEST_ASSERT_TRUE(circle_equals(&c1, &c3));
    TEST_ASSERT_TRUE(circle_equals(&c2, &c4));
    TEST_ASSERT_FALSE(circle_equals(&c1, &c2));

    c3.center.x = nextafterf(c3.center.x, INFINITY);
    c3.center.y = nextafterf(c3.center.y, INFINITY);

    c4.center.x = nextafterf(c4.center.x, -INFINITY);
    c4.center.y = nextafterf(c4.center.y, -INFINITY);

    TEST_ASSERT_FALSE(circle_equals(&c1, &c3));
    TEST_ASSERT_FALSE(circle_equals(&c2, &c4));
}

void test_circle_equals_approx()
{
    circle_t c1 = {1.0f, 2.0f, 3.0f};
    circle_t c2 = {-3.0f, -4.0f, 5.0f};

    circle_t c3 = {1.0f, 2.0f, 3.0f};
    circle_t c4 = {-3.0f, -4.0f, 5.0f};

    TEST_ASSERT_TRUE(circle_equals_approx(&c1, &c3));
    TEST_ASSERT_TRUE(circle_equals_approx(&c2, &c4));
    TEST_ASSERT_FALSE(circle_equals_approx(&c1, &c2));

    c3.center.x = nextafterf(c3.center.x, INFINITY);
    c3.center.y = nextafterf(c3.center.y, INFINITY);

    c4.center.x = nextafterf(c4.center.x, -INFINITY);
    c4.center.y = nextafterf(c4.center.y, -INFINITY);

    TEST_ASSERT_TRUE(circle_equals_approx(&c1, &c3));
    TEST_ASSERT_TRUE(circle_equals_approx(&c2, &c4));
}

void test_circle_translate()
{
    circle_t c1 = {1.0f, 2.0f, 5.0f};

    circle_translate(&c1, -3.0f, 4.0f);
    TEST_ASSERT_EQUAL_CIRCLE(-2.0f, 6.0f, 5.0f, c1);

    circle_t c2 = {-3.0f, 4.0f, 7.0f};
    circle_translate(&c2, 2.0f, 1.0f);
    TEST_ASSERT_EQUAL_CIRCLE(-1.0f, 5.0f, 7.0f, c2);
}

void test_circle_rotate_radians()
{
    circle_t c = {1.0f, 2.0f, 5.0f};

    circle_rotate_radians(&c, M_PI_2);
    TEST_ASSERT_EQUAL_CIRCLE(-2.0f, 1.0f, 5.0f, c);

    circle_rotate_radians(&c, M_PI);
    TEST_ASSERT_EQUAL_CIRCLE(2.0f, -1.0f, 5.0f, c);

    circle_rotate_radians(&c, M_PI * -1.5f);
    TEST_ASSERT_EQUAL_CIRCLE(1.0f, 2.0f, 5.0f, c);
}

void test_circle_rotate_radians_pivot()
{
    circle_t c = {1.0f, 2.0f, 5.0f};
    point_t pivot = {-1.0f, -2.0f};

    circle_rotate_radians_at_pivot(&c, &pivot, M_PI_2);
    TEST_ASSERT_EQUAL_CIRCLE(-5.0f, 0.0f, 5.0f, c);
    TEST_ASSERT_EQUAL_POINT(-1.0f, -2.0f, pivot);

    circle_rotate_radians_at_pivot(&c, &pivot, -M_PI);
    TEST_ASSERT_EQUAL_CIRCLE(3.0f, -4.0f, 5.0f, c);
    TEST_ASSERT_EQUAL_POINT(-1.0f, -2.0f, pivot);
}

void test_circle_rotate_degrees()
{
    circle_t c = {1.0f, 2.0f, 5.0f};

    circle_rotate_degrees(&c, 90.0f);
    TEST_ASSERT_EQUAL_CIRCLE(-2.0f, 1.0f, 5.0f, c);

    circle_rotate_degrees(&c, 180.0f);
    TEST_ASSERT_EQUAL_CIRCLE(2.0f, -1.0f, 5.0f, c);

    circle_rotate_degrees(&c, -270.0f);
    TEST_ASSERT_EQUAL_CIRCLE(1.0f, 2.0f, 5.0f, c);
}

void test_circle_rotate_degrees_pivot()
{
    circle_t c = {1.0f, 2.0f, 5.0f};
    point_t pivot = {-1.0f, -2.0f};

    circle_rotate_degrees_at_pivot(&c, &pivot, 90.0f);
    TEST_ASSERT_EQUAL_CIRCLE(-5.0f, 0.0f, 5.0f, c);
    TEST_ASSERT_EQUAL_POINT(-1.0f, -2.0f, pivot);

    circle_rotate_degrees_at_pivot(&c, &pivot, -180.0f);
    TEST_ASSERT_EQUAL_CIRCLE(3.0f, -4.0f, 5.0f, c);
    TEST_ASSERT_EQUAL_POINT(-1.0f, -2.0f, pivot);
}

void test_circle_scale()
{
    circle_t c = {1.0f, 2.0f, 5.0f};

    circle_scale(&c, 0.5f, 0.5f, 0.5f);
    TEST_ASSERT_EQUAL_CIRCLE(0.5f, 1.0f, 2.5f, c);

    circle_scale(&c, 0.5f, 0.1f, 0.2f);
    TEST_ASSERT_EQUAL_CIRCLE(0.25f, 0.1f, 0.5f, c);
}

void run_tests_circle()
{
    RUN_TEST(test_circle_equals);
    RUN_TEST(test_circle_equals_approx);
    RUN_TEST(test_circle_translate);
    RUN_TEST(test_circle_rotate_radians);
    RUN_TEST(test_circle_rotate_radians_pivot);
    RUN_TEST(test_circle_rotate_degrees);
    RUN_TEST(test_circle_rotate_degrees_pivot);
    RUN_TEST(test_circle_scale);
}