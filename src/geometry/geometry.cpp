#include "geometry.hpp"

#if _WIN32  // In Windows, this macro is needed to expose the PI macros.
    #define _USE_MATH_DEFINES
#endif
#include <cmath>

#if _WIN32 // Windows doesn't have f versions.
    #define PI M_PI
    #define PI_2 M_PI_2
#else
    #define PI M_PIf
    #define PI_2 M_PI_2f
#endif

using namespace kojuelo::diorama;

float geometry::radiansToDegrees(float radians)
{
    return radians * (180.0f / PI);
}

float geometry::degreesToRadians(float degrees)
{
    return degrees * (PI / 180.0f);
}

float geometry::pointDistanceSquared(const Point &a, const Point &b)
{
    float xDiff = b.x - a.x;
    float yDiff = b.y - a.y;

    return (xDiff * xDiff) + (yDiff * yDiff);
}

float geometry::pointDistance(const Point &a, const Point &b)
{
    return std::sqrt(pointDistanceSquared(a, b));
}

Point geometry::pointInterpolate(const Point &a, const Point &b, float interpolant)
{
    return Point(
        a.x + ((b.x - a.x) * interpolant), 
        a.y + ((b.y - a.y) * interpolant)
    );
}