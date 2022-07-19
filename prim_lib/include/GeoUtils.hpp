#pragma once
#include "Core.hpp"
#include "LineSegment.hpp"
#include "Point.hpp"

namespace ucg {

/**
 * @brief Returns the area of a triangle defined by 3 points.
 * 
 * @return float 
 */
float areaTriangle2d(const Point2&, const Point2&, const Point2&);

RELATIVE_POS orientation2d(const Point2&, const Point2&, const Point2&);
RELATIVE_POS orientation2d(const LineSegment2&, const Point2&);
}  // namespace ucg
