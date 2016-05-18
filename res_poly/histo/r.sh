#!/bin/bash

cd sb
gnuplot hw_l_frequency
gnuplot hw_t_frequency
cd ../hw
gnuplot hw_l_frequency
gnuplot hw_t_frequency
cd ../precision
gnuplot precision_scalar
gnuplot precision_vector
cd ../../figures
open hw_histo_vector_t_hw.eps hw_histo_vector_l_hw.eps hw_histo_vector_t_sb.eps hw_histo_vector_l_sb.eps all_precision_scalar.eps all_precision_vector.eps
