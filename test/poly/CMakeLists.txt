
if(POLY_CYME)
foreach(i ${libexp})
    add_executable(poly_test_vector_${i} test_vector.cpp)
    target_link_libraries(poly_test_vector_${i} poly_vector_${i})
    add_test(poly_test_vector_${i} poly_test_vector_${i})
endforeach()

endif()

foreach(i ${libexp})
    add_executable(poly_test_scalar_${i} test_scalar.cpp)
    target_link_libraries(poly_test_scalar_${i} poly_scalar_${i})
    add_test(poly_test_scalar_${i} poly_test_scalar_${i})
endforeach()
