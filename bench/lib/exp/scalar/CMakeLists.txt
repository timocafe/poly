file(GLOB src "*.cpp")

foreach(files ${src})
    string(REPLACE ".cpp" "" tmp ${files})
    string(REPLACE "${CMAKE_SOURCE_DIR}/bench/lib/exp/scalar/" "" exe ${tmp})
    set(SCALAR_LIB "exp_scalar_${exe}")
    add_library(${SCALAR_LIB} ${files})
endforeach()

