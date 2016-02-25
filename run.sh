#!/bin/bash

function ulp {
for i in $1/bench/ulp/$2_ulp_*
do
   RES=$(./${i})
   echo ${i} ${RES} 
done
}

function throughput {
for i in $1/bench/throughput/$2_throughput_*
do
   RES=$(./${i} 10000)
   echo ${i} ${RES}
done
}

ulp "${1}" "scalar"
ulp "${1}" "vector"
throughput "${1}" "scalar"
throughput "${1}" "vector"
