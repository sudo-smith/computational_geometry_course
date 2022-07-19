#include "GeoUtils.hpp"

#include "Vector.hpp"

namespace ucg {
float areaTriangle2d(const Point2& a, const Point2& b, const Point2& c) {
  Vector2f ab = b - a;
  Vector2f ac = c - a;

  return cross2d(ab, ac) / 2.f;
}

RELATIVE_POS orientation2d(const Point2& a, const Point2& b, const Point2& c) {
  float area = areaTriangle2d(a, b, c);
  if (isEqual(area, 0)) {
    const Vector2f ab = b - a;
    const Vector2f ac = c - a;

    if (a == c) {
      return RELATIVE_POS::ORIGIN;
    } else if (b == c) {
      return RELATIVE_POS::DESTINATION;
    } else if (dot(ab, ac) < 0) {
      return RELATIVE_POS::BEHIND;
    } else if (ab.smag() > ac.smag()) {
      return RELATIVE_POS::BETWEEN;
    } else {
      return RELATIVE_POS::BEYOND;
    }
  } else if (area > 0) {
    return RELATIVE_POS::LEFT;
  } else {
    return RELATIVE_POS::RIGHT;
  }
}

RELATIVE_POS orientation2d(const LineSegment2& l, const Point2& p) {
  return orientation2d(l.a, l.b, p);
}

}  // namespace ucg
