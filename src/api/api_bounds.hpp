#include <diorama/bounds.h>

#include "api_cast.hpp"
#include "../geometry/boundings/bounds.hpp"

using namespace kojuelo::diorama;

void bounds_calculate_from_corner(const point_t *corner, float width, float height, bounds_t *outBounds)
{
    *BOUNDS_API_TO_LIB(outBounds) = Bounds::calculateFromCorner(*POINT_CONST_API_TO_LIB(corner), width, height);
}

void bounds_calculate_from_center(const point_t *center, float width, float height, bounds_t *outBounds)
{
    *BOUNDS_API_TO_LIB(outBounds) = Bounds::calculateFromCenter(*POINT_CONST_API_TO_LIB(center), width, height);
}

void bounds_combine(const bounds_t *a, const bounds_t *b, bounds_t *outBounds)
{
    *BOUNDS_API_TO_LIB(outBounds) = Bounds::combine(*BOUNDS_CONST_API_TO_LIB(a), *BOUNDS_CONST_API_TO_LIB(b));
}

void bounds_validate(bounds_t *bounds)
{
    BOUNDS_API_TO_LIB(bounds)->validate();
}

void bounds_translate(bounds_t *bounds, float x, float y)
{
    BOUNDS_API_TO_LIB(bounds)->translate(x, y);
}

void bounds_scale_from_center(bounds_t *bounds, float x, float y)
{
    BOUNDS_API_TO_LIB(bounds)->scaleFromCenter(x, y);
}

void bounds_scale_from_min(bounds_t *bounds, float x, float y)
{
    BOUNDS_API_TO_LIB(bounds)->scaleFromMin(x, y);
}

void bounds_scale_from_max(bounds_t *bounds, float x, float y)
{
    BOUNDS_API_TO_LIB(bounds)->scaleFromMax(x, y);
}

void bounds_constaint(bounds_t *bounds, const point_t *point, int8_t *outResult)
{
    *outResult = BOUNDS_API_TO_LIB(bounds)->contains(*POINT_CONST_API_TO_LIB(point)) ? 1 : 0;
}

void bounds_overlaps(bounds_t *bounds, const bounds_t *other, int8_t *outResult)
{
    *outResult = BOUNDS_API_TO_LIB(bounds)->overlaps(*BOUNDS_CONST_API_TO_LIB(other)) ? 1 : 0;
}

void bounds_get_width(bounds_t *bounds, float *outWidth)
{
    *outWidth = BOUNDS_API_TO_LIB(bounds)->getWidth();
}

void bounds_get_height(bounds_t *bounds, float *outHeight)
{
    *outHeight = BOUNDS_API_TO_LIB(bounds)->getHeight();
}

void bounds_is_valid(bounds_t *bounds, int8_t *outResult)
{
    *outResult = BOUNDS_API_TO_LIB(bounds)->isValid() ? 1 : 0;
}