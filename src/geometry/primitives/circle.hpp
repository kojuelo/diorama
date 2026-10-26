#pragma once

#include "point.hpp"
#include "../boundings/bounds.hpp"

namespace kojuelo::diorama
{
    class Circle
    {
    public:
        Point center;
        float radius;

        Circle() {};
        Circle(const Point& center, float radius)
        {
            Circle::center = center;
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

        Bounds getBounds() const;
    };
}