#include <iostream>
#include "GeoUtils.hpp"
#include "Point.hpp"
#include "Vector.hpp"


#define OK 0
#define ERROR -1
#define STATUS int

namespace ucg {

STATUS testVector() {
    Vector3f v1(4, 2, 4);
    std::cout << v1.norm() << std::endl;
    std::cout << v1 << std::endl;
    v1.normalize();
    std::cout << v1 << std::endl;

    return OK;
}

STATUS ex_01_10() {
    std::cout << "=============\n";
    Point2 a(5, 3);
    Point2 b(2, 8);
    Point2 c1(4, 9);
    Point2 c2(3, 3);
    std::cout << "A: " << a << std::endl;
    std::cout << "B: " << b << std::endl;
    std::cout << "C1: " << c1 << std::endl;
    std::cout << "C2: " << c2 << std::endl;

    std::cout << "\n";
    std::cout << "Triangle Area (a, b, c1): " << areaTriangle2d(a, b, c1) << std::endl;
    std::cout << "Position of C1 relative to AB: "
              << RELATIVE_POS_TO_STR(orientation2d(a, b , c1)) << std::endl;
    std::cout << "\n";
    std::cout << "Triangle Area (a, b, c2): " << areaTriangle2d(a, b, c2) << std::endl;
    std::cout << "Position of C1 relative to AB: "
              << RELATIVE_POS_TO_STR(orientation2d(a, b , c2)) << std::endl;


    return OK;
}


}  // namespace ucg

STATUS main() {
    if (ucg::testVector())
        return ERROR;
    if (ucg::ex_01_10())
        return ERROR;
    return OK;
}
