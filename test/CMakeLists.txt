

file(GLOB poly_test_src "poly/*.cpp")

foreach(files ${poly_test_src})
    string(REPLACE ".cpp" "" tmp ${files})
    string(REPLACE "${CMAKE_SOURCE_DIR}/test/poly/" "" exe ${tmp})
    add_executable(${exe} ${files})
    target_link_libraries(${exe} ${Boost_LIBRARIES})
    add_test(${exe} ${exe})
endforeach()

