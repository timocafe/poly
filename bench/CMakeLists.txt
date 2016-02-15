file(GLOB benchmark_src "*.cpp")

foreach(files ${benchmark_src})
    string(REPLACE ".cpp" "" tmp ${files})
    string(REPLACE "${CMAKE_SOURCE_DIR}/bench/" "" exe ${tmp})
    add_executable(${exe} ${files})
endforeach()

