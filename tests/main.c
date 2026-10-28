#include <diorama/point.h>

#include <stdio.h>
#include <unity.h>

#include "point.h"
#include "circle.h"

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

    return UNITY_END();
}