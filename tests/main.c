#include <diorama/point.h>

#include <stdio.h>
#include <unity.h>

#include "point.h"
#include "circle.h"
#include "segment.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

int main()
{
    UNITY_BEGIN();

    run_tests_point();
    run_tests_circle();
    run_tests_segment();

    return UNITY_END();
}