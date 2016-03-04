
foreach(i ${libexp})
    add_executable(scalar_throughput_${i} main_scalar.cpp)
    add_executable(vector_throughput_${i} main_vector.cpp)
    target_link_libraries(scalar_throughput_${i} scalar_${i})
    target_link_libraries(vector_throughput_${i} vector_${i})
endforeach()

if (CMAKE_SYSTEM_PROCESSOR MATCHES "(x86)|(X86)")
    add_executable(vector_throughput_vendor main_vector.cpp)
    set_target_properties(vector_throughput_vendor PROPERTIES COMPILE_FLAGS -DEXP_VENDOR)
    target_link_libraries(vector_throughput_vendor -lsvml)

    add_executable(scalar_throughput_vendor main_scalar.cpp)
    set_target_properties(scalar_throughput_vendor PROPERTIES COMPILE_FLAGS -DEXP_VENDOR)
    target_link_libraries(scalar_throughput_vendor -limf)
endif()

if (CMAKE_SYSTEM_PROCESSOR MATCHES "(ppc64le)")
    add_executable(vector_throughput_vendor main_vector.cpp)
    set_target_properties(vector_throughput_vendor PROPERTIES COMPILE_FLAGS -DEXP_VENDOR)
    target_link_libraries(vector_throughput_vendor /opt/ibm/xlmass/8.1.3/lib/libmassvp8.a
                                            /opt/ibm/xlmass/8.1.3/lib/libmass_simdp8.a
                                            /opt/ibm/xlmass/8.1.3/lib/libmass.a
                                            /opt/ibm/xlmass/8.1.3/lib/libmassv.a )
    
    add_executable(scalar_throughput_vendor main_scalar.cpp)
    set_target_properties(scalar_throughput_vendor PROPERTIES COMPILE_FLAGS -DEXP_VENDOR)
    target_link_libraries(scalar_throughput_vendor /opt/ibm/xlmass/8.1.3/lib/libmass.a)
endif()
