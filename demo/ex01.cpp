#include <iostream>
#include "GeoUtils.hpp"
#include "Point.hpp"
#include "Vector.hpp"
#include "Intersection.hpp"


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

STATUS sec10() {
    std::cout << "=============\n";
    std::cout << "Section 10\n";
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


STATUS sec13() {
    std::cout << "\n\n=============\n";
    std::cout << "Section 13/14\n";
    std::cout << "=============\n";

    auto print_intersection = [](const LineSegment2& l1, const LineSegment2& l2) {
        std::cout << "Line 1: " << l1 << std::endl;
        std::cout << "Line 2: " << l2 << std::endl;

        Point2 intersectionPoint;
        bool intersects = Intersection(l1, l2, intersectionPoint);
        std::cout << "Line 1 " << (intersects ? "INTERSECTS" : "DOES NOT INTERSECT") << " Line2";
        if (intersects) {
            std::cout << " at Point: " << intersectionPoint;
        }

        std::cout << "\n" << std::endl;
    };

    print_intersection(LineSegment2(Point2(-1, 0), Point2(1, 0)),
                       LineSegment2(Point2(0, -1), Point2(0, 1)));

    print_intersection(LineSegment2(Point2(0, 0), Point2(1, 0)),
                       LineSegment2(Point2(0, 0), Point2(0, 1)));

    print_intersection(LineSegment2(Point2(0, 1), Point2(1, 1)),
                       LineSegment2(Point2(0, 0), Point2(0, 0.5)));

    print_intersection(LineSegment2(Point2(0, 0), Point2(0, 1)),
                       LineSegment2(Point2(-1, 2), Point2(1, 2)));

    print_intersection(LineSegment2(Point2(0, 0), Point2(0, 1)),
                       LineSegment2(Point2(0, -1), Point2(0, 2)));

    return OK;
}


}  // namespace ucg

STATUS main() {
    if (ucg::testVector())
        return ERROR;
    if (ucg::sec10())
        return ERROR;
    if (ucg::sec13())
        return ERROR;
    return OK;
}
