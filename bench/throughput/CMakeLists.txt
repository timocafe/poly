
foreach(i ${libexp})
    add_executable(scalar_throughput_${i} main_scalar.cpp)
    add_executable(vector_throughput_${i} main_vector.cpp)
    target_link_libraries(scalar_throughput_${i} scalar_${i})
    target_link_libraries(vector_throughput_${i} vector_${i})
endforeach()

    add_executable(vector_throughput_svml4d main_svml4d.cpp)
    target_link_libraries(vector_throughput_svml4d -lsvml)

    add_executable(scalar_throughput_imf main_imf.cpp)
    target_link_libraries(scalar_throughput_imf -limf)
