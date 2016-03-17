
foreach(i ${libexp})
    add_executable(exp_test_scalar_${i} test_scalar.cpp)
    add_executable(exp_test_vector_${i} test_vector.cpp)
    target_link_libraries(exp_test_scalar_${i} exp_scalar_${i})
    target_link_libraries(exp_test_vector_${i} exp_vector_${i})
    add_test(exp_test_scalar_${i} exp_test_scalar_${i})
    add_test(exp_test_vector_${i} exp_test_vector_${i})
endforeach()
