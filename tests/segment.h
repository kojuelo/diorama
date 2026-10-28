#pragma once

#include "util.h"

#include <unity.h>
#include <diorama/segment.h>

void test_segment_equals()
{
    segment_t s1 = {1.0f, 2.0f, 3.0f, 4.0f};
    segment_t s2 = {0.0f, 0.0f, -2.0f, -5.0f};

    segment_t s3 = {1.0f, 2.0f, 3.0f, 4.0f};
    segment_t s4 = {0.0f, 0.0f, -2.0f, -5.0f};

    TEST_ASSERT_TRUE(segment_equals(&s1, &s3));
    TEST_ASSERT_TRUE(segment_equals(&s2, &s4));
    TEST_ASSERT_FALSE(segment_equals(&s1, &s2));

    s3.a.x = nextafterf(s3.a.x, INFINITY);
    s3.a.y = nextafterf(s3.a.y, INFINITY);

    s4.b.x = nextafterf(s4.b.x, -INFINITY);
    s4.b.y = nextafterf(s4.b.y, -INFINITY);

    TEST_ASSERT_FALSE(segment_equals(&s1, &s3));
    TEST_ASSERT_FALSE(segment_equals(&s2, &s4));
}

void test_segment_equals_approx()
{
    segment_t s1 = {1.0f, 2.0f, 3.0f, 4.0f};
    segment_t s2 = {0.0f, 0.0f, -2.0f, -5.0f};

    segment_t s3 = {1.0f, 2.0f, 3.0f, 4.0f};
    segment_t s4 = {0.0f, 0.0f, -2.0f, -5.0f};

    TEST_ASSERT_TRUE(segment_equals_approx(&s1, &s3));
    TEST_ASSERT_TRUE(segment_equals_approx(&s2, &s4));
    TEST_ASSERT_FALSE(segment_equals_approx(&s1, &s2));

    s3.a.x = nextafterf(s3.a.x, INFINITY);
    s3.a.y = nextafterf(s3.a.y, INFINITY);

    s4.b.x = nextafterf(s4.b.x, -INFINITY);
    s4.b.y = nextafterf(s4.b.y, -INFINITY);

    TEST_ASSERT_TRUE(segment_equals_approx(&s1, &s3));
    TEST_ASSERT_TRUE(segment_equals_approx(&s2, &s4));
}

void test_segment_translate()
{
    segment_t s1 = {1.0f, 2.0f, 3.0f, 4.0f};

    segment_translate(&s1, -2.0f, 5.0f);
    TEST_ASSERT_EQUAL_SEGMENT(-1.0f, 7.0f, 1.0f, 9.0f, s1);

    segment_t s2 = {0.0f, 0.0f, -2.0f, -5.0f};
    segment_translate(&s2, 2.0f, -5.0f);
    TEST_ASSERT_EQUAL_SEGMENT(2.0f, -5.0f, 0.0f, -10.0f, s2);
}

void test_segment_rotate_radians()
{
    segment_t s = {1.0f, 2.0f, -2.0f, -1.0f};

    segment_rotate_radians(&s, M_PI_2);
    TEST_ASSERT_EQUAL_SEGMENT(-2.0f, 1.0f, 1.0f, -2.0f, s);

    segment_rotate_radians(&s, M_PI);
    TEST_ASSERT_EQUAL_SEGMENT(2.0f, -1.0f, -1.0f, 2.0f, s);

    segment_rotate_radians(&s, M_PI * -1.5f);
    TEST_ASSERT_EQUAL_SEGMENT(1.0f, 2.0f, -2.0f, -1.0f, s);
}

void test_segment_rotate_radians_pivot()
{
    segment_t s = {1.0f, 2.0f, -2.0f, -1.0f};
    point_t pivot = {1.0f, 2.0f};

    segment_rotate_radians_at_pivot(&s, &pivot, M_PI_2);
    TEST_ASSERT_EQUAL_SEGMENT(1.0f, 2.0f, 4.0f, -1.0f, s);
    TEST_ASSERT_EQUAL_POINT(1.0f, 2.0f, pivot);

    pivot = (point_t){4.0f, -1.0f};
    segment_rotate_radians_at_pivot(&s, &pivot, M_PI);
    TEST_ASSERT_EQUAL_SEGMENT(7.0f, -4.0f, 4.0f, -1.0f, s);

    segment_rotate_radians_at_pivot(&s, &pivot, -M_PI);
    TEST_ASSERT_EQUAL_SEGMENT(1.0f, 2.0f, 4.0f, -1.0f, s);
}

void test_segment_rotate_degrees()
{
    segment_t s = {1.0f, 2.0f, -2.0f, -1.0f};

    segment_rotate_degrees(&s, 90.0f);
    TEST_ASSERT_EQUAL_SEGMENT(-2.0f, 1.0f, 1.0f, -2.0f, s);

    segment_rotate_degrees(&s, 180.0f);
    TEST_ASSERT_EQUAL_SEGMENT(2.0f, -1.0f, -1.0f, 2.0f, s);

    segment_rotate_degrees(&s, -270.0f);
    TEST_ASSERT_EQUAL_SEGMENT(1.0f, 2.0f, -2.0f, -1.0f, s);
}

void test_segment_rotate_degrees_pivot()
{
    segment_t s = {1.0f, 2.0f, -2.0f, -1.0f};
    point_t pivot = {1.0f, 2.0f};

    segment_rotate_degrees_at_pivot(&s, &pivot, 90.0f);
    TEST_ASSERT_EQUAL_SEGMENT(1.0f, 2.0f, 4.0f, -1.0f, s);
    TEST_ASSERT_EQUAL_POINT(1.0f, 2.0f, pivot);

    pivot = (point_t){4.0f, -1.0f};
    segment_rotate_degrees_at_pivot(&s, &pivot, 180.0f);
    TEST_ASSERT_EQUAL_SEGMENT(7.0f, -4.0f, 4.0f, -1.0f, s);

    segment_rotate_degrees_at_pivot(&s, &pivot, -180.0f);
    TEST_ASSERT_EQUAL_SEGMENT(1.0f, 2.0f, 4.0f, -1.0f, s);
}

void test_segment_scale()
{
    segment_t s = {1.0f, 2.0f, -3.0f, -4.0f};

    segment_scale(&s, 0.5f, 0.5f);
    TEST_ASSERT_EQUAL_SEGMENT(0.5f, 1.0f, -1.5f, -2.0f, s);

    segment_scale(&s, 0.5f, 0.1f);
    TEST_ASSERT_EQUAL_SEGMENT(0.25f, 0.1f, -0.75f, -0.2f, s);
}

void run_tests_segment()
{
    RUN_TEST(test_segment_equals);
    RUN_TEST(test_segment_equals_approx);
    RUN_TEST(test_segment_translate);
    RUN_TEST(test_segment_rotate_radians);
    RUN_TEST(test_segment_rotate_radians_pivot);
    RUN_TEST(test_segment_rotate_degrees);
    RUN_TEST(test_segment_rotate_degrees_pivot);
    RUN_TEST(test_segment_scale);
}