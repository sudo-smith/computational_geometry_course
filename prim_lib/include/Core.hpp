#pragma once

#include <math.h>

#define EPSILON 0.00001

namespace ucg {
enum RELATIVE_POS {
  LEFT = 2 >> 1,
  RIGHT = 2 << 0,
  BEHIND = 2 << 1,
  BEYOND = 2 << 2,
  BETWEEN = 2 << 3,
  ORIGIN = 2 << 4,
  DESTINATION = 2 << 5
};

constexpr const char* RELATIVE_POS_TO_STR(RELATIVE_POS p) noexcept {
  switch (p) {
    case RELATIVE_POS::LEFT: return "LEFT";
    case RELATIVE_POS::RIGHT: return "RIGHT";
    case RELATIVE_POS::BEHIND: return "BEHIND";
    case RELATIVE_POS::BEYOND: return "BEYOND";
    case RELATIVE_POS::BETWEEN: return "BETWEEN";
    case RELATIVE_POS::ORIGIN: return "ORIGIN";
    case RELATIVE_POS::DESTINATION: return "DESTINATION";
  }
  return "ERROR. Should never happen";
}

inline bool isEqual(float s1, float s2) { return fabs(s1 - s2) < EPSILON; }
}  // namespace ucg
