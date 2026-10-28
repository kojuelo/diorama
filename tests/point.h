#pragma once

#include "util.h"

#include <unity.h>
#include <diorama/point.h>

#include <math.h>

void test_point_equals()
{
    point_t p1 = {1.5f, -2.37f};
    point_t p2 = {-0.1f, 2.56f};

    point_t p3 = {1.5f, -2.37f};
    point_t p4 = {-0.1f, 2.56f};

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
    point_t p4 = {-0.1f, 2.56f};

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

void test_point_translate()
{
    point_t p1 = {1.0f, 2.0f};

    point_translate(&p1, -3.0f, 4.0f);
    TEST_ASSERT_EQUAL_POINT(-2.0f, 6.0f, p1);

    point_t p2 = {-3.0f, 4.0f};
    point_translate(&p2, 2.0f, 1.0f);
    TEST_ASSERT_EQUAL_POINT(-1.0f, 5.0f, p2);
}

void test_point_rotate_radians()
{
    point_t p = {1.0f, 2.0f};

    point_rotate_radians(&p, M_PI_2);
    TEST_ASSERT_EQUAL_POINT(-2.0f, 1.0f, p);

    point_rotate_radians(&p, M_PI);
    TEST_ASSERT_EQUAL_POINT(2.0f, -1.0f, p);

    point_rotate_radians(&p, M_PI * -1.5f);
    TEST_ASSERT_EQUAL_POINT(1.0f, 2.0f, p);
}

void test_point_rotate_radians_pivot()
{
    point_t p = {1.0f, 2.0f};
    point_t pivot = {-1.0f, -2.0f};

    point_rotate_radians_at_pivot(&p, &pivot, M_PI_2);
    TEST_ASSERT_EQUAL_POINT(-5.0f, 0.0f, p);
    TEST_ASSERT_EQUAL_POINT(-1.0f, -2.0f, pivot);

    point_rotate_radians_at_pivot(&p, &pivot, -M_PI);
    TEST_ASSERT_EQUAL_POINT(3.0f, -4.0f, p);
    TEST_ASSERT_EQUAL_POINT(-1.0f, -2.0f, pivot);
}

void test_point_rotate_degrees()
{
    point_t p = {1.0f, 2.0f};

    point_rotate_degrees(&p, 90.0f);
    TEST_ASSERT_EQUAL_POINT(-2.0f, 1.0f, p);

    point_rotate_degrees(&p, 180.0f);
    TEST_ASSERT_EQUAL_POINT(2.0f, -1.0f, p);

    point_rotate_degrees(&p, -270.0f);
    TEST_ASSERT_EQUAL_POINT(1.0f, 2.0f, p);
}

void test_point_rotate_degrees_pivot()
{
    point_t p = {1.0f, 2.0f};
    point_t pivot = {-1.0f, -2.0f};

    point_rotate_degrees_at_pivot(&p, &pivot, 90.0f);
    TEST_ASSERT_EQUAL_POINT(-5.0f, 0.0f, p);
    TEST_ASSERT_EQUAL_POINT(-1.0f, -2.0f, pivot);

    point_rotate_degrees_at_pivot(&p, &pivot, -180.0f);
    TEST_ASSERT_EQUAL_POINT(3.0f, -4.0f, p);
    TEST_ASSERT_EQUAL_POINT(-1.0f, -2.0f, pivot);
}

void test_point_scale()
{
    point_t p = {1.0f, 2.0f};

    point_scale(&p, 0.5f, 0.5f);
    TEST_ASSERT_EQUAL_POINT(0.5f, 1.0f, p);

    point_scale(&p, 0.5f, 0.1f);
    TEST_ASSERT_EQUAL_POINT(0.25f, 0.1f, p);
}

void run_tests_point()
{
    RUN_TEST(test_point_equals);
    RUN_TEST(test_point_equals_approx);
    RUN_TEST(test_point_translate);
    RUN_TEST(test_point_rotate_radians);
    RUN_TEST(test_point_rotate_radians_pivot);
    RUN_TEST(test_point_rotate_degrees);
    RUN_TEST(test_point_rotate_degrees_pivot);
    RUN_TEST(test_point_scale);
}