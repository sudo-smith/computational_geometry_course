#include "Intersection.hpp"
#include "GeoUtils.hpp"

bool ucg::Intersection(const LineSegment2& l1, const LineSegment2& l2) {
  // assume l1 is defined by (a->b) and l2 defined by (c->d)
  auto a_rel_to_l2 = orientation2d(l2, l1.a);
  auto b_rel_to_l2 = orientation2d(l2, l1.b);
  auto c_rel_to_l1 = orientation2d(l1, l2.a);
  auto d_rel_to_l1 = orientation2d(l1, l2.b);

  // if either endpoints of either lines lies on the line of hte other,
  // then return true
  auto on_line = BETWEEN | ORIGIN | DESTINATION;

  if (a_rel_to_l2 & on_line ||
      b_rel_to_l2 & on_line ||
      c_rel_to_l1 & on_line ||
      d_rel_to_l1 & on_line) {
    return true;
  }

  // check that a, b lie on different sides of l2 and that
  // c, d lie on different sides of l1. Do this by
  // checking that they're not both on the left side
  return (a_rel_to_l2 == LEFT ^ b_rel_to_l2 == LEFT) &&
         (c_rel_to_l1 == LEFT ^ d_rel_to_l1 == LEFT);
}

bool ucg::Intersection(const Point2& a, const Point2& b,
                       const Point2& c, const Point2& d) {
  return ucg::Intersection(LineSegment2(a, b), LineSegment2(c, d));
}