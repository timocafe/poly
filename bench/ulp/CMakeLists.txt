
foreach(i ${libexp})
    add_executable(scalar_ulp_${i} main_scalar.cpp)
    add_executable(vector_ulp_${i} main_vector.cpp)
    target_link_libraries(scalar_ulp_${i} scalar_${i})
    target_link_libraries(vector_ulp_${i} vector_${i})
endforeach()

    add_executable(vector_ulp_svml4d main_svml4d.cpp)
    target_link_libraries(vector_ulp_svml4d -lsvml)

    add_executable(scalar_ulp_imf main_imf.cpp)
    target_link_libraries(scalar_ulp_imf -limf)
