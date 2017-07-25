# poly

Let's play with 236 exp(x) implementation

**minimum recquirements:**
  - GCC > 4.9 (primary compiler because inlining is better)
  - Intel Compiler (to compare to vendor implementation)
  - Power/X86 system 
  - linux system
  - cmake > 2.9
  - machine that understand x86/ppc ASM and the inline GCC mode
  
**arborescence:**
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
**to compile**
```
  mkdir b
  cd b
  cmake ..
  make // can be long > 3000 files to compile
```
**to modify**
```
  ccmake .
  POLY_CYME buidl the vectorial version using cyme DSL (ON DEFAULT)
  POLY_BENCH build the benchmark throughput/ulp/latency (ON DEFAULT)
  POLY_TEST build the test (ON DEFAULT)
  CMAKE_BUILD_TYPE DEBUG (default) / RELEASE (mandatory for the perf)
```

**to run (all)**
```
  run.sh b exp > out // b for the build directory and exp for the results
```
**to run (by hand)**
All numbers are fictives
**Latency**
```
   .b/bench/latency/scalar_vector_latency_ed10 poly // run ed10 for the polynomial scalar and vector version
   .b/bench/latency/scalar_vector_latency_ed10 exp  // run ed10 for the polynomial scalar and vector version
   .b/bench/latency/scalar_vector_latency_ed10 tool  // run the 2^k and the boundary
   .b/bench/latency/scalar_vector_latency_ed10 vendor  // run the vendor version
   [ewart@super_machine b]$ ./bench/latency/scalar_vector_latency_ed10 poly
   scalar::poly 35.0671
   vector::poly 30.2791
   [ewart@super_machine b]$ ./bench/latency/scalar_vector_latency_ed10 exp
   scalar::exp 75.0317
   vector::exp 61.4446
   [ewart@super_machine b]$ ./bench/latency/scalar_vector_latency_ed10 tool
   scalar::twok 36.006
   scalar::boundary 26.0249
   vector::twok 31.0046 // 2^k
   vector::boundary 20.96371 // the boundary condition
   [ewart@super_machine b]$ ./bench/latency/scalar_vector_latency_ed10 vendor
   imf 76.9489 // scalar version of intel
   svml4d 75.166 //vec version of intel
```
**ULP**
```
   .b/bench/ulp/exp/exp_scalar_ulp_ed10
   5 // the ulp is 3 compare to std::exp (IEEE std)
```
**Throughput**
```
   ./bench/throughput/exp/exp_scalar_throughput_ed10
   4.63
```
**to postprocess (all)**
```
  perl pp_exp.pl out > out.hmtl
```
**For the story:**
The directory poly/lib/scalar and poly/lib/vector contain the implementation of every exp(x). The generation of all theses files is performed with main.cpp of the lib directory.

If your machine is super experimental you may switch off (POLY_CYME,POLY_BENCH,POLY_TEST). Then you will a get a library for every implementation of the exp, free to you to work a simple benchmark with it.
