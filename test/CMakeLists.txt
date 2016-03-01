
foreach(i ${libexp})
    add_executable(test_scalar_${i} test_scalar.cpp)
    add_executable(test_vector_${i} test_vector.cpp)
    target_link_libraries(test_scalar_${i} scalar_${i})
    target_link_libraries(test_vector_${i} vector_${i})
    add_test(test_scalar_${i} test_scalar_${i})
    add_test(test_vector_${i} test_vector_${i})
endforeach()
