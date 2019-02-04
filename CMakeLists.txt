cmake_minimum_required(VERSION 3.13)
project(PeakFinder)

set(CMAKE_CXX_STANDARD 17)

find_package(ROOT)
include(${ROOT_USE_FILE})

find_package(Qt4)
include( ${QT_USE_FILE} )
add_definitions( ${QT_DEFINITIONS} )

include_directories(${CMAKE_SOURCE_DIR}/include)
file(GLOB SOURCE_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB INCLUDE_FILES ${CMAKE_SOURCE_DIR}/include/*.h)

add_executable(PeakFinder main.cpp ${SOURCE_FILES} ${INCLUDE_FILES} src/HitFindingAlg.cpp include/HitFindingAlg.h)
target_link_libraries(PeakFinder ${ROOT_LIBRARIES} ${QT_LIBRARIES})