
foreach(i ${libexp})
    add_executable(poly_scalar_throughput_${i} main_scalar.cpp)
    add_executable(poly_vector_throughput_${i} main_vector.cpp)
    target_link_libraries(poly_scalar_throughput_${i} poly_scalar_${i})
    target_link_libraries(poly_vector_throughput_${i} poly_vector_${i})
endforeach()

