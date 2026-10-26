#include <diorama/segment.h>

#include "api_cast.hpp"
#include "../geometry/primitives/segment.hpp"

using namespace kojuelo::diorama;

int8_t segment_equals(const segment_t *segment, const segment_t *other)
{
    return SEGMENT_CONST_API_TO_LIB(segment)->equals(*SEGMENT_CONST_API_TO_LIB(other)) ? 1 : 0;
}

int8_t segment_equals_approx(const segment_t *segment, const segment_t *other)
{
    return SEGMENT_CONST_API_TO_LIB(segment)->equalsApprox(*SEGMENT_CONST_API_TO_LIB(other)) ? 1 : 0;
}

void segment_translate(segment_t *segment, float x, float y)
{
    SEGMENT_API_TO_LIB(segment)->translate(x, y);
}

void segment_rotate_radians(segment_t *segment, float radians)
{
    SEGMENT_API_TO_LIB(segment)->rotateRadians(radians);
}

void segment_rotate_radians_at_pivot(segment_t *segment, const point_t *pivot, float radians)
{
    SEGMENT_API_TO_LIB(segment)->rotateRadiansAtPivot(*POINT_CONST_API_TO_LIB(pivot), radians);
}

void segment_rotate_degrees(segment_t *segment, float degrees)
{
    SEGMENT_API_TO_LIB(segment)->rotateDegrees(degrees);
}

void segment_rotate_degrees_at_pivot(segment_t *segment, const point_t *pivot, float degrees)
{
    SEGMENT_API_TO_LIB(segment)->rotateDegreesAtPivot(*POINT_CONST_API_TO_LIB(pivot), degrees);
}

void segment_scale(segment_t *segment, float x, float y, float radius)
{
    SEGMENT_API_TO_LIB(segment)->scale(x, y);
}