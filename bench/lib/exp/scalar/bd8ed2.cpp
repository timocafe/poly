//
// bd8ed2_test.cpp
//
// Created by Ewart Timothée, 2/3/2016
// Copyright (c) Ewart Timothée. All rights reserved.
//
// This file is generated automatically, do not edit!
// TAG: bd8ed2
// Helper:
//     h = Horner, e = Estrin, b = BruteForce
//     The number indicates the order for Horner
//     e.g. h1h3 indicates a produce of polynomial with Horner order 1 and 3
//
#include <limits>
#include <string.h>
#include <cmath>
#include <iostream>
#include "poly/poly.h"

namespace poly {
    inline double sse_floor(double a) {
        double b;
        #ifdef __x86_64__
        asm ("roundsd $1,%1,%0 " :"=x"(b) :"x"(a));
        #endif
        #ifdef __PPC64__
        asm ("frim %0,%1 " :"=d"(b) :"d"(a));
        #endif
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

    double exp(double x){
        uint64_t mask1 = (fabs(x) > 700);
        mask1 = (mask1-1);
        uint64_t mask2 = (x < 700);
        mask2 = ~(mask2-1);
        uint64_t mask3 = as_uint64(std::numeric_limits<double>::infinity());
        const long long int tmp((long long int)sse_floor(1.4426950408889634 * x));
        const long long int twok = (1023 + tmp) << 52;
        x -= ((double)(tmp))*6.93145751953125E-1;
        x -= ((double)(tmp))*1.42860682030941723212E-6;
        double y = poly::bruteforce<poly::coeffP8>(x)*poly::estrin<poly::coeffP2_5>(x)* (*(double *)(&twok));
        uint64_t n = as_uint64(y);
        n &= mask1;
        mask3 &= ~mask2;
        n |= mask3;
        return as_double(n);
    }
} //end namespace 

