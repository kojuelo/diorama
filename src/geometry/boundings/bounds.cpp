#include "bounds.hpp"

#include <cmath>

using namespace kojuelo::diorama;

void calculateSizeShift(const Bounds &bounds, float xFactor, float yFactor, float &outWidthShift, float &outShiftGrowth)
{
    float width = bounds.getWidth();
    float height = bounds.getHeight();

    outWidthShift = (width * xFactor) - width;
    outShiftGrowth = (height * yFactor) - height;
}

void calculateSizeShiftHalf(const Bounds &bounds, float xFactor, float yFactor, float &outWidthShiftHalf, float &outHeightShiftHalf)
{
    calculateSizeShift(bounds, xFactor, yFactor, outWidthShiftHalf, outHeightShiftHalf);

    outWidthShiftHalf *= .5f;
    outHeightShiftHalf *= .5f;
}

Bounds kojuelo::diorama::Bounds::calculateFromCorner(const Point &corner, float width, float height)
{
    Bounds bounds;

    if (width >= 0.0f)
    {
        bounds.xMin = corner.x;
        bounds.xMax = corner.x + width;
    }
    else
    {
        bounds.xMin = corner.x - width;
        bounds.xMax = corner.x;
    }

    if (height >= 0.0f)
    {
        bounds.yMin = corner.y;
        bounds.yMax = corner.y + height;
    }
    else
    {
        bounds.yMin = corner.y - height;
        bounds.yMax = corner.y;
    }

    return bounds;
}

Bounds kojuelo::diorama::Bounds::calculateFromCenter(const Point &center, float width, float height)
{
    const float halfWidth = width * .5f;
    const float halfHeight = height * .5f;

    Bounds bounds;

    bounds.xMin = center.x - halfWidth;
    bounds.xMax = center.x + halfWidth;

    bounds.yMin = center.y - halfHeight;
    bounds.yMax = center.y + halfHeight;

    return bounds;
}

Bounds kojuelo::diorama::Bounds::combine(const Bounds &a, const Bounds &b)
{
    return Bounds(std::min(a.xMin, b.xMin), std::min(a.yMin, b.yMin), std::max(a.xMax, b.xMax), std::max(a.yMax, b.yMax));
}

void kojuelo::diorama::Bounds::validate()
{
    if (xMin > xMax)
    {
        float xMinTemp = xMin;

        xMin = xMax;
        xMax = xMinTemp;
    }

    if (yMin > yMax)
    {
        float yMinTemp = yMin;

        yMin = yMax;
        yMax = yMinTemp;
    }
}

void kojuelo::diorama::Bounds::translate(float x, float y)
{
    xMin += x;
    xMax += x;

    yMin += y;
    yMax += y;
}

void kojuelo::diorama::Bounds::scaleFromCenter(float x, float y)
{
    float widthShiftHalf;
    float heightShiftHalf;

    calculateSizeShiftHalf(*this, x, y, widthShiftHalf, heightShiftHalf);

    xMin -= widthShiftHalf;
    xMax += widthShiftHalf;

    yMin -= heightShiftHalf;
    yMax += heightShiftHalf;
}

void kojuelo::diorama::Bounds::scaleFromMin(float x, float y)
{
    float widthShift;
    float heightShift;

    calculateSizeShift(*this, x, y, widthShift, heightShift);

    xMax += widthShift;
    yMax += heightShift;
}

void kojuelo::diorama::Bounds::scaleFromMax(float x, float y)
{
    float widthShift;
    float heightShift;

    calculateSizeShift(*this, x, y, widthShift, heightShift);

    xMin -= widthShift;
    yMin -= heightShift;
}

bool kojuelo::diorama::Bounds::contains(const Point &point) const
{
    if (point.x < xMin)
    {
        return false;
    }

    if (point.x > xMax)
    {
        return false;
    }

    if (point.y < yMin)
    {
        return false;
    }

    if (point.y > yMax)
    {
        return false;
    }

    return true;
}

bool kojuelo::diorama::Bounds::overlaps(const Bounds &bounds) const
{
    if (xMin > bounds.xMax)
    {
        return false;
    }

    if (xMax < bounds.xMin)
    {
        return false;
    }

    if (yMin > bounds.yMax)
    {
        return false;
    }

    if (yMax < bounds.yMin)
    {
        return false;
    }

    return true;
}

float kojuelo::diorama::Bounds::getWidth() const
{
    return xMax - xMin;
}

float kojuelo::diorama::Bounds::getHeight() const
{
    return yMax - yMin;
}

bool kojuelo::diorama::Bounds::isValid() const
{
    return (xMin <= xMax) && (yMin <= yMax);
}
