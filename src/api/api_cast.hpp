#pragma once

#define POINT_CONST_API_TO_LIB(point) reinterpret_cast<const kojuelo::diorama::Point *>(point)

#define POINT_API_TO_LIB(point) reinterpret_cast<kojuelo::diorama::Point *>(point)