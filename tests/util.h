#pragma once

#include <unity.h>

#define FLOAT_TEST_EPSILON 0.00001f

#define TEST_ASSERT_EQUAL_POINT(expected_x, expected_y, actual)         \
    TEST_ASSERT_FLOAT_WITHIN(FLOAT_TEST_EPSILON, expected_x, actual.x); \
    TEST_ASSERT_FLOAT_WITHIN(FLOAT_TEST_EPSILON, expected_y, actual.y);

#define TEST_ASSERT_EQUAL_CIRCLE(expected_x, expected_y, expected_radius, actual)   \
    TEST_ASSERT_FLOAT_WITHIN(FLOAT_TEST_EPSILON, expected_x, actual.center.x);      \
    TEST_ASSERT_FLOAT_WITHIN(FLOAT_TEST_EPSILON, expected_y, actual.center.y);      \
    TEST_ASSERT_FLOAT_WITHIN(FLOAT_TEST_EPSILON, expected_radius, actual.radius);

#define TEST_ASSERT_EQUAL_SEGMENT(expected_ax, expected_ay, expected_bx, expected_by, actual)   \
    TEST_ASSERT_FLOAT_WITHIN(FLOAT_TEST_EPSILON, expected_ax, actual.a.x);                      \
    TEST_ASSERT_FLOAT_WITHIN(FLOAT_TEST_EPSILON, expected_ay, actual.a.y);                      \
    TEST_ASSERT_FLOAT_WITHIN(FLOAT_TEST_EPSILON, expected_bx, actual.b.x);                      \
    TEST_ASSERT_FLOAT_WITHIN(FLOAT_TEST_EPSILON, expected_by, actual.b.y);

#define TEST_ASSERT_EQUAL_CAPSULE(expected_ax, expected_ay, expected_bx, expected_by, expected_radius, actual)  \
    TEST_ASSERT_FLOAT_WITHIN(FLOAT_TEST_EPSILON, expected_ax, actual.segment.a.x);                              \
    TEST_ASSERT_FLOAT_WITHIN(FLOAT_TEST_EPSILON, expected_ay, actual.segment.a.y);                              \
    TEST_ASSERT_FLOAT_WITHIN(FLOAT_TEST_EPSILON, expected_bx, actual.segment.b.x);                              \
    TEST_ASSERT_FLOAT_WITHIN(FLOAT_TEST_EPSILON, expected_by, actual.segment.b.y);                              \
    TEST_ASSERT_FLOAT_WITHIN(FLOAT_TEST_EPSILON, expected_radius, actual.radius);
