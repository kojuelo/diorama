#pragma once

#include "point.hpp"

namespace kojuelo::diorama
{
    class Circle
    {
    public:
        Point point;
        float radius;

        Circle() {};
        Circle(float x, float y, float radius)
        {
            Circle::point = Point(x, y);
            Circle::radius = radius;
        };

        bool equals(const Circle &other) const;
        bool equalsApprox(const Circle &other) const;

        void translate(float x, float y);

        void rotateRadians(float radians);
        void rotateRadiansAtPivot(const Point &pivot, float radians);

        void rotateDegrees(float degrees);
        void rotateDegreesAtPivot(const Point &pivot, float degrees);

        void scale(float x, float y, float radius);
    };
}