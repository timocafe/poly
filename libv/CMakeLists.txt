

file(GLOB test_src "src/cyme_*.cpp")

foreach(files ${test_src})
    string(REPLACE ".cpp" "" tmp ${files})
    string(REPLACE "${CMAKE_SOURCE_DIR}/libv/src/" "" lib ${tmp})
    add_library(${lib} ${files})
endforeach()

