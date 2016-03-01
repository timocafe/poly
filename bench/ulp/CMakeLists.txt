
foreach(i ${libexp})
    add_executable(scalar_ulp_${i} main_scalar.cpp)
    add_executable(vector_ulp_${i} main_vector.cpp)
    target_link_libraries(scalar_ulp_${i} scalar_${i})
    target_link_libraries(vector_ulp_${i} vector_${i})
endforeach()
