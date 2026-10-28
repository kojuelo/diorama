#pragma once

#include "util.h"

#include <unity.h>
#include <diorama/capsule.h>

void test_capsule_equals()
{
    capsule_t c1 = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    capsule_t c2 = {0.0f, 0.0f, -2.0f, -5.0f, 7.0f};

    capsule_t c3 = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    capsule_t c4 = {0.0f, 0.0f, -2.0f, -5.0f, 7.0f};

    TEST_ASSERT_TRUE(capsule_equals(&c1, &c3));
    TEST_ASSERT_TRUE(capsule_equals(&c2, &c4));
    TEST_ASSERT_FALSE(capsule_equals(&c1, &c2));

    c3.segment.a.x = nextafterf(c3.segment.a.x, INFINITY);
    c3.segment.a.y = nextafterf(c3.segment.a.y, INFINITY);
    c3.radius = nextafterf(c3.radius, -INFINITY);

    c4.segment.b.x = nextafterf(c4.segment.b.x, -INFINITY);
    c4.segment.b.y = nextafterf(c4.segment.b.y, -INFINITY);
    c4.radius = nextafterf(c4.radius, INFINITY);

    TEST_ASSERT_FALSE(capsule_equals(&c1, &c3));
    TEST_ASSERT_FALSE(capsule_equals(&c2, &c4));
}

void test_capsule_equals_approx()
{
    capsule_t c1 = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    capsule_t c2 = {0.0f, 0.0f, -2.0f, -5.0f, 7.0f};

    capsule_t c3 = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    capsule_t c4 = {0.0f, 0.0f, -2.0f, -5.0f, 7.0f};

    TEST_ASSERT_TRUE(capsule_equals_approx(&c1, &c3));
    TEST_ASSERT_TRUE(capsule_equals_approx(&c2, &c4));
    TEST_ASSERT_FALSE(capsule_equals_approx(&c1, &c2));

    c3.segment.a.x = nextafterf(c3.segment.a.x, INFINITY);
    c3.segment.a.y = nextafterf(c3.segment.a.y, INFINITY);
    c3.radius = nextafterf(c3.radius, -INFINITY);

    c4.segment.b.x = nextafterf(c4.segment.b.x, -INFINITY);
    c4.segment.b.y = nextafterf(c4.segment.b.y, -INFINITY);
    c4.radius = nextafterf(c4.radius, INFINITY);

    TEST_ASSERT_TRUE(capsule_equals_approx(&c1, &c3));
    TEST_ASSERT_TRUE(capsule_equals_approx(&c2, &c4));
}

void test_capsule_translate()
{
    capsule_t c1 = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};

    capsule_translate(&c1, -2.0f, 5.0f);
    TEST_ASSERT_EQUAL_CAPSULE(-1.0f, 7.0f, 1.0f, 9.0f, 5.0f, c1);

    capsule_t c2 = {0.0f, 0.0f, -2.0f, -5.0f, 7.0f};
    capsule_translate(&c2, 2.0f, -5.0f);
    TEST_ASSERT_EQUAL_CAPSULE(2.0f, -5.0f, 0.0f, -10.0f, 7.0f, c2);
}

void test_capsule_rotate_radians()
{
    capsule_t c = {1.0f, 2.0f, -2.0f, -1.0f, 7.0f};

    capsule_rotate_radians(&c, M_PI_2);
    TEST_ASSERT_EQUAL_CAPSULE(-2.0f, 1.0f, 1.0f, -2.0f, 7.0f, c);

    capsule_rotate_radians(&c, M_PI);
    TEST_ASSERT_EQUAL_CAPSULE(2.0f, -1.0f, -1.0f, 2.0f, 7.0f, c);

    capsule_rotate_radians(&c, M_PI * -1.5f);
    TEST_ASSERT_EQUAL_CAPSULE(1.0f, 2.0f, -2.0f, -1.0f, 7.0f, c);
}

void test_capsule_rotate_radians_pivot()
{
    capsule_t c = {1.0f, 2.0f, -2.0f, -1.0f, 7.0f};
    point_t pivot = {1.0f, 2.0f};

    capsule_rotate_radians_at_pivot(&c, &pivot, M_PI_2);
    TEST_ASSERT_EQUAL_CAPSULE(1.0f, 2.0f, 4.0f, -1.0f, 7.0f, c);
    TEST_ASSERT_EQUAL_POINT(1.0f, 2.0f, pivot);

    pivot = (point_t){4.0f, -1.0f};
    capsule_rotate_radians_at_pivot(&c, &pivot, M_PI);
    TEST_ASSERT_EQUAL_CAPSULE(7.0f, -4.0f, 4.0f, -1.0f, 7.0f, c);

    capsule_rotate_radians_at_pivot(&c, &pivot, -M_PI);
    TEST_ASSERT_EQUAL_CAPSULE(1.0f, 2.0f, 4.0f, -1.0f, 7.0f, c);
}

void test_capsule_rotate_degrees()
{
    capsule_t c = {1.0f, 2.0f, -2.0f, -1.0f, 7.0f};

    capsule_rotate_degrees(&c, 90.0f);
    TEST_ASSERT_EQUAL_CAPSULE(-2.0f, 1.0f, 1.0f, -2.0f, 7.0f, c);

    capsule_rotate_degrees(&c, 180.0f);
    TEST_ASSERT_EQUAL_CAPSULE(2.0f, -1.0f, -1.0f, 2.0f, 7.0f, c);

    capsule_rotate_degrees(&c, -270.0f);
    TEST_ASSERT_EQUAL_CAPSULE(1.0f, 2.0f, -2.0f, -1.0f, 7.0f, c);
}

void test_capsule_rotate_degrees_pivot()
{
    capsule_t c = {1.0f, 2.0f, -2.0f, -1.0f, 7.0f};
    point_t pivot = {1.0f, 2.0f};

    capsule_rotate_degrees_at_pivot(&c, &pivot, 90.0f);
    TEST_ASSERT_EQUAL_CAPSULE(1.0f, 2.0f, 4.0f, -1.0f, 7.0f, c);
    TEST_ASSERT_EQUAL_POINT(1.0f, 2.0f, pivot);

    pivot = (point_t){4.0f, -1.0f};
    capsule_rotate_degrees_at_pivot(&c, &pivot, 180.0f);
    TEST_ASSERT_EQUAL_CAPSULE(7.0f, -4.0f, 4.0f, -1.0f, 7.0f, c);

    capsule_rotate_degrees_at_pivot(&c, &pivot, -180.0f);
    TEST_ASSERT_EQUAL_CAPSULE(1.0f, 2.0f, 4.0f, -1.0f, 7.0f, c);
}

void test_capsule_scale()
{
    capsule_t c = {1.0f, 2.0f, -3.0f, -4.0f, 7.0f};

    capsule_scale(&c, 0.5f, 0.5f, 0.5f);
    TEST_ASSERT_EQUAL_CAPSULE(0.5f, 1.0f, -1.5f, -2.0f, 3.5f, c);

    capsule_scale(&c, 0.5f, 0.1f, 0.3f);
    TEST_ASSERT_EQUAL_CAPSULE(0.25f, 0.1f, -0.75f, -0.2f, 1.05f, c);
}

void run_tests_capsule()
{
    RUN_TEST(test_capsule_equals);
    RUN_TEST(test_capsule_equals_approx);
    RUN_TEST(test_capsule_translate);
    RUN_TEST(test_capsule_rotate_radians);
    RUN_TEST(test_capsule_rotate_radians_pivot);
    RUN_TEST(test_capsule_rotate_degrees);
    RUN_TEST(test_capsule_rotate_degrees_pivot);
    RUN_TEST(test_capsule_scale);
}