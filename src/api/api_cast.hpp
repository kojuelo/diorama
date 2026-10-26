#pragma once

#define POINT_CONST_API_TO_LIB(point) reinterpret_cast<const kojuelo::diorama::Point *>(point)

#define POINT_CONST_LIB_TO_API(point) reinterpret_cast<const point_t *>(point)

#define POINT_API_TO_LIB(point) reinterpret_cast<kojuelo::diorama::Point *>(point)

#define POINT_LIB_TO_API(point) reinterpret_cast<point_t *>(point)

#define CIRCLE_CONST_API_TO_LIB(circle) reinterpret_cast<const kojuelo::diorama::Circle *>(circle)

#define CIRCLE_CONST_LIB_TO_API(circle) reinterpret_cast<const circle_t *>(circle)

#define CIRCLE_API_TO_LIB(circle) reinterpret_cast<kojuelo::diorama::Circle *>(circle)

#define CIRCLE_LIB_TO_API(circle) reinterpret_cast<circle_t *>(circle)

#define SEGMENT_CONST_API_TO_LIB(segment) reinterpret_cast<const kojuelo::diorama::Segment *>(segment)

#define SEGMENT_CONST_LIB_TO_API(segment) reinterpret_cast<const segment_t *>(segment)

#define SEGMENT_API_TO_LIB(segment) reinterpret_cast<kojuelo::diorama::Segment *>(segment)

#define SEGMENT_LIB_TO_API(segment) reinterpret_cast<segment_t *>(segment)

#define BOUNDS_CONST_API_TO_LIB(bounds) reinterpret_cast<const kojuelo::diorama::Bounds *>(bounds)

#define BOUNDS_CONST_LIB_TO_API(bounds) reinterpret_cast<const bounds_t *>(bounds)

#define BOUNDS_API_TO_LIB(bounds) reinterpret_cast<kojuelo::diorama::Bounds *>(bounds)

#define BOUNDS_LIB_TO_API(bounds) reinterpret_cast<bounds_t *>(bounds)