


foreach(i ${libexp})
    add_executable(scalar_vector_latency_${i} cxx_demangle.cc primitive_ops.cc run_kernels.cc)
    if(POLY_CYME)
    target_compile_definitions(scalar_vector_latency_${i} PUBLIC -DPOLY_CYME)
    target_link_libraries(scalar_vector_latency_${i} exp_vector_${i} poly_vector_${i})
    target_link_libraries(scalar_vector_latency_${i} vector_twok vector_boundary)
    endif()
    target_link_libraries(scalar_vector_latency_${i} exp_scalar_${i} poly_scalar_${i})
    target_link_libraries(scalar_vector_latency_${i} scalar_twok scalar_boundary )
    if (CMAKE_SYSTEM_PROCESSOR MATCHES "(x86)|(X86)")
    target_link_libraries(scalar_vector_latency_${i} llc -L${INTEL_LIB_PATH} -lsvml -limf -lintlc)
    endif()

    if (CMAKE_SYSTEM_PROCESSOR MATCHES "(ppc64le)")
    target_link_libraries(scalar_vector_latency_${i} llc /opt/ibm/xlmass/8.1.3/lib/libmass.a /opt/ibm/xlmass/8.1.3/lib/libmass_simdp8.a)
    target_link_libraries(scalar_vector_latency_${i} /opt/ibm/xlmass/8.1.3/lib/libmassvp8.a
                                                     /opt/ibm/xlmass/8.1.3/lib/libmass_simdp8.a
                                                     /opt/ibm/xlmass/8.1.3/lib/libmass.a
                                                     /opt/ibm/xlmass/8.1.3/lib/libmassv.a )
    endif()

#    if (CMAKE_SYSTEM_PROCESSOR MATCHES "(ppc64)")
#    target_link_libraries(scalar_vector_latency_${i} llc /opt/ibmcmp/xlmass/bg/7.3/lib64/libmass_64.a /opt/ibmcmp/xlmass/bg/7.3/lib64/libmass_simdp7_64.a)
#    target_link_libraries(scalar_vector_latency_${i} /opt/ibmcmp/xlmass/bg/7.3/lib64/libmassvp7_64.a
#                                                     /opt/ibmcmp/xlmass/bg/7.3/lib64/libmass_simdp7_64.a
#                                                     /opt/ibmcmp/xlmass/bg/7.3/lib64/libmass_64.a)
#    endif()
    target_link_libraries(scalar_vector_latency_${i} llc)
endforeach()
