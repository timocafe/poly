
foreach(i ${libexp})
    add_executable(exp_scalar_throughput_${i} main_scalar.cpp)
    target_link_libraries(exp_scalar_throughput_${i} exp_scalar_${i})
if(POLY_CYME)
    add_executable(exp_vector_throughput_${i} main_vector.cpp)
    target_link_libraries(exp_vector_throughput_${i} exp_vector_${i})
endif()
endforeach()

if (CMAKE_SYSTEM_PROCESSOR MATCHES "(x86)|(X86)")
if(POLY_CYME)
    add_executable(exp_vector_throughput_vendor main_vector.cpp)
    set_target_properties(exp_vector_throughput_vendor PROPERTIES COMPILE_FLAGS -DEXP_VENDOR)
    target_link_libraries(exp_vector_throughput_vendor -L${INTEL_LIB_PATH} -lsvml)
endif()

    add_executable(exp_scalar_throughput_vendor main_scalar.cpp)
    set_target_properties(exp_scalar_throughput_vendor PROPERTIES COMPILE_FLAGS -DEXP_VENDOR)
    target_link_libraries(exp_scalar_throughput_vendor -L ${INTEL_LIB_PATH} -limf)
endif()

if (CMAKE_SYSTEM_PROCESSOR MATCHES "(ppc64le)")
    add_executable(exp_vector_throughput_vendor main_vector.cpp)
    set_target_properties(exp_vector_throughput_vendor PROPERTIES COMPILE_FLAGS -DEXP_VENDOR)
    target_link_libraries(exp_vector_throughput_vendor /opt/ibm/xlmass/8.1.3/lib/libmassvp8.a
                                                       /opt/ibm/xlmass/8.1.3/lib/libmass_simdp8.a
                                                       /opt/ibm/xlmass/8.1.3/lib/libmass.a
                                                       /opt/ibm/xlmass/8.1.3/lib/libmassv.a )
    
    add_executable(exp_scalar_throughput_vendor main_scalar.cpp)
    set_target_properties(exp_scalar_throughput_vendor PROPERTIES COMPILE_FLAGS -DEXP_VENDOR)
    target_link_libraries(exp_scalar_throughput_vendor /opt/ibm/xlmass/8.1.3/lib/libmass.a)
endif()
