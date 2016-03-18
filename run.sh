#!/bin/bash

function ulp {
for i in $1/bench/ulp/$2/$3_ulp_*
do
   RES=$(./${i})
   echo ${i} ${RES} 
done
}

function throughput {
for i in $1/bench/throughput/$2/$3_throughput_*
do
   RES=$(./${i})
   echo ${i} ${RES}
done
}

function latency {
for i in $1/bench/latency/scalar_vector_latency_*
do
   RES=$(./${i} ${2})
   echo ${i} ${RES}
done
}

ulp "${1}" "${2}" "${2}_scalar"
ulp "${1}" "${2}" "${2}_vector"
throughput "${1}" "${2}" "${2}_scalar"
throughput "${1}" "${2}" "${2}_vector"
latency "${1}" "${2}"
latency "${1}" "${2}"
