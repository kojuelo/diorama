#pragma once

#include <diorama/api.h>
#include <diorama/point.h>

#include <stdint.h>

DIORAMA_API_SCOPE_START

typedef struct circle_t
{
    point_t center;
    float radius;
} circle_t;

DIORAMA_API int8_t circle_equals(const circle_t *circle, const circle_t *other);

DIORAMA_API int8_t circle_equals_approx(const circle_t *circle, const circle_t *other);

DIORAMA_API void circle_translate(circle_t *circle, float x, float y);

DIORAMA_API void circle_rotate_radians(circle_t *circle, float radians);

DIORAMA_API void circle_rotate_radians_at_pivot(circle_t *circle, const point_t *pivot, float radians);

DIORAMA_API void circle_rotate_degrees(circle_t *circle, float degrees);

DIORAMA_API void circle_rotate_degrees_at_pivot(circle_t *circle, const point_t *pivot, float degrees);

DIORAMA_API void circle_scale(circle_t *circle, float x, float y, float radius);

DIORAMA_API_SCOPE_END