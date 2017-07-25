# poly

minimum recquirements:
  - GCC > 4.9 (primary compiler because inlining is better)
  - Intel Compiler (to compare to vendor implementation)
  - Power/X86 system 
  - linux system
  - cmake > 2.9
  - machine that understand x86/ppc ASM and the inline GCC mode
  
arborescence:
```
  poly -- bench (contains the benchmarks for latency/throughtput/ulp + header for the timer library)
          -- latency (latency benchmark)
          -- throughtput (throughtput benchmark)
          -- lib (contains implementation of exp, scalar/vector version)
             -- exp
                -- scalar (implementation of the exp scalar version) 
                -- vector (implementation of the exp vector version)          
             -- poly
                -- scalar (implementation of the polynomial evaluation scalar version) 
                -- vector (implementation of the polynomial evaluation vector version)          
             -- tool
                -- scalar(implementation of 2^k and the branching part for the scalar version)
                -- vector(implementation of 2^k and the branching part for the vector version)            
          -- ulp (ulp benchmark)
       -- cyme (DSL for the vectorial version)
       -- dot (contains ASM - DAG graphiz format/ATT)
       -- llc (tiny library to measure the throughput, read hardware counter)  
       -- poly (contains the program that generate all variations of the exp implementation for poly/lib directory)
```       
to compile
```
  mkdir b
  cd b
  cmake ..
  make // can be long > 3000 files to compiles
```
to modify
```
  ccmake .
  POLY_CYME buidl the vectorial version using cyme DSL (ON DEFAULT)
  POLY_BENCH build the benchmark throughput/ulp/latency (ON DEFAULT)
  POLY_TEST build the test (ON DEFAULT)
```

to run
```
  run.sh b exp > out // b for the build directory and exp for the results
```
to postprocess
```
  perl pp_exp.pl out > out.hmtl
```
For the story:
The directory poly/lib/scalar and poly/lib/vector contain the implementation of every exp(x). The generation of all theses files is performed with main.cpp of the lib directory.

If your machine is super experimental you may switch off (POLY_CYME,POLY_BENCH,POLY_TEST). Then you will a get a library for every implementation of the exp, free to you to work a simple benchmark with it.

