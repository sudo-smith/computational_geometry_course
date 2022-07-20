#pragma once
#include "Point.hpp"
#include "LineSegment.hpp"
namespace ucg {

// returns true if line segment from point a, b intersect with point c, d
bool Intersection(const Point2& a, const Point2& b,
                  const Point2& c, const Point2& d);

bool Intersection(const LineSegment2& l1, const LineSegment2& l2);

bool Intersection(const LineSegment2& l1, const LineSegment2& l2, Point2& intersectionPoint);

bool Intersection(const Point2& a, const Point2& b,
                  const Point2& c, const Point2& d,
                  Point2& intersectionPoint);

}  // namespace ucg
