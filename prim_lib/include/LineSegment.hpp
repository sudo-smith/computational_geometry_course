#pragma once

#include "Vector.hpp"
namespace ucg {
template<class dtype, size_t dim>
class LineSegment {
  friend std::ostream& operator<<(std::ostream& os,
                                  const LineSegment<dtype, dim>& l) {
    return os << l.a << " -> " << l.b;
  }

 public:
  Vector<dtype, dim> a;
  Vector<dtype, dim> b;

  LineSegment(const Vector<dtype, dim>& _a,
              const Vector<dtype, dim>& _b) : a(_a), b(_b) {}
};

typedef LineSegment<float, DIM2> LineSegment2;
typedef LineSegment<float, DIM3> LineSegment3;


}  // namespace ucg
