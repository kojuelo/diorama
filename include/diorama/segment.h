#pragma once

#include <diorama/api.h>
#include <diorama/point.h>

#include <stdint.h>

DIORAMA_API_SCOPE_START

typedef struct segment_t
{
    point_t a;
    point_t b;
} segment_t;

DIORAMA_API int8_t segment_equals(const segment_t *segment, const segment_t *other);

DIORAMA_API int8_t segment_equals_approx(const segment_t *segment, const segment_t *other);

DIORAMA_API void segment_translate(segment_t *segment, float x, float y);

DIORAMA_API void segment_rotate_radians(segment_t *segment, float radians);

DIORAMA_API void segment_rotate_radians_at_pivot(segment_t *segment, const point_t *pivot, float radians);

DIORAMA_API void segment_rotate_degrees(segment_t *segment, float degrees);

DIORAMA_API void segment_rotate_degrees_at_pivot(segment_t *segment, const point_t *pivot, float degrees);

DIORAMA_API void segment_scale(segment_t *segment, float x, float y);

DIORAMA_API_SCOPE_END