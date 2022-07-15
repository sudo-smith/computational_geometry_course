#pragma once

#include "Plane.hpp"
#include "Vector.hpp"

namespace ucg {
template <class dtype>
class Plane {
  Vector3f normal;
  float d;

 public:
  Plane() {}
  Plane(const Vector3f& _normal, float _d) : normal(_normal), d(_d) {}
  Plane(const Point3& p1, const Point3& p2, const Point3& p3) {
    normal = cross3d(p2 - p1, p3 - p1);
    d = dot<dtype, DIM3>(p1, normal);
  }
}
}  // namespace ucg
