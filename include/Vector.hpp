#pragma once
#include <array>
#include <cmath>
#include <iostream>

namespace ucg {
#define DIM2 2
#define DIM3 3

#define X 0
#define Y 1
#define Z 2

#define EPSILON 0.0001


template <class dtype, size_t dim = DIM3>
class Vector {
  static_assert(std::is_arithmetic<dtype>(),
                "Vector class only supports numbers.");
  static_assert(dim >= DIM2, "Vector must be at least 2 dimensional");

  std::array<dtype, dim> value;

  friend std::ostream& operator<<(std::ostream& os, const Vector<dtype, dim>& v) {
    os << "(";
    for (size_t d = 0; d < dim - 1; ++d) {
      os << v[d] << " ,";
    }
    os << v[dim-1] << ")";
    return os;
  }

 public:
  Vector() {}

  explicit Vector(std::array<dtype, dim> _value) : value(_value) {}

  Vector(dtype _x, dtype _y) : value({_x, _y}) {}
  Vector(dtype _x, dtype _y, dtype _z) : value({_x, _y, _z}) {}
  
  bool operator==(const Vector<dtype, dim>&);
  bool operator!=(const Vector<dtype, dim>&);
  bool operator<(const Vector<dtype, dim>&);
  bool operator>(const Vector<dtype, dim>&);


  Vector<dtype, dim> operator+(const Vector<dtype, dim>&);
  Vector<dtype, dim> operator-(const Vector<dtype, dim>&);
  Vector<dtype, dim> operator*(const dtype&);
  dtype& operator[](size_t);
  dtype operator[](size_t) const;

  // magnitude
  float mag() const;

  // square sum
  float smag() const;

  Vector<dtype, dim> norm() const;
  void normalize();

  // friend Vector<dtype, dim> cross2d(const Vector<dtype, size_t>&);
  // friend Vector<dtype, dim> cross3d(const Vector<dtype, size_t>&);
  // friend float dot(const Vector<dtype, size_t>&, const Vector<dtype, size_t>&);
};

typedef Vector<float, DIM2> Vector2f;
typedef Vector<float, DIM3> Vector3f;

float cross2d(const Vector2f& v1, const Vector2f& v2);
Vector3f cross3d(const Vector3f& v1, const Vector3f& v2);

// template<class dtype, size_t dim>
// std::ostream& operator<<(std::ostream &os, const Vector<dtype, dim>& v) {
//   os << "(";
//   for (size_t d = 0; d < dim - 1; ++d) {
//     os << v[d] << " ,";
//   }
//   os << v[dim-1] << ")";
//   return os;
// }

template<class dtype, size_t dim>
inline bool Vector<dtype, dim>::operator==(const Vector<dtype, dim>& other) {
  for (size_t d = 0; d < dim; ++d) {
    if (fabs(value[d] - other[d]) >= EPSILON)
      return false;
  }
  return true;
}

template<class dtype, size_t dim>
inline bool Vector<dtype, dim>::operator!=(const Vector<dtype, dim>& other) {
  return !(*this == other);
}

template<class dtype, size_t dim>
inline bool Vector<dtype, dim>::operator<(const Vector<dtype, dim>& other) {
  for (size_t d = 0; d < dim; ++d) {
    if (*this[d] < other[d]) {
      return true;
    } else if (*this[d] > other[d]) {
      return false;
    }
  }
  return false;
}

template<class dtype, size_t dim>
inline bool Vector<dtype, dim>::operator>(const Vector<dtype, dim>& other) {
  if (*this == other)
    return false;

  return !(*this < other);
}

template<class dtype, size_t dim>
inline Vector<dtype, dim> Vector<dtype, dim>::operator+(const Vector<dtype, dim>& other) {
  std::array<dtype, dim> tmp(this->value);
  for (size_t d = 0; d < dim; ++d) {
    tmp += other[d];
  }
  return tmp;
}

template<class dtype, size_t dim>
inline Vector<dtype, dim> Vector<dtype, dim>::operator-(const Vector<dtype, dim>& other) {
  return *this + (-1*other);
}

template<class dtype, size_t dim>
inline Vector<dtype, dim> Vector<dtype, dim>::operator*(const dtype& scalar) {
  Vector<dtype, dim> tmp(this->value);
  for (dtype& v : tmp.value) {
    v *= scalar;
  }
  return tmp;
}

template<class dtype, size_t dim>
inline dtype Vector<dtype, dim>::operator[](size_t index) const {
  return value[index];
}

template<class dtype, size_t dim>
inline dtype& Vector<dtype, dim>::operator[](size_t index) {
  return value[index];
}

template<class dtype, size_t dim>
float dot(const Vector<dtype, dim>& v1,
          const Vector<dtype, dim>& v2) {
  float result = 0.f;
  for (size_t d = 0; d < dim; ++d) {
    result += v1[d] * v2[d];
  }

  return result;
}

template<class dtype, size_t dim>
inline float Vector<dtype, dim>::smag() const {
  float result = 0.f;
  for (size_t d = 0; d < dim; ++d)
    result += value[d] * value[d];

  return result;
}

template<class dtype, size_t dim>
inline float Vector<dtype, dim>::mag() const {
  return sqrt(smag());
}

template<class dtype, size_t dim>
inline void Vector<dtype, dim>::normalize() {
  const float _mag = mag();
  for (dtype& v : value) {
    v /= _mag;
  }
}

template<class dtype, size_t dim>
inline Vector<dtype, dim> Vector<dtype, dim>::norm() const {
  Vector<dtype, dim> tmp(this->value);
  tmp.normalize();
  return tmp;
}

};  // namespace ucg
