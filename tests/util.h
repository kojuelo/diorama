#pragma once

#include <unity.h>

#define FLOAT_TEST_EPSILON 0.00001f

#define TEST_ASSERT_EQUAL_POINT(expected_x, expected_y, actual)         \
    TEST_ASSERT_FLOAT_WITHIN(FLOAT_TEST_EPSILON, expected_x, actual.x); \
    TEST_ASSERT_FLOAT_WITHIN(FLOAT_TEST_EPSILON, expected_y, actual.y);

