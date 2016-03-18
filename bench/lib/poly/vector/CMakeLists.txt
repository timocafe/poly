file(GLOB src "*.cpp")

foreach(files ${src})
    string(REPLACE ".cpp" "" tmp ${files})
    string(REPLACE "${CMAKE_SOURCE_DIR}/bench/lib/poly/vector/" "" exe ${tmp})
    set(VECTOR_LIB "poly_vector_${exe}")
    add_library(${VECTOR_LIB} ${files})
endforeach()

