#pragma once

#include <diorama/api.h>
#include <diorama/point.h>

DIORAMA_API_SCOPE_START

DIORAMA_API float geometry_radians_to_degrees(float radians);

DIORAMA_API float geometry_degrees_to_radians(float degrees);

DIORAMA_API float geometry_point_distance_squared(const point_t *a, const point_t *b);

DIORAMA_API float geometry_point_distance(const point_t *a, const point_t *b);

DIORAMA_API float geometry_point_interpolate(const point_t *a, const point_t *b, float interpolant);

DIORAMA_API_SCOPE_END