#pragma once

#include "../primitives/point.hpp"

namespace kojuelo::diorama
{
    class Bounds
    {
    public:
        float xMin;
        float yMin;
        float xMax;
        float yMax;

        Bounds() { };
        Bounds(float xMin, float yMin, float xMax, float yMax)
        {
            Bounds::xMin = xMin;
            Bounds::yMin = yMin;

            Bounds::xMax = xMax;
            Bounds::yMax = yMax;
        }

        static Bounds calculateFromCorner(const Point &corner, float width, float height);
        static Bounds calculateFromCenter(const Point &center, float width, float height);

        static Bounds combine(const Bounds &a, const Bounds &b);

        void validate();

        void translate(float x, float y);

        void scaleFromCenter(float x, float y);
        void scaleFromMin(float x, float y);
        void scaleFromMax(float x, float y);

        bool contains(const Point &point) const;
        bool overlaps(const Bounds &bounds) const;

        float getWidth() const;
        float getHeight() const;

        bool isValid() const;
    };
}