#pragma once

namespace kojuelo::diorama
{
    class Point
    {
    public:
        float x;
        float y;

        Point() {};
        Point(float x, float y)
        {
            Point::x = x;
            Point::y = y;
        };

        bool equals(const Point &other) const;
        bool equalsApprox(const Point &other) const;

        void translate(float x, float y);

        void rotateRadians(float radians);
        void rotateRadiansAtPivot(const Point &pivot, float radians);

        void rotateDegrees(float degrees);
        void rotateDegreesAtPivot(const Point &pivot, float degrees);

        void scale(float x, float y);
    };
}