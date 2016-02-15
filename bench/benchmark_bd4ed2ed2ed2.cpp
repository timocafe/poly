//
// benchmark_bd4ed2ed2ed2_test.cpp
//
// Created by Ewart Timothée, 15/2/2016
// Copyright (c) Ewart Timothée. All rights reserved.
//
// This file is generated automatically, do not edit!
// TAG: benchmark_bd4ed2ed2ed2
// Helper:
//     h = Horner, e = Estrin, b = BruteForce
//     The number indicates the order for Horner
//     e.g. h1h3 indicates a produce of polynomial with Horner order 1 and 3
//

#include <iostream>
#include <random>
#include <cmath>
#include <chrono>
#include <algorithm>
#include <ctime>
#include <cstring>
#include <limits>
#include <iomanip>
#include <functional>

#include "poly/poly.h"

    inline double sse_floor(double a) {
        double b;
        asm ("roundsd $1,%1,%0 " :"=x"(b) :"x"(a));
        return b;
    }
   static inline uint64_t as_uint64(double x) {
       uint64_t i;
       memcpy(&i,&x,8);
       return i;
    }
    static inline double as_double(uint64_t i) {
        double x;
        memcpy(&x,&i,8);
        return x;
    }
    double poly_exp(double x){
        uint64_t mask1 = (fabs(x) > 700);
        mask1 = (mask1-1);
        uint64_t mask2 = (x < 700);
        mask2 = ~(mask2-1);
        uint64_t mask3 = as_uint64(std::numeric_limits<double>::infinity());
        const long long int tmp((long long int)sse_floor(1.4426950408889634 * x));
        const long long int twok = (1023 + tmp) << 52;
        x -= ((double)(tmp))*0.6931471805599453;
        double y = poly::bruteforce<poly::coeffP4_1>(x)*poly::estrin<poly::coeffP2_3>(x)*poly::estrin<poly::coeffP2_4>(x)*poly::estrin<poly::coeffP2_5>(x)* (*(double *)(&twok));
        uint64_t n = as_uint64(y);
        n &= mask1;
        mask3 &= ~mask2;
        n |= mask3;
        return as_double(n);
    }

int main(int argc, char* argv[]){
        size_t size = atoi(argv[1]);
        double freq = atof(argv[2]);
        std::vector<double> buffer(size);
        std::vector<double> res(size);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(-700,700);
        auto rand = std::bind(dis, gen);
        std::generate(buffer.begin(), buffer.end(), rand);
        double * __restrict p_0 = &res[0];
        double * __restrict p_1 = &buffer[0];
        int n = buffer.size();
        std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
        start = std::chrono::high_resolution_clock::now();
        for(auto i=0; i < n; ++i)
            p_0[i] = poly_exp(p_1[i]);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double,std::nano> elapsed_seconds_poly_exp = end-start;
        std::cout << " benchmark_bd4ed2ed2ed2, TROUGHPUT: " <<  freq*elapsed_seconds_poly_exp.count()/n << std::endl;
}
