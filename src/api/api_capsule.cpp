#include <diorama/capsule.h>

#include "api_cast.hpp"
#include "../geometry/primitives/capsule.hpp"

using namespace kojuelo::diorama;

int8_t capsule_equals(const capsule_t *capsule, const capsule_t *other)
{
    return CAPSULE_CONST_API_TO_LIB(capsule)->equals(*CAPSULE_CONST_API_TO_LIB(other)) ? 1 : 0;
}

int8_t capsule_equals_approx(const capsule_t *capsule, const capsule_t *other)
{
    return CAPSULE_CONST_API_TO_LIB(capsule)->equalsApprox(*CAPSULE_CONST_API_TO_LIB(other)) ? 1 : 0;
}

void capsule_translate(capsule_t *capsule, float x, float y)
{
    CAPSULE_API_TO_LIB(capsule)->translate(x, y);
}

void capsule_rotate_radians(capsule_t *capsule, float radians)
{
    CAPSULE_API_TO_LIB(capsule)->rotateRadians(radians);
}

void capsule_rotate_radians_at_pivot(capsule_t *capsule, const point_t *pivot, float radians)
{
    CAPSULE_API_TO_LIB(capsule)->rotateRadiansAtPivot(*POINT_CONST_API_TO_LIB(pivot), radians);
}

void capsule_rotate_degrees(capsule_t *capsule, float degrees)
{
    CAPSULE_API_TO_LIB(capsule)->rotateDegrees(degrees);
}

void capsule_rotate_degrees_at_pivot(capsule_t *capsule, const point_t *pivot, float degrees)
{
    CAPSULE_API_TO_LIB(capsule)->rotateDegreesAtPivot(*POINT_CONST_API_TO_LIB(pivot), degrees);
}

void capsule_scale(capsule_t *capsule, float x, float y, float radius)
{
    CAPSULE_API_TO_LIB(capsule)->scale(x, y, radius);
}