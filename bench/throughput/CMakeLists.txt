
foreach(i ${libexp})
    add_executable(scalar_throughput_${i} main_scalar.cpp)
    add_executable(vector_throughput_${i} main_vector.cpp)
    target_link_libraries(scalar_throughput_${i} scalar_${i})
    target_link_libraries(vector_throughput_${i} vector_${i})
endforeach()
