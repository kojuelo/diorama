#include <diorama/geometry.h>

#include "api_cast.hpp"
#include "../geometry/geometry.hpp"

using namespace kojuelo::diorama;

float geometry_radians_to_degrees(float radians)
{
    return geometry::radiansToDegrees(radians);
}

float geometry_degrees_to_radians(float degrees)
{
    return geometry::degreesToRadians(degrees);
}

float geometry_point_distance_squared(const point_t *a, const point_t *b)
{
    return geometry::pointDistanceSquared(*POINT_CONST_API_TO_LIB(a), *POINT_CONST_API_TO_LIB(b));
}

float geometry_point_distance(const point_t *a, const point_t *b)
{
    return geometry::pointDistance(*POINT_CONST_API_TO_LIB(a), *POINT_CONST_API_TO_LIB(b));
}

void geometry_point_interpolate(const point_t *a, const point_t *b, float interpolant, point_t *point_output)
{
    Point result = geometry::pointInterpolate(*POINT_CONST_API_TO_LIB(a), *POINT_CONST_API_TO_LIB(b), interpolant);

    point_output->x = result.x;
    point_output->y = result.y;
}