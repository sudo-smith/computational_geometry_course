add_library(prim_lib
            Intersection.cpp
            GeoUtils.cpp
            Vector.cpp)

target_include_directories(prim_lib PUBLIC ../include)

