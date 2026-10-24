#pragma once

#include <api.h>

DIORAMA_API_SCOPE_START

typedef struct point_t
{
    float x;
    float y;
} point_t;

DIORAMA_API bool point_equals(const point_t *point, const point_t *other);

DIORAMA_API bool point_equals_approx(const point_t *point, const point_t *other);

DIORAMA_API void point_translate(point_t *point, float x, float y);

DIORAMA_API void rotate_radians(point_t *point, float radians);

DIORAMA_API void rotate_radians_at_pivot(point_t *point, const point_t *pivot, float radians);

DIORAMA_API void rotate_degrees(point_t *point, float degrees);

DIORAMA_API void rotate_degrees_at_pivot(point_t *point, const point_t *pivot, float degrees);

DIORAMA_API void scale(point_t *point, float x, float y);

DIORAMA_API_SCOPE_END