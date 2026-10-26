#pragma once

#include <diorama/api.h>
#include <diorama/point.h>

#include <stdint.h>

DIORAMA_API_SCOPE_START

typedef struct bounds_t
{
    float xMin;
    float yMin;
    float xMax;
    float yMax;
} bounds_t;

DIORAMA_API void bounds_calculate_from_corner(const point_t *corner, float width, float height, bounds_t *outBounds);

DIORAMA_API void bounds_calculate_from_center(const point_t *center, float width, float height, bounds_t *outBounds);

DIORAMA_API void bounds_combine(const bounds_t *a, const bounds_t *b, bounds_t *outBounds);

DIORAMA_API void bounds_validate(bounds_t *bounds);

DIORAMA_API void bounds_translate(bounds_t *bounds, float x, float y);

DIORAMA_API void bounds_scale_from_center(bounds_t *bounds, float x, float y);

DIORAMA_API void bounds_scale_from_min(bounds_t *bounds, float x, float y);

DIORAMA_API void bounds_scale_from_max(bounds_t *bounds, float x, float y);

DIORAMA_API void bounds_constaint(bounds_t *bounds, const point_t *point, int8_t *outResult);

DIORAMA_API void bounds_overlaps(bounds_t *bounds, const bounds_t *other, int8_t *outResult);

DIORAMA_API void bounds_get_width(bounds_t *bounds, float *outWidth);

DIORAMA_API void bounds_get_height(bounds_t *bounds, float *outHeight);

DIORAMA_API void bounds_is_valid(bounds_t *bounds, int8_t *outResult);

DIORAMA_API_SCOPE_END