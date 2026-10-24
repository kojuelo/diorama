#include <geometry.h>

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