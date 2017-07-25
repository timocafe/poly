# poly

minimum recquirements:
  - GCC > 4.9 (primary compiler because inlining is better)
  - Intel Compiler (to compare to vendor implementation)
  - Power/X86 system 
  - linux system
  - cmake > 2.9
  
arborescence:
```
  poly -- bench (contains the benchmarks for latency/throughtput/ulp + header for the timer library)
          -- latency (latency benchmark)
          -- throughtput (throughtput benchmark)
          -- lib (contains implementation of exp, scalar/vector version)
          -- ulp (ulp benchmark)
       -- cyme (DSL for the vectorial version)
       -- dot (contains ASM - DAG graphiz format/ATT)
       -- llc (tiny library to measure the throughput, read hardware counter)  
       -- poly (contains the program that generate all variations of the exp implementation)
```       
to compile
```
  mkdir b
  cd b
  cmake ..
  make // can be long > 3000 files to compiles
```
to run
```
  run.sh b exp > out // b for the build directory and exp for the results
```
to postprocess
```
  perl pp_exp.pl out > out.hmtl
```
