#pragma once

#include <diorama/api.h>
#include <diorama/segment.h>

#include <stdint.h>

DIORAMA_API_SCOPE_START

typedef struct capsule_t
{
    segment_t segment;
    float radius;
} capsule_t;

DIORAMA_API int8_t capsule_equals(const capsule_t *capsule, const capsule_t *other);

DIORAMA_API int8_t capsule_equals_approx(const capsule_t *capsule, const capsule_t *other);

DIORAMA_API void capsule_translate(capsule_t *capsule, float x, float y);

DIORAMA_API void capsule_rotate_radians(capsule_t *capsule, float radians);

DIORAMA_API void capsule_rotate_radians_at_pivot(capsule_t *capsule, const point_t *pivot, float radians);

DIORAMA_API void capsule_rotate_degrees(capsule_t *capsule, float degrees);

DIORAMA_API void capsule_rotate_degrees_at_pivot(capsule_t *capsule, const point_t *pivot, float degrees);

DIORAMA_API void capsule_scale(capsule_t *capsule, float x, float y, float radius);

DIORAMA_API_SCOPE_END