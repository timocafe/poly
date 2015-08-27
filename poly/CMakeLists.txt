
set(tests POLY_Horner1 POLY_Horner2 POLY_Horner3 POLY_Horner4 POLY_Horner5 POLY_Horner6
          POLY_Horner7 POLY_Horner8 POLY_Horner9 POLY_Horner10 POLY_Estrin POLY_Factorization
          POLY_Bruteforce)

foreach(i ${tests})
    add_executable(poly_${i}  main.cpp polynomial.cpp)
    set_target_properties(poly_${i} PROPERTIES COMPILE_FLAGS "-D${i}")
endforeach()



