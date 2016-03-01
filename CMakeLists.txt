cmake_minimum_required (VERSION 2.6)
project (poly)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMake)

include(CheckCXXSourceCompiles)
include(CheckCXXCompilerFlag)
include(CheckCXXSourceRuns)

find_package(SIMD)
find_package(FMA)

include(SelectTech)
include(Compiler)
set(CMAKE_CXX_FLAGS "${CXX_DIALECT_OPT_CXX11} ${COMPILER_OPT_ARCH_NATIVE} ${CMAKE_CXX_FLAGS} ${CYME_FMA_FLAGS} ${CYME_SIMD_FLAGS}")

enable_testing()
set(Boost_USE_STATIC_LIBS  ON)
find_package(Boost 1.44 REQUIRED unit_test_framework system)
#boost include
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/cyme/include)
add_subdirectory (poly)
#test
add_subdirectory (test)
#bench
add_subdirectory (llc)
add_subdirectory (bench)

