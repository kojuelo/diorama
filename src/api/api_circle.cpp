#include <diorama/circle.h>

#include "api_cast.hpp"
#include "../geometry/primitives/circle.hpp"

using namespace kojuelo::diorama;

int8_t circle_equals(const circle_t *circle, const circle_t *other)
{
    return CIRCLE_CONST_API_TO_LIB(circle)->equals(*CIRCLE_CONST_API_TO_LIB(other)) ? 1 : 0;
}

int8_t circle_equals_approx(const circle_t *circle, const point_t *other)
{
    return CIRCLE_CONST_API_TO_LIB(circle)->equalsApprox(*CIRCLE_CONST_API_TO_LIB(other))  ? 1 : 0;
}

void circle_translate(circle_t *circle, float x, float y)
{
    CIRCLE_API_TO_LIB(circle)->translate(x, y);
}

void circle_rotate_radians(circle_t *circle, float radians)
{
    CIRCLE_API_TO_LIB(circle)->rotateRadians(radians);
}

void circle_rotate_radians_at_pivot(circle_t *circle, const point_t *pivot, float radians)
{
    CIRCLE_API_TO_LIB(circle)->rotateRadiansAtPivot(*POINT_CONST_API_TO_LIB(pivot), radians);
}

void circle_rotate_degrees(circle_t *circle, float degrees)
{
    CIRCLE_API_TO_LIB(circle)->rotateDegrees(degrees);
}

void circle_rotate_degrees_at_pivot(circle_t *circle, point_t *pivot, float degrees)
{
    CIRCLE_API_TO_LIB(circle)->rotateDegreesAtPivot(*POINT_CONST_API_TO_LIB(pivot), degrees);
}

void circle_scale(circle_t *circle, float x, float y, float radius)
{
    CIRCLE_API_TO_LIB(circle)->scale(x, y, radius);
}