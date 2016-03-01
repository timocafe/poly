
foreach(i ${libexp})
    add_executable(scalar_vector_latency_${i} cxx_demangle.cc primitive_ops.cc run_kernels.cc)
    target_link_libraries(scalar_vector_latency_${i} scalar_${i})
    target_link_libraries(scalar_vector_latency_${i} vector_${i})
    target_link_libraries(scalar_vector_latency_${i} llc -L/cm/shared/apps/intel/composer_xe/2015.5.223/compiler/lib/intel64/ -lsvml)
endforeach()

include_directories(..)
include_directories(install/include)

