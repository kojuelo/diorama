#include <point.h>

#include "api_cast.hpp"
#include "../geometry/primitives/point.hpp"

using namespace kojuelo::diorama;

bool point_equals(const point_t *point, const point_t *other)
{
    return POINT_CONST_API_TO_LIB(point).equals(POINT_CONST_API_TO_LIB(other));
}

bool point_equals_approx(const point_t *point, const point_t *other)
{
    return POINT_CONST_API_TO_LIB(point).equalsApprox(POINT_CONST_API_TO_LIB(other));
}

void point_translate(point_t *point, float x, float y)
{
    POINT_API_TO_LIB(point).translate(x, y);
}

void rotate_radians(point_t *point, float radians)
{
    POINT_API_TO_LIB(point).rotateRadians(radians);
}

void rotate_radians_at_pivot(point_t *point, const point_t *pivot, float radians)
{
    POINT_API_TO_LIB(point).rotateRadiansAtPivot(POINT_CONST_API_TO_LIB(pivot), radians);
}

void rotate_degrees(point_t *point, float degrees)
{
    POINT_API_TO_LIB(point).rotateDegrees(degrees);
}

void rotate_degrees_at_pivot(point_t *point, point_t *pivot, float degrees)
{
    POINT_API_TO_LIB(point).rotateDegreesAtPivot(POINT_CONST_API_TO_LIB(pivot), degrees);
}

void scale(point_t *point, float x, float y)
{
    POINT_API_TO_LIB(point).scale(x, y);
}