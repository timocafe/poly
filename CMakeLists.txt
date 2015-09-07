cmake_minimum_required (VERSION 2.8.10)
project (poly)
enable_testing()
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()
set(Boost_USE_STATIC_LIBS  ON)
find_package(Boost 1.44 REQUIRED unit_test_framework system)
#boost include
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR})
add_subdirectory (poly)
#test
add_subdirectory (test)

