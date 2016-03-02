
foreach(i ${libexp})
    add_executable(scalar_vector_latency_${i} cxx_demangle.cc primitive_ops.cc run_kernels.cc)
    target_link_libraries(scalar_vector_latency_${i} scalar_${i})
    target_link_libraries(scalar_vector_latency_${i} vector_${i})
   #target_link_libraries(scalar_vector_latency_${i} llc -lsvml -limf)
    target_link_libraries(scalar_vector_latency_${i} llc -lsvml )
endforeach()
