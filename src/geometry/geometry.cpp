#include "geometry.hpp"

#if _WIN32  // In Windows, this macro is needed to expose the PI macros.
    #define _USE_MATH_DEFINES
#endif
#include <math.h>

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

