#!/bin/bash

    echo "Solver Latency [cycle] Throughput [cycle]"
for i in Horner1 Horner2 Horner3 Horner4 Horner5 Horner6 Horner7 Horner8 Horner9 Horner10 Estrin Factorization Bruteforce
do 
    L=$(iaca -64 -analysis LATENCY ./bwfma/poly/poly_POLY_${i} | grep Latency | grep Cycles | cut -d ' ' -f 2)
    TH=$(iaca -64 -analysis THROUGHPUT ./bwfma/poly/poly_POLY_${i} | grep Throughput | grep Cycles | cut -d ' ' -f 3)
    echo ${i} $L $TH
done
