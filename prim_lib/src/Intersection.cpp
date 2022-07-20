#include "Intersection.hpp"
#include "GeoUtils.hpp"

bool ucg::Intersection(const Point2& a, const Point2& b,
                       const Point2& c, const Point2& d,
                       Point2& intersectionPoint) {
  if (!Intersection(a, b, c, d)) {
    return false;
  }

  Vector2f ab = b - a;
  Vector2f cd = d - c;

  // normal to vector cd
  Vector2f n(cd[Y], -cd[X]);

  float t = dot(n, c - a) / dot(n, b - a);
  intersectionPoint = (ab * t) + a;
  return true;
}

bool ucg::Intersection(const LineSegment2& l1, const LineSegment2& l2) {
  return Intersection(l1.a, l1.b, l2.a, l2.b);
}

bool ucg::Intersection(const Point2& a, const Point2& b,
                       const Point2& c, const Point2& d) {
  // find what the point c and d are relative to the line ab
  auto or_abc = orientation2d(a, b, c);
  auto or_abd = orientation2d(a, b, d);

  // find what the point a and b are relative to the line cd
  auto or_cda = orientation2d(c, d, a);
  auto or_cdb = orientation2d(c, d, b);

  // check if the lines are colinear and intersection or the endpoints
  // of each other touch the other's line.
  auto on_line = BETWEEN | ORIGIN | DESTINATION;
  if (or_abc & on_line ||
      or_abd & on_line ||
      or_cda & on_line ||
      or_cdb & on_line) {
    return true;
  }

  // check that a, b lie on different sides of l2 and that
  // c, d lie on different sides of l1. Do this by
  // checking that they're not both on the left side.
  return ((or_abc == LEFT) != (or_abd == LEFT)) &&
         ((or_cda == LEFT) != (or_cdb == LEFT));
}


bool ucg::Intersection(const LineSegment2& l1, const LineSegment2& l2, Point2& intersectionPoint) {
  return ucg::Intersection(l1.a, l1.b, l2.a, l2.b, intersectionPoint);
}
