#include "Vector.hpp"

namespace ucg {

float cross2d(const Vector2f& v1, const Vector2f& v2) {
    return (v1[X] * v2[Y]) - (v1[Y] * v2[X]);
}

Vector3f cross3d(const Vector3f& v1, const Vector3f& v2) {
    return Vector3f( (v1[Y] * v2[Z]) - (v1[Z] * v2[Y]),
                     (v1[Z] * v2[X]) - (v1[X] * v2[Z]),
                     (v1[X] * v2[Y]) - (v1[Y] * v2[X]));
}

};  // namespace ucg


