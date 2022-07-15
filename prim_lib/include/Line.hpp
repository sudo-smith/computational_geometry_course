#pragma once

#include "Vector.hpp"

namespace ucg {
template <class dtype, size_t dim>
class Line {
  Vector<dtype, dim> origin;
  Vector<dtype, dim> dir;

 public:
  Line() {}

  Line(const Vector<dtype, dim>& p1, const Vector<dtype, dim>& p2) {
    dir = p2 - p1;
    origin = p1;
  }

  // copy getters
  Vector<dtype, dim> origin() const { return origin; }
  Vector<dtype, dim> dir() const { return dir; }
}
}  // namespace ucg
