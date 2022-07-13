#include <iostream>
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
    return OK;
}


}  // namespace ucg

STATUS main() {
    return ucg::testVector();
}
